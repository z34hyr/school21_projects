#include "toReturn.hpp"

// struct inputData
// {
// 	ServerConf* server;
// 	std::string	server_name;
// 	std::string	requested_path;
// };

struct tempHolder
{
	tempHolder(Location* loc, int counter) : curr_loc(loc), conj_counter(counter)
	{
		// std::cout << "	Added new loc to tempHolder:\n";
		// std::cout << "		" << loc->getRequest() << "\n";
		// std::cout << "		" << counter << "\n";
	};
	Location* curr_loc;
	int	conj_counter;
};

int		conjunctionCounter(std::string request_string, std::string conf_string)
{
	int is_cgi_loc = (conf_string[conf_string.size() - 1] == '/' ? 0 : 1);
	int is_req_folder = (request_string[request_string.size() - 1] == '/' ? 1 : 0);
	// int conj_counter = 0;
	int i = 0;
	std::vector<std::string> request_side = newSplitByDelimeter(request_string, "/");
	std::vector<std::string> config_side = newSplitByDelimeter(conf_string , "/");
	int size1 = config_side.size();
	int size2 = request_side.size();

	while (i < size1 && i < size2)
	{
		if (config_side[i] == request_side[i])
			i += 1;
		else
			break;
	}
	if (i == size1 - 1 && size1 == size2 && is_cgi_loc && !is_req_folder &&
	request_side[i].size() > 4 &&
	(request_side[i].substr(request_side[i].size() - 3, 3) == ".py" || request_side[i].substr(request_side[i].size() - 4, 4) == ".php"))
		i += 1;
	return (i >= size1 ? i : -1);
}

Location*	returnMaxConjLocation(std::vector<tempHolder> temp_holder)
{
	int max_conj = 0;
	Location* ret = temp_holder[0].curr_loc;
	std::vector<tempHolder>::iterator i_b = temp_holder.begin();
	std::vector<tempHolder>::iterator i_e = temp_holder.end();
	while (i_b != i_e)
	{
		if (i_b[0].conj_counter == -1)
			return i_b[0].curr_loc;
		if (max_conj < i_b[0].conj_counter)
		{
			ret = i_b[0].curr_loc;
			max_conj = i_b[0].conj_counter;
		}
		++i_b;
	}
	std::cout << GREEN << ret->getRequest() << RESET << "\n";
	return ret;
}

Location* returnResponse(ServerConf* server, std::string	server_name, std::string	requested_path)
{
	std::vector<Location*> temp = server->getLocations();
	std::vector<Location*>::iterator i_b = temp.begin();
	std::vector<Location*>::iterator i_e = temp.end();
	// int conj = 0;
	// Location* res = NULL;
	std::string config_path;
	std::vector<tempHolder> resultBucket;
	std::vector<std::string> s_names;
	int counter = 0;

	while (i_b != i_e)
	{
		// ищем имя сервера
		s_names = i_b[0]->getServerNames();
		config_path = i_b[0]->getRequest();
		if (std::find(s_names.begin(), s_names.end(), server_name) != s_names.end())
		{
			// отлично. в temp добавляем, и проверяем на наличие указанонго пути запрса.
			// если нет - ищем в других локациях. если там не найдем - вернем первый temp
			if ((counter = conjunctionCounter(requested_path, config_path)) != -1)
				resultBucket.push_back(tempHolder(i_b[0], counter));
		}
		++i_b;
	}
	if (resultBucket.size())
		return returnMaxConjLocation(resultBucket);
	// если указанного имени сервера нет,
	// то ищем таким же способом в первых n локациях с одинаковыми именами серверов
	s_names = temp[0]->getServerNames();
	size_t i = 0;
	while (temp.size() > i && s_names == temp[i]->getServerNames())
	{
		// отлично. в temp добавляем, и проверяем на наличие указанонго пути запрса.
		// если нет - ищем в других локациях. если там не найдем - вернем первый temp
		config_path = temp[i]->getRequest();
		if ((counter = conjunctionCounter(requested_path, config_path)) != -1)
			resultBucket.push_back(tempHolder(temp[i], counter));
		i += 1;
	}
	return returnMaxConjLocation(resultBucket);
}
