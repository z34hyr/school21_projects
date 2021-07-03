
#include "ServerConf.hpp"

	// default server profile
	ServerConf::ServerConf() : locations(0)
	{
		// fill default values
		port = -1;
		user_body_size = -1;
	};
	ServerConf::ServerConf(ServerConf& obj)
	{
		this->operator=(obj);
	}
	ServerConf& ServerConf::operator=(ServerConf& obj)
	{
		port = obj.getPort();
		ip = obj.getIP();
		server_name = obj.getServerNames();
		user_body_size = obj.getUBS();
		root = obj.getRoot();
		error_pages = obj.getErrorPages();
		locations = obj.getLocations();
		index = obj.getIndex();
		return *this;
	};
	void	ServerConf::clearLocations()
	{
		int j = locations.size();
		int i = 0;
		while (i < j)
		{
			delete locations[i];
			i += 1;
		}
		locations.clear();
	}
	ServerConf::~ServerConf() {};

	/*
	##############################################################
	##########	GETTERS									##########
	##############################################################
	*/
	std::string	ServerConf::getIP() { return ip; };
	int			ServerConf::getPort() { return port; };
	std::vector<std::string> ServerConf::getServerNames() { return server_name; };
	long	ServerConf::getUBS() { return user_body_size; };
	std::string	ServerConf::getRoot() { return root; };
	std::map<int, std::string>	ServerConf::getErrorPages() { return error_pages; };
	std::string	ServerConf::getIndex() { return index; };
	std::vector<Location*>	ServerConf::getLocations() { return locations; };
	bool	ServerConf::isSetErrPage(int err_number)
	{
		if (error_pages.find(err_number) != error_pages.end())
		return true;
	return false;
	};
	bool	ServerConf::isSetServerNames() { return server_name.size() ? true : false;};

	/*
	##############################################################
	##########	SETTERS									##########
	##############################################################
	*/
	int		ServerConf::setPort(std::string user_port)
	{
		int	temp = std::atoi(user_port.c_str());
		if (temp > 0 && (user_port.length() < 5 || (user_port.length() == 5 && user_port <= "65535")))
		{
			port = temp;
			return 0;
		}
		return 1;
	};
	int		ServerConf::setIP(std::string user_ip)
	{
		std::vector<std::string> splitted_ip;
		std::string copy(user_ip);
		int temp;
		splitted_ip = newSplitByDelimeter(user_ip, ".");
		if (splitted_ip.size() == 4)
		{
			int i = 0;
			while (i < 4)
			{
				temp = std::atoi(splitted_ip[i].c_str());
				if ((temp > 0 && temp <= 255 && splitted_ip[i].size() <= 3) || (temp == 0 && splitted_ip[i] == "0"))
					i += 1;
				else
					return 1;
			}
			ip = copy;
			return 0;
		}
		return 1;
	};
	void	ServerConf::addServerName(std::string new_name)
	{ 
		server_name.push_back(new_name);
	}
	void	ServerConf::addLocation(Location* loc) { locations.push_back(loc); };
	int		ServerConf::setBodySize(std::string ubs_string)
	{
		// long max_val = std::numeric_limits<int>::max();
		long temp = std::atol(ubs_string.c_str());
		if (temp > 0 && (ubs_string.length() < 19 || (ubs_string.length() == 19 && ubs_string <= "9223372036854775807")))
		{
			user_body_size = temp;
			return 0;
		}
		return 1;
	};
	void	ServerConf::setRoot(std::string new_root) { root = new_root; };
	void	ServerConf::setErrPage(size_t err_number, std::string err_path) { error_pages[err_number] = err_path; };
	void	ServerConf::setIndex(std::string new_index) { index = new_index; };
	void	ServerConf::setDefaultsForLocations()
	{
		std::vector<Location*>::iterator i_b = locations.begin();
		std::vector<Location*>::iterator i_e = locations.end();

		while (i_b != i_e)
		{
			i_b[0]->setDefaultRoot(root);
			i_b[0]->addErrPagesRootPath();
			i_b[0]->insertDefaultErrPages(error_pages);
			i_b[0]->setDefaultUBS(user_body_size);
			i_b[0]->setDefaultAllowedMethods();
			i_b[0]->setServerNames(server_name);
			i_b[0]->setDefaultIndex(index);
			i_b[0]->setDefaultAutoindex();
			i_b[0]->setDefaultSaveFile();
			++i_b;
		}
	};
	void	ServerConf::addErrPagesRootPath()
	{
		std::map<int, std::string>::iterator i_b = error_pages.begin();
		while (i_b != error_pages.end())
		{
			i_b->second = root + "/" + i_b->second;
			if (checkExistAndType(i_b->second.c_str()) != FILE || !canBeOpened(i_b->second)) {
				std::cout << "fail to open file " << i_b->second << std::endl;
				exit(0);
			}
			++i_b;
		}
	};
	bool	ServerConf::checkOriginLocations(std::string loc_name)
	{
		std::vector<Location*>::iterator i_b = locations.begin();

		while (i_b != locations.end())
		{
			if (loc_name == i_b[0]->getRequest())
				return true;
			++i_b;
		}
		return false;
	};
	bool	ServerConf::checkLocationPresence() { return locations.empty() ? false : true; };

	void	ServerConf::mergeLocations(std::vector<Location*>	loc)
	{
		locations.insert(locations.end(), loc.begin(), loc.end());
	};
	void	ServerConf::fillDefaultErrorPages()
	{
		// std::map<int, std::string>::iterator i_b = error_pages.begin();
		std::map<int, std::string> def_map;
		def_map[400] = root + default_err_folder + "400.html";
		def_map[403] = root + default_err_folder + "403.html";
		def_map[404] = root + default_err_folder + "404.html";
		def_map[405] = root + default_err_folder + "405.html";
		def_map[413] = root + default_err_folder + "413.html";
		def_map[500] = root + default_err_folder + "500.html";
		checkDefaultType(def_map);
		error_pages.insert(def_map.begin(), def_map.end());
	}

	void ServerConf::checkDefaultType(std::map<int, std::string> def_map)
	{
		for (std::map<int, std::string>::iterator i_b = def_map.begin(); i_b != def_map.end(); i_b++) {
			if (checkExistAndType(i_b->second.c_str()) != FILE || !canBeOpened(i_b->second)) {
				std::cout << "fail to open file " << i_b->second << std::endl;
				exit(0);
			}
		}
	}
	void	ServerConf::showServerInfo()
	{
		std::cout << "Server info:" << std::endl;
		std::cout << "	Port: " << port << std::endl;
		std::cout << "	IP: " << ip << std::endl;
		std::cout << "	UBS:" << user_body_size << std::endl;
		std::cout << "	Root:" << root << std::endl;
		std::cout << "	Index: " << index << std::endl;
		std::vector<Location*>::iterator i_b = locations.begin();
		std::vector<Location*>::iterator i_e = locations.end();
		while (i_b != i_e)
		{
			i_b[0]->showLocationInfo();
			++i_b;
		}
		std::cout << std::endl;
	};

	void ServerConf::addServerPlusPort()
	{
		std::vector<std::string> tmp;
		std::ostringstream s1;
		for (std::vector<std::string>::iterator name = server_name.begin(); name != server_name.end(); name++) {
			s1 << port;
			tmp.push_back(*name + ":" + s1.str() /* std::to_string(port) */ );
		}
		server_name.insert(server_name.begin(), tmp.begin(), tmp.end());
	}
