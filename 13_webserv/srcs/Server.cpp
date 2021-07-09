#include "Server.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Server::Server(ServerConf* serverconfig)
{
    __server_config = serverconfig;
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
/* ************************************************************************** */
