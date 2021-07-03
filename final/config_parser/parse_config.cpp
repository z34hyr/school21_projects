
#include "parse_config.hpp"
#include "webserv.hpp"
#include <limits>

inline int	configError(std::string err_name, std::string info = "")
{
	if (info.size())
		info = "'" + info + "' ";
	std::cout << "	" << RED << err_name << " " << info << RESET << "(line " << line_counter << ")" << ". Exit..." << std::endl;
	return 1;
}

inline bool findDefaultLocation(ServerConf* server)
{
	std::vector<Location*> locations(server->getLocations());
	std::vector<Location*>::iterator i_b = locations.begin();
	while (i_b != locations.end())
	{
		if (i_b[0]->getRequest() == "/")
			return true;
		++i_b;
	}
	return false;
}

inline void	 insertDefaultParams(std::vector<ServerConf*> server_pool)
{
	std::vector<ServerConf*>::iterator i_b = server_pool.begin();
	std::vector<ServerConf*>::iterator i_e = server_pool.end();
	//Location* def_loc = new Location("/");

	while (i_b != i_e)
	{
		if (!findDefaultLocation(i_b[0]))
			i_b[0]->addLocation(new Location("/"));
			//i_b[0]->addLocation(def_loc);
		if (!i_b[0]->getRoot().size())
			i_b[0]->setRoot(default_root);
		i_b[0]->addErrPagesRootPath();
		if (i_b[0]->getPort() == -1)
			i_b[0]->setPort(default_port);
		if (i_b[0]->getUBS() == -1)
			i_b[0]->setBodySize(default_UBS);
		if (!i_b[0]->getIndex().size())
			i_b[0]->setIndex(default_index);
		if (!i_b[0]->getIP().size())
			i_b[0]->setIP(default_ip);
		i_b[0]->fillDefaultErrorPages();
		i_b[0]->setDefaultsForLocations();
		++i_b;
	}
	//delete def_loc;
}

inline int	openConfig(char *config_path)
{
	int fd;

	fd = open(config_path, O_RDONLY);
	if (fd == -1)
		std::cout << "Can't open " << config_path << std::endl;
	return fd;
}

inline int	chooseConfig(int argc, char **argv, char *default_path)
{
	int fd;

	fd = -1;
	if (argc >= 2)
		fd = openConfig(argv[1]);
	if (argc == 1 || fd == -1)
	{
		std::cout << "Using default config..." << std::endl;
		fd = openConfig(default_path);
		if (fd == -1)
		{
			std::cout << RED << "Can't open config. Exit..." << RESET << std::endl;
			exit(1);
		}
	}
	std::cout << "Config opened OK" << std::endl;
	return fd;
}

inline bool	skipEmptyLine(std::vector<std::string> current_line)
{
	if (!current_line.size())
		return true;
	return false;
}

inline bool	skipComment(std::vector<std::string> current_line)
{
	if (current_line.size() && current_line[0][0] == '#')
		return true;
	return false;
}

