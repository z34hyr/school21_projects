#include "Client.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Client::Client()
{}

Client::Client(Server *serv, int fd, struct sockaddr_in addr_info)
{
    __serv = serv;
    __fd = fd;
    __addr_info = addr_info;
    __req = NULL;
    __res = NULL;
    time_last_action = time(0);
    __session_visits = 0;
    __client_cookies = serv->getCookies();
    if (__client_cookies["total_counter"].size() == 0)
        std::cout << "I see no total counter\n";
    else
        std::cout << "Total Counter = " << __client_cookies["total_counter"] << "\n";
    std::cout << "Total count from serv: " << __serv->getTotalCounter() << "\n";
    if (__serv->getCookies().size())
        std::cout << "      Server Total Ccounter: " << __serv->getCookies()["total_counter"] << "\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Client::~Client()
{
    if (__req)
        delete __req;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
	int Client::getFd()
    {
        return __fd;
    }

    void Client::fixTime()
    {
        __serv->fixTime();
        time_last_action = time(0);
    }

    Request *Client::getRequest()
    {
        return __req;
    }

    Server *Client::getServer()
    {
        return __serv;
    }

    time_t Client::getTimeLastAction()
    {
        return time_last_action;
    }

    int Client::getStatus()
    {
        return __status;
    }

    int Client::readRequest()
    {
        int num_bytes;
        char buf[MAX_HEADER_SIZE];
        std::string raw_request;
        bzero(buf, MAX_HEADER_SIZE);
        fixTime();
        try
        {
            num_bytes = recv(__fd, buf, MAX_HEADER_SIZE - 1, 0);
            if (num_bytes < 0) {
                close(__fd);
                return (BAD_READ);
            }
            std::cout << "RAW REQUEST:\n" << buf << "\n";
            if (std::strstr(buf, "GET /close"))
            {
                must_exit = true;
                std::cout << "MUST EXIT : " << must_exit << "\n";
            }
            if (num_bytes == 0) {
                close(__fd);
                std::cout << "CLOSE CONNECTION\n";
                return (CLOSE_CONNECTION);
            }
            raw_request.insert(0, buf, num_bytes);

            if (!__req)
                __req = new Request();
            __req->addToRequest(raw_request);
            return checkRequest();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return(BAD_READ);
        }
    }

    int Client::checkRequest()
    {
        if (__req->status) {
            __status = CLIENT_TO_WRITE;
            return(END_READ);
        }
        // поиск конца хедера
        size_t end_request_index = __req->getRequest().find("\r\n\r\n");
        if (end_request_index == std::string::npos) {
            if (__req->getSize() < MAX_HEADER_SIZE)
                return(CONTINUE_READ);
            __req->status = REQUEST_ENTITY_TOO_LARGE;
            __req->config = __serv->getConfigByUrl(__req->getHost(), "/");
            __status = CLIENT_TO_WRITE;
            return(END_READ);
        }
        //первый парсинг если нужен
        if (__req->getUri().empty()) {
            __req->parseHeader(end_request_index);
            copyCookie(__req->getReqCookie());
            __req->config = __serv->getConfigByUrl(__req->getHost(), __req->getUri());
        }
        if (__req->isChunked()) {
            if (__req->getRequest().find("0\r\n\r\n") != std::string::npos) {
                __status = CLIENT_TO_WRITE;
                return (END_READ);
            }
        }
        else if (__req->getSize() == __req->getContentLength() + 4 + __req->getHeader().length())
        {
            __status = CLIENT_TO_WRITE;
            return (END_READ);
        }
        return __req->status ? END_READ : CONTINUE_READ;
    }

	Response* Client::getResponse() { return __res; }

    int Client::sendResponse()
    {
        fixTime();
        try
        {
            __status = CLIENT_TO_WRITE;
            if (!__res) {
                __res = new Response(this, __req);
               // __res->
                //["total_counter"] = __serv->getCookies()["total_counter"];
                __res->prepareBody();
				__serv->changeSessionIds(__res->getSessionID(), 1);
            }
            if (__res->execute() == false)
                return (CONTINUE_WRITE);
            std::string response_chunk = __res->getText().substr(__res->sended_bytes);
            size_t ret = send(__fd, response_chunk.c_str(), response_chunk.length(), 0);
            if (ret < 0) {
                std::cout << "проблемы с отсылкой данных клиенту\n";
                return (BAD_WRITE);
            }
            __serv->addTotalCounter();
            __serv->saveCookie();
            __res->sended_bytes += ret;
            if (__res->getText().length() != __res->sended_bytes || ret == 0)
                return (CONTINUE_WRITE);
            bool is_close = __req->getConnection() == "close" || __res->getText().find("Connection: close") != std::string::npos;
            __status = CLIENT_TO_READ;
            delete __res;
            delete __req;
            __res = NULL;
            __req = NULL;
            return (is_close ? CLOSE_CONNECTION : END_WRITE);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return (BAD_WRITE);
        }
    }

    //    std::map<std::string, std::string>    getReqCookie();
    std::map<std::string, std::string> Client::getReqCookie()
    {
        return __client_cookies;
    }

    void    Client::copyCookie(std::map<std::string, std::string> server_cookie)
    {
        __client_cookies = server_cookie;
    }

	void    Client::setSessionID(std::string id)
	{
		__session_ID = id;
	}
    void    Client::addSessionCounter() { __session_visits += 1; }
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
	std::string Client::getSessionID() { return __session_ID; }
    unsigned long Client::getSessionCounter() { return __session_visits; }
    

/* ************************************************************************** */
