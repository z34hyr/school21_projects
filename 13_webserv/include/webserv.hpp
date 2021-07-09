#ifndef WEBSERV_HPP
# define WEBSERV_HPP

# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <vector>
# include <iostream>
# include <string>
# include <map>
# include <stack>
# include <fstream>
# include <sys/time.h>
# include <time.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <cstring>
# include "stdlib.h"
# include "sys/types.h"
# include "netinet/in.h"
# include "dirent.h"
# include "netdb.h"
# include <poll.h>
# include "Client.hpp"
# include "Server.hpp"
# include "Response.hpp"
# include "Request.hpp"
# include "../config_parser/ServerConf.hpp"
# include "../config_parser/toReturn.hpp"
# include "../config_parser/parse_config.hpp"
# include <sys/select.h>

# include <fstream>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <stdlib.h>
# include <ctime>
# include <fstream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

# define CLIENT_TIMEOUT 60000
# define SERVER_TIMEOUT 360000
# define BAD_READ -1

# define END_READ 0
# define BAD_READ -1
# define CONTINUE_READ 1
# define CLOSE_CONNECTION 2

# define NOT_EXIST -1
# define DIRECTORY 0
# define FILE 1

# define END_WRITE 0
# define BAD_WRITE -1
# define CONTINUE_WRITE 1

# define CLIENT_TO_READ 1
# define CLIENT_TO_WRITE 2
# define CLIENT_TO_CLOSE 3
# define CGI_EXECUTE 4

# define REQUEST_ENTITY_TOO_LARGE 413
# define NOT_SUPPORTED_VERSION_HTTP 505
# define MAX_HEADER_SIZE 8192
# define MOVED_PERMANENTLY 301
# define MOVED_TEMPORARY 302
# define TEMPORAY_REDIRECT 307
# define BAD_REQUEST 400
# define AUTH_NEEDED 401
# define FORBIDDEN 403
# define NO_CONTENT 204
# define CREATED 201
# define NOT_FOUND 404
# define METHOD_NOT_ALLOWED 405
# define LENGTH_REQUIRED 404
# define TOO_MANY_REQUEST 429
# define INTERNAL_SERVER_ERROR 500
# define NOT_IMPLEMENTED 501
# define HTTP_VERSION_NOT_SUPPORTED 505

extern bool must_exit;

class Client;
int createSocket(int port, std::string ip);
void add_client_fds_with_request(std::map<int, Client *> clients, fd_set *fds, int *max_fd);
std::vector<std::string> splitByDelimeter(std::string buffer, const char *delimeters);
std::vector<std::string> split(const std::string& str, const std::string& delim);
std::string getDate();
int checkExistAndType(const char* filePath);
bool canBeOpened(std::string file_name);


bool	delete_file(std::string const &name);
bool	create_new_file(std::string const &name, std::string const &info);
std::vector<ServerConf*>	getConfigs(int argc, char **argv);
// trim from end of string (right)
std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v");
// trim from beginning of string (left)
std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v");

// trim from both ends of string (right then left)
std::string& trim(std::string& s, const char* t = " \t\n\r\f\v");
std::string    createSession();
template<class val>
bool in_vector(std::vector<val> stack, val needle)
{
    return find(stack.begin(), stack.end(), needle)
		!= stack.end();
}

template<class val>
void debug(val value, std::string description = "")
{
	std::cerr << BOLDYELLOW << description << value << RESET << std::endl;
}
#endif
