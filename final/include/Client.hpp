#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "webserv.hpp"

class Response;
class Request;
class Server;

class Client
{

public:
    Client(Server *serv, int fd, struct sockaddr_in addr_info);
    ~Client();


private:
    Client();
    Client &		operator=( Client const & rhs );
    Client( Client const & src );
    int __status;
    int __fd;
    Request *__req;
    Response *__res;
    Server *__serv;
    time_t time_last_action;
    struct sockaddr_in __addr_info;
    std::map<std::string, int> cookies;

public:
    void fixTime();
    int checkRequest();
    Server *getServer();
    time_t getTimeLastAction();
    int		getFd();
    Request	*getRequest();
	int		getStatus();
    int		readRequest();
    int		sendResponse();
    size_t  getContentLength(std::string headers);
};

std::ostream &			operator<<( std::ostream & o, Client const & i );

#endif /* ********************************************************** CLIENT_H */