inline Location* fillLocationInfo(int fd, char* buff, std::string dir)
{
	Location* new_location = new Location(dir);
	std::vector<std::string> splitted_line;
	char *line;
	int splitted_size = 0;
	int err_page = 0;
	// long user_body_size = 0;

	//std::cout << "Filling location info...\n";
	while (fget_next_line(fd, buff, &line, NULL) > 0)
	{
		line_counter += 1;
		splitted_line.clear();
		if (ft_strlen(line))
			splitted_line = newSplitByDelimeter(std::string(line), " \t");
		delete[] line;
		line = NULL;
		splitted_size = splitted_line.size();
		if (skipEmptyLine(splitted_line) || skipComment(splitted_line))
			continue;
		// if root
		if (splitted_size == 2 && splitted_line[0] == "root")
		{
			if (new_location->getRoot().size())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			new_location->setRoot(splitted_line[1]);
		}
		else if (splitted_size == 2 && splitted_line[0] == "autoindex")
		{
			if (new_location->getAutoindex() != -1)
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			if (splitted_line[1] == "1" || splitted_line[1] == "0")
				new_location->setAutoIndex(splitted_line[1]);
			else
				exit(configError("Wrong autoindex argument"));
		}
		// if change cgi pass
		else if (splitted_size == 2 && splitted_line[0] == "cgi_pass")
		{
			if (new_location->getCGIPath().size())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			new_location->setCGIPath(splitted_line[1]);
		}
		// if change error_page
		else if (splitted_size == 3 &&
		splitted_line[0] == "error_page")
		{
			err_page = std::atoi(splitted_line[1].c_str());
			if (err_page > 0)
			{
				if (new_location->isSetErrPage(err_page))
					exit(configError("duplicated error page definition", splitted_line[1]));
				//new_location->setErrPage(err_page, splitted_line[2]);
				if (!new_location->checkErrType(splitted_line[1]))
					new_location->setErrPage(err_page, splitted_line[2]);
				else
					exit(configError("Wrong error page number"));
			}
			else
				exit(configError("Wrong error page number"));
		}
		// redirect option
		else if (splitted_size == 3 &&
		splitted_line[0] == "redirect")
		{
			if (new_location->isSetRedir())
			 	exit(configError("duplicated definition of parameter", splitted_line[0]));
			if (splitted_line[2][splitted_line[2].size() - 1] != '/')
				exit(configError("Redirection path should end with /"));
			if (!new_location->checkRedirType(splitted_line[1]))
				new_location->setRedirection(splitted_line[1], splitted_line[2]);
			else
				exit(configError("Wrong redirection type: ", splitted_line[1]));
		}
		// if wanna save
		else if (splitted_size == 2 && splitted_line[0] == "save_file")
		{
			if (new_location->getSaveFile() != -1)
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			if (splitted_line[1] == "1" || splitted_line[1] == "0")
				new_location->setSaveFile(splitted_line[1]);
			else
				exit(configError("Wrong save_file argument"));
		}
		// if change user body size
		else if (splitted_size == 2 &&
		splitted_line[0] == "user_body_size")
		{
			if (new_location->getUserBodySize() != -1)
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			if (new_location->setBodySize(splitted_line[1]))
				exit(configError("Wrong user_body_size value"));
		}
		// change default page
		else if (splitted_size == 2 &&
		splitted_line[0] == "index")
		{
			if (new_location->getIndex().size())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			new_location->setIndex(splitted_line[1]);
		}
		// if allowed methods
		else if (splitted_size >= 2 && splitted_line[0] == "allowed_methods")
		{
			if (new_location->isSetAllowedReq())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			while (splitted_size > 1)
			{
				// if method is in list of allowed for server
				if (new_location->addRequest(splitted_line[splitted_size - 1]))
					exit(configError("Unknown method in location config"));
				splitted_size -= 1;
			}
		}
		// end of location params
		else if (splitted_size == 1 && splitted_line[0] == "}")
			return new_location;
		else
			exit(configError("Unknown token for location config: ", splitted_line[0]));
	}
	return NULL;
}

ServerConf* fillServerInfo(int fd, char* buff)
{
	ServerConf*	new_server = new ServerConf();
	//extern size_t line_counter;
	std::vector<std::string> splitted_line;
	char *line;
	// int port;
	// long user_body_size;
	int splitted_size = 0;
	int err_page = 0;

	//std::cout << "Filling server info...\n";
	while (fget_next_line(fd, buff, &line, NULL) > 0)
	{
		line_counter += 1;
		splitted_line.clear();
		if (ft_strlen(line))
			splitted_line = newSplitByDelimeter(std::string(line), " \t");
		delete[] line;
		line = NULL;
		if (skipEmptyLine(splitted_line) || skipComment(splitted_line))
			continue;
		splitted_size = splitted_line.size();
		// if port
		if (splitted_size == 2 &&
		splitted_line[0] == "port")
		{
			if (new_server->getPort() != -1)
			 	exit(configError("duplicated definition of parameter", splitted_line[0]));
			if (new_server->setPort(splitted_line[1]))
				exit(configError("Wrong port"));
		}
		// if IP
		else if (splitted_size == 2 &&
		splitted_line[0] == "ip")
		{
			if (new_server->getIP().size())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			if (new_server->setIP(splitted_line[1]))
				exit(configError("wrong IP address"));
		}
		// if server_name
		else if (splitted_size >= 2 &&
		splitted_line[0] == "server_name")
		{
			if (new_server->isSetServerNames())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			while (splitted_size > 1)
				new_server->addServerName(splitted_line[splitted_size-- - 1]);
		}
		// if user_body_size
		else if (splitted_size == 2 &&
		splitted_line[0] == "user_body_size")
		{
			if (new_server->getUBS() != -1)
				exit(configError("duplicated definition of parameter", "user_body_size"));
			if (new_server->setBodySize(splitted_line[1]))
				exit(configError("Wrong user_body_size value"));
		}
		// index html
		else if (splitted_size == 2 &&
		splitted_line[0] == "index")
		{
			if (new_server->getIndex().size())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			new_server->setIndex(splitted_line[1]);
		}
		// if root
		else if (splitted_size == 2 &&
		splitted_line[0] == "root")
		{
			if (new_server->getRoot().size())
				exit(configError("duplicated definition of parameter", splitted_line[0]));
			new_server->setRoot(splitted_line[1]);
		}
		// new location params
		else if (splitted_size == 3 &&
		splitted_line[0] == "location" &&
		splitted_line[2] == "{")
		{
			if (new_server->checkOriginLocations(splitted_line[1]))
				exit(configError("Locations duplication found", splitted_line[1]));
			if (splitted_line[1][0] == '/' &&
			(splitted_line[1][splitted_line[1].size() - 1] == '/' ||
			(splitted_line[1].size() > 5 &&
			splitted_line[1].substr(splitted_line[1].size() - 4, 4) == "*.py") ||
			(splitted_line[1].size() > 6 && 
			splitted_line[1].substr(splitted_line[1].size() - 5, 5) == "*.php")))
			{
				Location* new_location = fillLocationInfo(fd, buff, splitted_line[1]);
				if (new_location)
					new_server->addLocation(new_location);
				else
					exit(1);
			}
			else
				exit(configError("Path for location must start with / and end with / or *.py or *.php"));
		}
		// if error_page
		else if (splitted_size == 3 &&
		splitted_line[0] == "error_page")
		{
			err_page = std::atoi(splitted_line[1].c_str());
			if (err_page > 0)
			{
				//if ()
				if (new_server->isSetErrPage(err_page))
					exit(configError("duplicated error page definition", splitted_line[1]));
				new_server->setErrPage(err_page, splitted_line[2]);
			}
			else
				exit(configError("Wrong error page number"));
		}
		// end of server options
		else if (splitted_size == 1 && splitted_line[0] == "}")
		{
			if (new_server->getIP().size()) {
				new_server->addServerPlusPort();
				return new_server;
			}
			else
				exit(configError("IP address not configured"));
		}
		else
			exit(configError("Unknown token for server config: ", splitted_line[0]));
	}
	return NULL;
}

