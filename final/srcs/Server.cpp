#include "Server.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Server::Server(ServerConf* serverconfig)
{
    __server_config = serverconfig;
    __session_enabled = serverconfig->getSessionEnable();
	__total_counter = 0;
}

Server::Server( const Server & src ): __socket_fd(src.__socket_fd), __server_config(src.__server_config)
{
	__total_counter = 0;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Server::~Server()
{
    if (__server_config)
    {
        __server_config->clearLocations();
        delete __server_config;
    }
}

/*
** --------------------------------- METHODS ----------------------------------
*/
Client *Server::acceptClient()
{
    Client *client = NULL;
    try
    {
        int fd;
        socklen_t len = (socklen_t)sizeof(__addr);
        if ((fd = accept(__socket_fd, (struct sockaddr *) &__addr, &len)) < 0)
            throw std::exception();
        client = new Client(this, fd, __addr);
        client->fixTime();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return client;
}

Location *Server::getConfigByUrl(std::string host, std::string uri)
{
    return returnResponse(__server_config, host, uri);
}

time_t Server::getTimeLastAction()
{
    return time_last_action;
}

void Server::fixTime()
{
    time_last_action = time(0);
}

int Server::createSocket(int port, std::string ip) {
    int sockfd;
    struct sockaddr_in addr;
    // char * hostAddr;
    bool yes = true;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    inet_pton(AF_INET, ip.c_str(), &(addr.sin_addr));
    addr.sin_port = htons((short)port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket!\n");
        exit(1);
    }

    printf("Socket created (port %d)...\n", port);

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    fcntl(sockfd, F_SETFL, O_NONBLOCK);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("Error binding socket to port!\n");
        exit(1);
    }
    printf("Binding done...\n");
    __socket_fd = sockfd;
    __addr = addr;
    return sockfd;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
ServerConf*	Server::getServerConf()
{
    return __server_config;
}
void	Server::pullCookie()
{
    //search and fill files with cookie in folder 'cookie'.
    //search all server names through locations for this server
    std::vector<Location*> loc_temp = __server_config->getLocations();
    std::string username;
    std::pair<std::string, std::string> serv_user;
    std::cout << "Handle saved cookie files...\n";
	std::ostringstream s1;
	s1 << __server_config->getPort();
	std::string file_name = __server_config->getIP() + ":" + s1.str();
	std::ifstream inFile;
	std::string temp_path = "./cookie/" + file_name;
	std::cout << "Searching for " << temp_path << "\n";
	inFile.open(temp_path.c_str());
	if (inFile.is_open())
	{
		for (std::string curr; std::getline(inFile, curr); )
		{
			std::vector<std::string> temp_split = splitByDelimeter(curr, "=");
			if (temp_split.size() == 2)
			{
				__server_cookie[temp_split[0]] = temp_split[1];
				if (temp_split[0] == "total_counter")
					__total_counter = std::atol(temp_split[1].c_str());
			}
		}
	}
	inFile.close();
	if (__server_cookie["total_counter"].size())
		std::cout << "	Server total counter: " << __server_cookie["total_counter"] << "\n";
    std::cout << "Cookies found: " << __server_cookie.size() << std::endl;
}

void	Server::saveCookie()
{
	std::ofstream outFile;
	std::ostringstream s1;
	s1 << __server_config->getPort();
	std::string file_name = "./cookie/" + __server_config->getIP() + ":" + s1.str();
	outFile.open(file_name.c_str(), std::fstream::out);
	if (outFile.is_open())
	{
		for (std::map<std::string, std::string>::iterator i_b = __server_cookie.begin(); i_b != __server_cookie.end(); i_b++)
		{
			std::string zz = i_b->first + "=" + i_b->second;
			outFile << zz;
		}
	}
	outFile.close();
}
std::map<std::string, std::string> Server::getCookies()
{
	return __server_cookie;
}
unsigned long		Server::getTotalCounter()
{
	return __total_counter;
}
void	Server::addTotalCounter()
{
	std::ostringstream s1;
	__total_counter += 1;
	s1 << __total_counter;
	__server_cookie["total_counter"] = s1.str();
}

void	Server::changeSessionIds(std::string session_id, int action)
{
	std::vector<std::string>::iterator res = std::find(__sessions_ids.begin(), __sessions_ids.end(), session_id);
    if (action && res == __sessions_ids.end())
        __sessions_ids.push_back(session_id);
    else if (!action && res != __sessions_ids.end())
        __sessions_ids.erase(res);
}
bool	Server::checkSessionId(std::string session_id)
{
    if (std::find(__sessions_ids.begin(), __sessions_ids.end(), session_id) != __sessions_ids.end())
        return true;
    else
        return false;
}

std::vector<std::string>	Server::getSessions()
{
    return __sessions_ids;
}

int		Server::getSessionEnabled() { return __session_enabled; };
/* ************************************************************************** */
