
#include "Human.hpp"

int	main(void)
{
	Human test;
	std::string buff_str;
	while (1)
	{
		std::cout << "Turn in name of function: ";
		std::getline(std::cin, buff_str);
		test.action(buff_str, "present");
	}
}
