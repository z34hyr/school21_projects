
#include <iostream>
#include <vector>

#include "Mindopen.hpp"

int	main(int argc, char* argv[])
{
	//void (* possibleComms[3]) (char) = {  };
	//char const comms[] = { '>', '<', '-', '.', ',', '[', ']'};
	if (argc == 2)
	{
		Mindopen compilator(argv[1], "");
		compilator.readFile();
	}
	else if (argc >= 3)
	{
		Mindopen compilator(argv[1], argv[2]);
		compilator.readFile();
	}
	else if (argc == 1)
	{
		std::cout << "No file name! Wooops 0_o. Stop it!" << std::endl;
		return -1;
	}
	return 0;
}
