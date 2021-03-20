
#include <string>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* str_pointer = &str;
	std::string& str_reference = str;

	std::cout << "using a pointer: " << *str_pointer << std::endl;
	std::cout << "using a reference: " << str_reference << std::endl;
}
