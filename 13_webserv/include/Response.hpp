#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "webserv.hpp"

class Request;
class Location;
class Response
{
	std::string __protocol;
	int			 __status;
	std::string __status_message;
	std::string __server_name;
	std::string __text;
	std::string __file_type;
	std::map<std::string, std::string> mime_types;
	std::map<std::string, std::string> __mapped_headers;

	public:
		std::map<int, std::string> response_messages;
	    size_t sended_bytes;
	    std::string file_path;
		Response();
		Response(Client	*client, Request *req);
		~Response();

		std::string getHead();
		std::string getBody();
		void		prepareBody();
		void		prepareFull();
		bool	execute();
		std::string getText();
		std::string getSessionID();
		int checkConfig();
		bool isDir(std::string path);
		int fileExecute(int code);
		std::string getConnectionHeader();
		std::string	getFileType();
		bool is_execute_cgi;
		void	executeCgi();
	private:
		Response( Response const & src );
		Response &		operator=( Response const & rhs );
		char **getCgiEnv();
		void internalServerError();
		std::string getFromFilePath();
		std::string getFullPath(bool autoindex);
		std::string	findKnownType(std::string type);
		std::string getErrorBody();
		std::string getRedirBody(std::string redir_type);
		void checkPath();
		Request *__req;
		Location *__config;
		Client	*__client;
		std::string	body;
		std::string	additional_header;
		std::string readFromFile(std::string path);
		bool		prepareCgi();
		bool		create_new_file(std::string const &name, std::string const &info);
		bool		delete_file(std::string const &name);
		std::string	getAutoindexPage();
		void		setFileType(std::string file_path);
		std::string	setRedirUri();
		std::string	joinCookie();

};

#endif /* ******************************************************** RESPONSE_H */
