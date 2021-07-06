#include <string>
#include <iostream>
#include <sstream>
# include <fcntl.h>
#include <fstream>
#include <vector>
#include <map>
#include <string.h>

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

int main()
{
	int fd_new_file;
	//std::string curr;
	std::ifstream inFile;
	std::string username;
    std::pair<std::string, std::string> serv_user;
	std::map<std::pair<std::string, std::string>, std::map<std::string, std::string>> server_cookie;
	inFile.open("testfile");
	if (!inFile.is_open())
	{
		std::cout << "No such file or no access\n";
		exit(1);
	}
	for (std::string curr; std::getline(inFile, curr); )
	{
		std::vector<std::string> temp_split = splitByDelimeter(curr, " ");
		if (temp_split.size() == 1)
		{
			username = temp_split[0];
			serv_user.first = "testservname";
			serv_user.second = username;
		}
		else if (temp_split.size() == 2)
		{
			server_cookie[serv_user][temp_split[0]] = temp_split[1];
		}
	}
	std::cout << "Map size: " << server_cookie.size() << std::endl;
	std::cout << server_cookie[serv_user]["key3"] << std::endl;
	inFile.close();
}