#include "webserv.hpp"

void add_client_fds_with_request(std::map<int, Client *> clients, fd_set *fds, int *max_fd)
{
    int fd;

    std::map<int, Client *>::iterator first = clients.begin();
    std::map<int, Client *>::iterator last = clients.end();
    for(; first != last; first++) {
        Client *cl = first->second;
        if (cl->getStatus() == CLIENT_TO_WRITE) {
            fd = first->first;
            FD_SET(fd, fds);
            if (fd > *max_fd)
                *max_fd = fd;
        }
    }
}

std::vector<std::string> splitByDelimeter(std::string buffer, const char *delimeters)
{
    std::vector<std::string> lines;

    char char_req[buffer.length()];
    char *ptr;
    strcpy(char_req, buffer.c_str());
    ptr = strtok(char_req, delimeters);
    lines.push_back(std::string(ptr));
    while((ptr = strtok(0, delimeters)))
        lines.push_back(std::string(ptr));
    free(ptr);
    return lines;
}

std::string getDate()
{
	std::time_t t = std::time(NULL);
	char buf[30];
	strftime(buf, sizeof(buf), "%a, %d %b %Y %T %Z", std::localtime(&t));
	return std::string(buf);
}

int checkExistAndType(const char* filePath)
{
	struct stat fileAtt;

	if (stat(filePath, &fileAtt) != 0)
		return -1;
	if (S_ISREG(fileAtt.st_mode))
		return 1;
	if (S_ISDIR(fileAtt.st_mode))
		return 0;
	return -1;
}


bool canBeOpened(std::string file_name)
{
    std::ifstream checked_file;
	checked_file.open(file_name.c_str());
	if (checked_file.fail() || !checked_file.is_open())
        return false;
    checked_file.close(); 
    return true;
}

std::vector<std::string> split(const std::string& s, const std::string& delim)
{
    size_t pos_start = 0, pos_end, delim_len = delim.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delim, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
std::string& rtrim(std::string& s, const char* t)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
std::string& ltrim(std::string& s, const char* t)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
std::string& trim(std::string& s, const char* t)
{
    return ltrim(rtrim(s, t), t);
}
