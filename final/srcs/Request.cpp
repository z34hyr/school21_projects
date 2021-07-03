#include "Request.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Request::Request(): status(0)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Request::~Request()
{
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Request::parseHeader(int end_request_index)
{
    __header =  __raw_request.substr(0, end_request_index);
	std::vector<std::string> lines = split(__header, "\r\n");
	if (lines.size() < 2) {
		status = BAD_REQUEST;
		return;
	}
	status = parseRequestLine(lines[0]);
	if (status == 0) {
		parseRequestHeaders(lines);
		if (__mapped_headers["Host"].empty())
			status = BAD_REQUEST;
	}
	std::string body_part = __raw_request.substr(__header.length() + 4);
    if (isChunked()) {
        body_part = unchunk(body_part);
    }
    __body = body_part;
}

void Request::addToRequest(std::string additional)
{
	__raw_request += additional;
    if (!__header.empty()) {
		if (isChunked())
	    	additional += unchunk(additional);
		__body += additional;
    }
}

std::string Request::getRequest()
{
	return __raw_request;
}

std::string Request::getHeader()
{
    return __header;
}

std::string Request::getMethod()
{
    return __method;
}
size_t Request::getSize()
{
    if (!__header.empty())
        return __header.length() + 4 + __body.length();
    return __raw_request.length();
}

std::string Request::getUri()
{
	return __uri;
}

std::string Request::unchunk(std::string body_part)
{
    std::string unchunked_part;
    if (!__chunk_buffer.empty())
        body_part = __chunk_buffer + body_part;
    std::vector<std::string> lines = split(body_part, "\r\n");
	size_t num = 0;
	size_t data = 1;
	char *p_end;
	while (lines.size() > data)
	{
		//size_t data_size = std::stol(lines[num], 0 , 16);
		size_t data_size = std::strtol(lines[num].c_str(), &p_end, 16);
		if (data_size > lines[data].length()) {
			__chunk_buffer = body_part.substr((body_part.find(lines[num])));
			break;
		} else if (data_size < lines[data].length()) {
			status = BAD_REQUEST;
			break;
		}
		unchunked_part += lines[data];
		data += 2;
		num += 2;
	}

	return unchunked_part;
}

int     Request::getContentLength()
{
	return atoi(__mapped_headers["Content-Length"].c_str());
}

std::string      Request::getConnection()
{
	return __mapped_headers["Connection"];
}

bool      Request::isCloseConnection()
{
	return getConnection() == "close";
}

std::string     Request::getHost()
{
	return __mapped_headers["Host"];
}

int Request::parseRequestLine(std::string requset_line)
{
	std::vector<std::string> words = splitByDelimeter(requset_line, " ");
	if (words.size() != 3)
		return BAD_REQUEST;
	__method = words[0];

	__uri = words[1];
	if (__uri[0] != '/')
		return BAD_REQUEST;
	__version = words[2];
	return checkPorotocol();
}

int Request::checkPorotocol()
{
	size_t index = __version.find("HTTP/");
	if (index == std::string::npos)
		return BAD_REQUEST;

	float ver = atof(__version.substr(5).c_str());
	if (ver < 1.0 && ver >= 2.0)
		return NOT_SUPPORTED_VERSION_HTTP;

	return 0;
}
void Request::parseRequestHeaders(std::vector<std::string> headers)
{
	std::vector<std::string>::iterator first = headers.begin();
	std::vector<std::string>::iterator last = headers.end();
	for(++first; first != last; first++) {
		size_t pos = first->find(":", 0);
		if (pos == std::string::npos)
			continue;
		__mapped_headers[first->substr(0, pos)] = first->substr(pos + 2);
	}
	if (__mapped_headers["Cookie"].size())
	{
		std::cout << "Find some cookie\n";
		std::cout << __mapped_headers["Cookie"] << "\n";
	}
}

void Request::printRequest()
{
	std::cout << __header << std::endl;
	std::cout << __body << std::endl;
	// std::cout << __method << " " << __uri << " " << __version << std::endl;
	// std::map<std::string,std::string>::iterator start = __mapped_headers.begin();
	// std::map<std::string,std::string>::iterator end = __mapped_headers.end();
	// while (start != end) {
	// 	std::cout << start->first << ": " << start->second << std::endl;
	// 	start++;
	// }
	// std::cout << start->first << ": " << start->second << std::endl;

}
bool	Request::isChunked()
{
	return !__mapped_headers["Transfer-Encoding"].empty()
		&& __mapped_headers["Transfer-Encoding"].find("chunked") != std::string::npos;
}
std::string Request::getBody()
{
	return __body;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
