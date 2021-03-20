
#include <iostream>
#include <string>
#include "Phonebook.class.hpp"

uint16_t const book_size = 8;

int main(void)
{
    Phonebook	instance[book_size];
	std::string	command;
	uint16_t	i = 0;
	uint16_t	n = 10;

	std::cout << "Hello! This is a pooPhoneBook" << std::endl \
	<< book_size << " slot(s) is empty" << std::endl \
	<< "Use 'ADD' or 'SEARCH' or 'EXIT' command" << std::endl;
	while (1)
	{
		if (std::cin.eof())
			std::cin.clear();
		std::cout << "Enter command: ";
		//std::cin >> command;
		std::getline(std::cin, command);
		if (!command.compare("EXIT"))
			return 0;
		else if (!command.compare("ADD"))
			instance[i].f_add_contact(&i, book_size);
		else if (!command.compare("SEARCH"))
		{
			for (uint16_t j = 0; j < i; j += 1)
				instance[j].f_show_short_list();
			if (i > 0) // if there is no contact yet - skip search by number
			{
				std::cout << "Enter desired number of contant: ";//<< std::endl;
				std::cin >> n;
				if (std::cin.fail())
				{
					std::cout << "	Not number has been turned!" << std::endl;
					std::cin.clear();
				}
				else
				{
					std::cout << "	Got it. Let's check if we have this contact..." << std::endl;
					if (n <= i)
						instance[n - 1].f_show_contact();
					else
						std::cout << "	There is no such contact!" << std::endl;
					std::cin.clear();
					std::cin.ignore(256,'\n');
				}
			}
		}	
		else	
			std::cout << "Wrong command. Use 'ADD' or 'SEARCH' or 'EXIT'" << std::endl;
	}
	return 0;
}