inline int	compareServerNames(ServerConf* conf1, ServerConf* conf2)
{
	std::vector<std::string> serv1_names = conf1->getServerNames();
	std::vector<std::string> serv2_names = conf2->getServerNames();
	std::vector<std::string>::iterator ic1_b = serv1_names.begin();
	std::vector<std::string>::iterator ic1_e = serv1_names.end();
	std::vector<std::string>::iterator ic2_b = serv2_names.begin();
	std::vector<std::string>::iterator ic2_e = serv2_names.end();

	if (ic1_b == ic1_e && ic2_b == ic2_e)
		return 1;
	while (ic1_b != ic1_e)
	{
		if (std::find(ic2_b, ic2_e, *ic1_b) != ic2_e)
			return 1;
		++ic1_b;
	}
	return 0;
}

inline int	compareConfigs(ServerConf* conf1, ServerConf* conf2)
{
	if (conf1->getIP() == conf2->getIP() && conf1->getPort() == conf2->getPort())
	{
		if (compareServerNames(conf1, conf2))
		{
			std::cout << RED << "conflicting server names for " << conf1->getIP() <<
			":" <<conf1->getPort() << ". Exit..." << RESET << std::endl;
			exit(1);
		}
		return 1;
	}
	return 0;
}

inline void mergeServerConfigs(std::vector<ServerConf*> *configs)
{
	std::vector<ServerConf*>::iterator i_b = configs->begin();
	std::vector<ServerConf*>::iterator temp = i_b + 1;

	while (temp != configs->end())
	{
		if (compareConfigs(i_b[0], temp[0]))
		{
			i_b[0]->mergeLocations(temp[0]->getLocations());
			delete *temp;
			configs->erase(temp);
			temp = i_b + 1;
			continue;
		}
		++temp;
		if (temp == configs->end() && i_b != configs->end())
		{
			++i_b;
			temp = i_b + 1;
		}
	}
}

std::vector<ServerConf*>	getConfigs(int argc, char **argv)
{
	static char buff[GNL_BUF_SIZE];
	char *line;
	int	fd;
	size_t read_res;
	std::vector<std::string> splitted_line;
	std::vector<ServerConf*> servers_pool;

	fd = chooseConfig(argc, argv, default_path);
	line = NULL;
	while ((read_res = fget_next_line(fd, buff, &line, NULL)) > 0)
	{
		line_counter += 1;
		splitted_line.clear();
		if (ft_strlen(line))
			splitted_line = newSplitByDelimeter(std::string(line), "\t ");
		delete[] line;
		line = NULL;
		// skip empty line ||  skip comment
		if (skipEmptyLine(splitted_line) || skipComment(splitted_line))
			continue;
		// fill server info
		if (splitted_line.size() == 2 && splitted_line[0] == "server" && splitted_line[1] == "{")
		{
			// create server, push it to list/map/vector of servers
			ServerConf* new_server = fillServerInfo(fd, buff);
			if (new_server)
				servers_pool.push_back(new_server);
			else
				exit(1);
		}
		// if not template "server {" - config error, exit
		else
			exit(configError("Unknown token"));
	}
	close(fd);
	if (servers_pool.size() == 0)
	{
		std::cout << RED << "Wrong or empty config file" << RESET << std::endl;
		exit(1);
	}
	insertDefaultParams(servers_pool);
	// merge servers with same IP and address - just add all locations (all info is inside location vector)
	mergeServerConfigs(&servers_pool);
	// print info about all servers:
	std::vector<ServerConf*>::iterator i_b = servers_pool.begin();
	std::vector<ServerConf*>::iterator i_e = servers_pool.end();
	while (i_b != i_e)
	{
		i_b[0]->showServerInfo();
		++i_b;
	}
	return servers_pool;
}
