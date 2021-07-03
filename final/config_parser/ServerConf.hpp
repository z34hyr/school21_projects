
#pragma once

#include "Location.hpp"
#include "parse_config.hpp"

const std::string default_index = "index.html";
const std::string default_ip = "0.0.0.0";
const std::string default_port = "80";
const std::string default_root = "/html";
const std::string default_UBS = "100000";
const std::string default_err_folder = "/error_pages/";

class Location;

class ServerConf
{
	private:
		int							port;
		std::string					ip;
		std::vector<std::string>	server_name;
		long						user_body_size;
		std::string					root;
		std::map<int, std::string>	error_pages;
		std::string					index;

		std::vector<Location*>		locations;

	public:
		// default server profile
		ServerConf();
		~ServerConf();
		void	clearLocations();
		void	checkDefaultType(std::map<int, std::string> def_map);
		// copy constructor
		ServerConf(ServerConf& obj);
		ServerConf& operator=(ServerConf& obj);
		// get:
		std::string	getIP();
		int			getPort();
		std::vector<std::string> getServerNames();
		long	getUBS();
		std::string	getRoot();
		std::map<int, std::string>	getErrorPages();
		std::string	getIndex();
		std::vector<Location*>	getLocations();
		bool	isSetErrPage(int err_number);
		bool	isSetServerNames();
		// change:
		int		setPort(std::string user_port);
		int		setIP(std::string user_ip);
		void	addServerName(std::string new_name);
		void	addLocation(Location* loc);
		int		setBodySize(std::string ubs_string);
		void	setRoot(std::string new_root);
		void	setErrPage(size_t err_number, std::string err_path);
		void	setIndex(std::string index);
		void	addServerPlusPort();
		void	setDefaultsForLocations();
		void	addErrPagesRootPath();
		bool	checkLocationPresence();
		bool	checkOriginLocations(std::string loc_name);
		void	mergeLocations(std::vector<Location*>	loc);
		void	fillDefaultErrorPages();
		void	showServerInfo();
};
