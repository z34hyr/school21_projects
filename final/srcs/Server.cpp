#include "Server.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Server::Server(ServerConf* serverconfig)
{
    __server_config = serverconfig;
}

Server::Server( const Server & src ): __socket_fd(src.__socket_fd), __server_config(src.__server_config)
{}


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
//std::map<std::pair<std::string, std::string>, std::map<std::string, std::string>> server_cookie;
void	Server::pullCookie()
{
    //search and fill files with cookie in folder 'cookie'.
    //search all server names through locations for this server
    std::vector<Location*> loc_temp = __server_config->getLocations();
    std::vector<std::string> temp;
    std::string username;
    std::pair<std::string, std::string> serv_user;
    std::cout << "Handle saved cookie files...\n";
    for (unsigned long j = 0; j < loc_temp.size(); j++)
    {
        std::vector<std::string> temp = loc_temp[j]->getServerNames();
        if (temp.size() == 0)
        {
            std::ostringstream ss;
            ss << __server_config->getPort();
            temp.push_back(__server_config->getIP() + ":" + ss.str());
        }
        for (unsigned long i = 0; i < temp.size(); i++)
        {
            std::ifstream inFile;
            std::string temp_path = "./cookie/" + temp[i];
            std::cout << "Searching for " << temp_path << "\n";
            inFile.open(temp_path.c_str());
            if (inFile.is_open())
            {
                for (std::string curr; std::getline(inFile, curr); )
                {
                    std::vector<std::string> temp_split = splitByDelimeter(curr, " ");
                    if (temp_split.size() == 1)
                    {
                        username = temp_split[0];
                        serv_user.first = temp[i];
                        serv_user.second = username;
                    }
                    else if (temp_split.size() == 2)
                    {
                        __server_cookie[serv_user][temp_split[0]] = temp_split[1];
                    }
                }
            }
            inFile.close();
        }
    }
    std::cout << "Users found: " << __server_cookie.size() << std::endl;
}
/*

*/
/* ************************************************************************** */
