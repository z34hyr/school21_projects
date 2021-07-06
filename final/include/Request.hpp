#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <vector>
#include "webserv.hpp"
class Location;

class Request
{
public:
        Request();
        ~Request();
        Location *config;
        void parseHeader(int end_request_index);
        void addToRequest(std::string additional);
        std::string getRequest();
        std::string getUri();
        int             status;
        void printRequest();
        int             getContentLength();
        std::string      getConnection();
        std::string getHeader();
        size_t getSize();
        std::string unchunk(std::string body_part);
	bool	isChunked();
        std::string getBody();
        std::string     getHost();
        std::string getMethod();
        bool    isCloseConnection();
        void    initCookie();
        void    parseCookie(std::string raw_cookie);
        std::map<std::string, std::string>      getMappedHeadrs();
        std::map<std::string, std::string>      getReqCookie();
        std::map<std::string,std::string>       __mapped_headers;

private:
        Request( Request const & src );
        Request &		operator=( Request const & rhs );
        std::string     __raw_request;
        std::string     __method;
        std::string     __uri;
        std::string     __version;
        std::string     __body;
        std::string     __header;
        std::string     __chunk_buffer;

        
        std::map<std::string, std::string> __cookie;

        void setMethod(const char *method);
        int     parseRequestLine(std::string requset_line);
        int     checkPorotocol();
        void parseRequestHeaders(std::vector<std::string> headers);
};

#endif /* ********************************************************* REQUEST_H */
