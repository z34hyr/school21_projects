#include "Response.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Response::Response(): sended_bytes(0)
{}

Response::Response(Client *client, Request *req)
{
	response_messages[200] = "OK";
	response_messages[201] = "Created";
	response_messages[204] = "No Content";
	response_messages[301] = "Moved Permanently";
	response_messages[302] = "Moved Temporary";
	response_messages[307] = "Temporary Redirect";
	response_messages[400] = "Bad Request";
	response_messages[401] = "Unauthorized";
	response_messages[403] = "Forbidden";
	response_messages[404] = "Not Found";
	response_messages[405] = "Method Not Allowed";
	response_messages[411] = "Length Required";
	response_messages[429] = "Too Many Requests";
	response_messages[500] = "Internal Server Error";
	response_messages[501] = "Not Implemented";
	response_messages[505] = "HTTP Version Not Supported";

	mime_types["html"] = "text/html";
	mime_types["txt"] = "text/plain";
	mime_types["ico"] = "image/vnd.microsoft.icon";
	mime_types["jpeg"] = "image/jpeg";
	mime_types["jpg"] = "image/jpeg";
	mime_types["png"] = "image/png";
	mime_types["pdf"] = "application/pdf";

	__client = client;
	__server_name = "ft_webserv";
	__req = req;
	sended_bytes = 0;
	__protocol = "HTTP/1.1";
	__status = 0;
	is_execute_cgi = false;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Response::~Response()
{}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string	Response::setRedirUri()
{
	std::string old_uri = __req->getUri();
	std::string new_uri = old_uri.replace(0, __config->getRequest().length(), __config->getRedir().second);
	return new_uri;
}

std::string Response::getHead()
{
	std::ostringstream s1, s2;
	if (!__status)
		__status = 200;
	s1 << __status;
	//s1 << 401;
	s2 << body.length();
	std::string first_string = __protocol + " " + s1.str() /* std::to_string(__status) */ + " " + response_messages[__status] + "\r\n";
	//std::string first_string = __protocol + " " + s1.str() + " " + "Unauthorized\r\n";
	first_string += "Date: " + getDate() + "\r\n";
	first_string += "Server: " + __server_name + "\r\n";
	//first_string += "WWW-Authenticate: Basic realm=\"Access to staging site\"";
	first_string += "Content-length: " + s2.str() /* std::to_string(body.length()) */ + "\r\n";
	if (__file_type.size())
		first_string += "Content-Type: " + __file_type + "\r\n";
	if (__status == CREATED)
		first_string += "Location: " + __req->getUri() + "\r\n";
	if (__status == MOVED_PERMANENTLY || __status == MOVED_TEMPORARY || __status == TEMPORAY_REDIRECT)
		first_string += "Location: " + setRedirUri() + "\r\n";
	first_string += "Set-Cookie: first_visit=a; HttpOnly\r\n";
	first_string += additional_header;
	first_string += getConnectionHeader();
	return first_string;
}

std::string Response::getConnectionHeader()
{
	std::string connection = "keep-alive";
	if (__req->isCloseConnection() || __status == 400)
		connection = "close";
	return "Connection: " + connection;
}

std::string Response::getBody()
{
	return body;
}

std::string	Response::getFileType()
{
	return __file_type;
}

std::string	Response::findKnownType(std::string type)
{
	if (mime_types[type].size())
		return mime_types[type];
	if (type[type.size() - 1] != '/')
		return "application/octet-stream";
	return "";
}

void	Response::setFileType(std::string file_path)
{
	if (file_path.empty())
		return ;
	std::vector<std::string> splitted_file_path = splitByDelimeter(file_path, ".");
	if (splitted_file_path.size() >= 2)
		__file_type = findKnownType(splitted_file_path[splitted_file_path.size() - 1]);
}

void	Response::prepareBody()
{
	__config = __req->config;
	std::pair<std::string, std::string> redir = __config->getRedir();
	if (__req->status) {
		__status = __req->status;
		body = getErrorBody();

	} else if (redir.first.size()) {
		__status = std::atoi(redir.first.c_str());
		body = getRedirBody(redir.first);
		return ;
	} else {
		__status = checkConfig();
		//std::cout << __config->getCGIPath() << " - CGI path\n";
		file_path = getFullPath(__config->getAutoindex());
		int code = checkExistAndType(file_path.c_str());
		// debug(__req->getMethod() == "DELETE" && code == FILE);
		if (__status) {
			body = getErrorBody();
		} else if (__config->getAutoindex() && code == DIRECTORY) {
			body = getAutoindexPage();
		} else if (__config->getSaveFile() && (__status = fileExecute(code))) {
			if (__status > 399)
				body = getErrorBody();
		} else if (code == NOT_EXIST) {
			__status = NOT_FOUND;
			body = getErrorBody();
		} else if (!__config->getCGIPath().empty()) {
			executeCgi();
		} else if (__req->getMethod() == "DELETE" && code == FILE) {
			__status = FORBIDDEN;
			body = getErrorBody();
		} else {
			body = getFromFilePath();
		}
	}
	std::cout << "File type: " << __file_type << std::endl;
}

bool	Response::execute()
{
	std::string head = getHead();
	__text = head + "\r\n\r\n" + body;
	return true;
}

std::string Response::getFromFilePath()
{
	std::string tmp_body = readFromFile(file_path);
	if (tmp_body.empty() && __status) {
		return getErrorBody();
	}
	setFileType(file_path);
	return tmp_body;
}

int Response::fileExecute(int code)
{
	if (__req->getMethod() == "DELETE" && code == FILE) {
			if (delete_file(file_path))
				return NO_CONTENT;
			return FORBIDDEN;
	} else if (__req->getMethod() == "POST" && code == NOT_EXIST) {
		if (create_new_file(file_path, __req->getBody())) {
			return CREATED;
		} else {
			return FORBIDDEN;
		}
	}
	return 0;
}

std::string Response::getErrorBody()
{
	file_path = __config->getErrorPaths()[__status];
	setFileType(file_path);
	return readFromFile(file_path);
}

std::string Response::getText()
{
	return __text;
}

int Response::checkConfig()
{
	if (!in_vector(__config->allowed_requests, __req->getMethod())) {
		return METHOD_NOT_ALLOWED;
	}
	if (__req->config->getUserBodySize() < __req->getContentLength() || __req->getBody().length() > (size_t)__config->getUserBodySize()) {
		return REQUEST_ENTITY_TOO_LARGE;
	}

	return 0;
}

std::string Response::getFullPath(bool autoindex = false)
{
	std::string path = __config->getRoot() + __req->getUri();
	std::cout << "	PATH: " << path << std::endl;
	int code = checkExistAndType(path.c_str());
	if (code == DIRECTORY && !autoindex)
		path += __config->getDefaultPage();
	return path;
}

bool Response::isDir(std::string path)
{
	return path[path.size() - 1] == '/';
}

std::string Response::readFromFile(std::string path)
{
	std::ifstream file(path.c_str());
	if (file.fail()) {
		__status = 403;
		return "";
	}
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	return content;
}


bool	Response::create_new_file(std::string const &name, std::string const &info)
{
	std::ofstream new_file(name.c_str());
	if (!new_file.is_open() || new_file.fail())
		return false;
	new_file << info;
	new_file.close();
	return true;
}

void Response::executeCgi()
{
	int pipe_fd[2];
	pid_t		pid;
	std::string tmp_file = "tmp_web_cgi";
	int			stat;
	char		**env = {NULL};
	int			fd_new_file;
	std::string	info;

	if (pipe(pipe_fd) < 0)
		return internalServerError();
	write(pipe_fd[1], __req->getBody().c_str(), strlen(__req->getBody().c_str()));
	fd_new_file = open(tmp_file.c_str(), O_RDWR | O_CREAT, S_IWRITE | S_IREAD);
	if (fd_new_file < 0){
		return internalServerError();
	}
	close(pipe_fd[1]);
	if ((pid = fork()) < 0) {
		delete_file(tmp_file);
		return internalServerError();
	}
	if (pid == 0)
	{
		char *arg[3];
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		dup2(fd_new_file, STDOUT_FILENO);
		arg[0] = strdup(__config->getCGIPath().c_str());
		arg[1] = strdup(file_path.c_str());
		arg[2] = NULL;
		execve(arg[0], arg, env);
		close(fd_new_file);
		exit(42);
	}
	else
	{
		waitpid(pid, &stat, 0);
		if (WEXITSTATUS(stat) != 0) {
			delete_file(tmp_file);
			std::cout << "EXITSTATUS != 0\n";
			return internalServerError();
		}
		close(fd_new_file);
		info = readFromFile(tmp_file);
		if (__status) {
			body = getErrorBody();
			return ;
		}
		size_t pos;
		//std::cout << "========\n" << info << "\n=========\n";
		if ((pos = info.find("\n\n")) == std::string::npos) {
			delete_file(tmp_file);
		//	std::cout << "NO NN FOUND\n";
			return internalServerError();
		}
		additional_header = info.substr(0, pos) + "\r\n";
		body = info.substr(pos + 2);
		delete_file(tmp_file);
	}
}

bool	Response::delete_file(std::string const &name)
{
	if (!remove(name.c_str()))
		return true;
	return false;
}

std::string	Response::getAutoindexPage()
{
	std::string	new_page = "";
	DIR *this_dir;
	if (!(this_dir = opendir(file_path.c_str())))
		return "";
	new_page += "<!DOCTYPE html>\n";
	new_page += "<html>\n";
	new_page += 	"\t<head>\n";
	new_page += 		"\t\t<title>OUR_WEBSERV</title>\n";
	new_page += 	"\t</head>\n";
	new_page += 	"\t<body>\n";

	struct dirent *read_dir;
	while((read_dir = readdir(this_dir)))
	{
		std::string read_name(read_dir->d_name);
		if ((read_name == ".." && __req->getUri() == "/")
			|| (read_name[0] == '.' && read_name != ".."))
			continue ;
		new_page += "\t\t<a href=\"" + read_name + "\">" + read_name + "</a><br>\n";
	}
	new_page += 	"\t</body>\n";
	new_page += "</html>\n";
	__file_type = "text/html";
	closedir(this_dir);
	return new_page;
}

void Response::internalServerError()
{
	__status = INTERNAL_SERVER_ERROR;
	body = getErrorBody();
}

std::string Response::getRedirBody(std::string redir_type)
{
	std::string	new_page = "";
	std::string temp = 
	new_page += "<!DOCTYPE html>\n";
	new_page += "<html>\n";
	new_page += 	"\t<head>\n";
	new_page += 		"\t\t<title>Redirect</title>\n";
	new_page += 	"\t</head>\n";
	new_page += 	"\t<body style=\"background-color:#000000\">\n";
	new_page += "\t\t\t<h1 align=\"center\" style=\"color:#00ff15; font-size:350%\">" + redir_type + " " + response_messages[__status] + "</h1>\n";
	new_page += "\t\t\t<p align=\"center\" style=\"color:#ff000d; font-size:150%\">Old request: " + __req->getUri() + ", new request: " + setRedirUri() +  "</p>\n";
	//new_page += "\t\t\t<a href=\"http://" + setRedirUri() + "\">" + "Try this" + "</a>\n";
	new_page += 	"\t</body>\n";
	new_page += "</html>\n";
	__file_type = "text/html";
	return new_page;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */
