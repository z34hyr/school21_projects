
#include "Location.hpp"

class ServerConf;

Location::Location(std::string req) : allowed_requests(0)
{
	request = req;
	autoindex = -1;
	save_file = -1;
	user_body_size = -1;
};
// Location::Location(std::string req,
// 	std::vector<std::string> s_n,
// 	long u_b_s,
// 	std::string r,
// 	std::map<int, std::string> err, std::string index) : 
// 		request(req), 
// 		server_name(s_n), 
// 		user_body_size(u_b_s), 
// 		root(r), 
// 		error_pages(err),
// 		index(index)
// {
// 	allowed_requests = std::vector<std::string>(known_methods, known_methods + sizeof(known_methods) / sizeof(std::string));
// 	autoindex = false;
// 	save_file = false;
// };
Location::~Location() {};

std::string	Location::getRequest() { return request; };
std::vector<std::string> Location::getServerNames() { return server_name; };
std::string	Location::getRoot() { return root; };
int		Location::getAutoindex() { return autoindex; };
int		Location::getSaveFile() { return save_file; };
std::string	Location::getCGIPath() { return cgi_pass; };
long	Location::getUserBodySize() { return user_body_size; };
std::map<int, std::string>	Location::getErrorPaths() { return error_pages; };
std::string	Location::getIndex() { return index; };
std::pair<std::string, std::string>	Location::getRedir() { return redirection; };
bool	Location::isSetAllowedReq() { return allowed_requests.size() ? true : false; };
bool	Location::isSetRedir() { return redirection.first.size() ? true : false; };
bool	Location::isSetErrPage(int err_number)
{
	if (error_pages.find(err_number) != error_pages.end())
		return true;
	return false;
};

void	Location::setRoot(std::string new_root) { root = new_root; };
void	Location::setErrPage(size_t err_number, std::string err_path) { error_pages[err_number] = err_path; };
void	Location::setAutoIndex(std::string autoind) { autoindex = (autoind == "1" ? true : false); };
void	Location::setSaveFile(std::string save) { save_file = (save == "1" ? true : false); };
void	Location::setCGIPath(std::string path) { cgi_pass = path; };
int		Location::setBodySize(std::string ubs)
{
	// long max_val = std::numeric_limits<int>::max();
	long temp = std::atol(ubs.c_str());
	if (temp > 0 && (ubs.length() < 19 || (ubs.length() == 19 && ubs <= "9223372036854775807")))
	{
		user_body_size = temp;
		return 0;
	}
	return 1;
};
void	Location::setIndex(std::string page_name) { index = page_name; };
void	Location::insertDefaultErrPages(std::map<int, std::string> to_insert)
{
	error_pages.insert(to_insert.begin(), to_insert.end());
};
void	Location::setRedirection(std::string redir_type, std::string path)
{
	redirection.first = redir_type;
	redirection.second = path;
}
void	Location::setDefaultUBS(long server_ubs)
{
	if (user_body_size <= 0)
		user_body_size = server_ubs;
}
void	Location::setDefaultRoot(std::string server_root)
{
	if (root.empty())
		root = server_root;
}
void	Location::setDefaultAllowedMethods()
{
	if (allowed_requests.empty())
		allowed_requests = std::vector<std::string>(known_methods, known_methods + sizeof(known_methods) / sizeof(std::string));
}
void	Location::setDefaultIndex(std::string server_index)
{
	if (index.empty())
		index = server_index;
}
void	Location::setDefaultAutoindex() { if (autoindex == -1) autoindex = 0; };
void	Location::setDefaultSaveFile() { if (save_file == -1) save_file = 0; };
void	Location::setServerNames(std::vector<std::string> server_names) { server_name = server_names; };
int		Location::addRequest(std::string request)
{
	std::vector<std::string> methods_vect(known_methods, known_methods + sizeof(known_methods) / sizeof(std::string));

	if (std::find(methods_vect.begin(), methods_vect.end(), request) != methods_vect.end())
		this->allowed_requests.push_back(request);
	else
		return 1;
	return 0;
}
void	Location::addErrPagesRootPath()
{
	std::map<int, std::string>::iterator i_b = error_pages.begin();
	while (i_b != error_pages.end())
	{
		i_b->second = root + "/" + i_b->second;
		++i_b;
	}
};
int		Location::checkRedirType(std::string redir_type)
{
	std::vector<std::string> allowed_redirects(known_redirects, known_redirects + sizeof(known_redirects) / sizeof(std::string));

	if (std::find(allowed_redirects.begin(), allowed_redirects.end(), redir_type) != allowed_redirects.end())
		return 0;
	else
		return 1;
	return 1;
}

int		Location::checkErrType(std::string err_type)
{
	std::vector<std::string> allowed_errors(known_errors, known_errors + sizeof(known_errors) / sizeof(std::string));

	if (std::find(allowed_errors.begin(), allowed_errors.end(), err_type) != allowed_errors.end())
		return 0;
	else
		return 1;
	return 1;
}

std::vector<std::string>	Location::getAlllowedMethods()
{
	return allowed_requests;
}

void	Location::showLocationInfo()
{
	std::cout << "	Location info:" << std::endl;
	std::cout << "		Server name(s): ";
	std::vector<std::string>::iterator i_sn_b = server_name.begin();
	while (i_sn_b != server_name.end())
	{
		std::cout << *i_sn_b << " ";
		++i_sn_b;
	}
	std::cout << std::endl;
	std::cout << "		Request: " << request << std::endl;
	std::cout << "		Root: " << root << std::endl;
	std::cout << "		Max user body size: " << user_body_size << std::endl;
	std::cout << "		Autoindex: " << autoindex << std::endl;
	std::cout << "		Save file: " << save_file << std::endl;
	if (cgi_pass.size())
		std::cout << "		CGI pass: " << cgi_pass << std::endl;
	else
		std::cout << "		CGI pass: disabled" << std::endl;
	std::cout << "		Index: " << index << std::endl;
	if (redirection.first.size())
		std::cout << "		Redirection " << redirection.first << " to " << redirection.second << std::endl;
	std::vector<std::string>::iterator i_b = allowed_requests.begin();
	std::vector<std::string>::iterator i_e = allowed_requests.end();
	std::cout << "		Allowed methods: ";
	while (i_b != i_e)
	{
		std::cout << i_b[0] << " ";
		++i_b;
	}
	std::cout << std::endl;
	std::cout << "		Error pages:\n";
	std::map<int, std::string>::iterator im_b = error_pages.begin();
	std::map<int, std::string>::iterator im_e = error_pages.end();
	while (im_b != im_e)
	{
		std::cout << "			" << im_b->first << ": " << im_b->second << std::endl;
		++im_b;
	}
};
std::string Location::getDefaultPage()
{
	return index;
}
