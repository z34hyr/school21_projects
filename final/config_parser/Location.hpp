
#pragma once

#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

const std::string known_methods[] = {"GET", "POST", "DELETE"};
const std::string known_redirects[] = { "301", "302", "307" };
const std::string known_errors[] = { "400", "403", "404", "405", "411", "429", "500" };

class Location
{
	private:
		std::string					request; // request
		std::string					root;
		int							autoindex;
		int							save_file;
		std::string					cgi_pass;
		long						user_body_size;
		std::vector<std::string>	server_name;
		std::string					index;
		std::pair<std::string, std::string>	redirection;

	public:
	// default constructor
		std::map<int, std::string>	error_pages;
		Location(std::string request);
		std::vector<std::string>	allowed_requests;// different type of requests - GET, POST, etc.
		~Location();

	/*
	##############################################################
	##########	GETTERS									##########
	##############################################################
	*/
		std::string	getRequest();
		std::vector<std::string>	getAlllowedMethods();
		std::vector<std::string> getServerNames();
		std::string	getRoot();
		int		getAutoindex();
		int		getSaveFile();
		std::string	getCGIPath();
		long	getUserBodySize();
		std::map<int, std::string>	getErrorPaths();
		std::string	getDefaultPage();
		std::string	getIndex();
		std::pair<std::string, std::string>	getRedir();
		bool	isSetAllowedReq();
		bool	isSetRedir();
		bool	isSetErrPage(int err_number);

	/*
	##############################################################
	##########	SETTERS									##########
	##############################################################
	*/
		void	setRoot(std::string new_root);
		void	setErrPage(size_t err_number, std::string err_path);
		void	setAutoIndex(std::string autoind);
		void	setSaveFile(std::string save);
		void	setCGIPath(std::string path);
		int		setBodySize(std::string ubs);
		void	setRedirection(std::string redir_type, std::string path);
		void	insertDefaultErrPages(std::map<int, std::string> to_insert);
		void	setDefaultUBS(long server_ubs);
		void	setDefaultRoot(std::string server_root);
		void	setDefPage(std::string page_name);
		void	setDefaultAllowedMethods();
		void	setDefaultIndex(std::string server_index);
		void	setDefaultAutoindex();
		void	setDefaultSaveFile();
		void	setServerNames(std::vector<std::string> server_names);
		void	setIndex(std::string new_index);
		int		addRequest(std::string request);
		void	addErrPagesRootPath();
		int		checkRedirType(std::string redir_type);
		int		checkErrType(std::string err_type);
		void	showLocationInfo();
};
