#ifndef SERVER_HPP
# define SERVER_HPP

#include "webserv.hpp"
#include "../config_parser/parse_config.hpp"
class Client;
class ServerConf;
class Location;

class Server
{
	public:
		Server();
		Server(ServerConf* serverconfig);
		Server( Server const & src );
		~Server();
		Location *getConfigByUrl(std::string host, std::string uri);

	private:
		Server &		operator=( Server const & rhs );
		int __socket_fd;
		ServerConf*	__server_config;
		std::map<int, Client*> __clients;
		time_t time_last_action;
		struct sockaddr_in __addr;
		//std::map<std::pair<std::string, std::string>, std::map<std::string, std::string> > __server_cookie;
		std::map<std::string, std::string> __server_cookie;
		std::vector<std::string> __sessions_ids;
		int	__session_enabled;
		unsigned long __total_counter;
		//server_name,username<map of cookie key + value>
	public:
		void fixTime();
		std::map<int, std::string> errorPages;
		int createSocket(int port, std::string ip);
		std::string getRoot();
		std::string getDef();
		Client *acceptClient();
		time_t getTimeLastAction();
		ServerConf*	getServerConf();
		void	pullCookie();
		void	saveCookie();
		std::map<std::string, std::string> getCookies();
		void	changeSessionIds(std::string session_id, int action);//1 - add, 0 - delete
		bool	checkSessionId(std::string session_id); // 1 -session is valid, 0 - closed
		std::vector<std::string>	getSessions();
		int		getSessionEnabled();
		unsigned long		getTotalCounter();
		void	addTotalCounter();
};

#endif
