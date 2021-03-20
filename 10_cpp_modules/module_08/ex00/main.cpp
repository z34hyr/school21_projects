
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

#include "easyfind.hpp"

int	main()
{
	std::vector<int> numbers;
	for (int i = 0; i < 10; i++)
		numbers.push_back(std::rand() % 100);
	numbers.push_back(10);
	std::cout << "numbers(vector): {";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << ", ";
	std::cout << "};" << std::endl;

	try
	{
		std::cout << *easyfind<std::vector<int> >(numbers, 10) << std::endl;
		std::cout << *easyfind<std::vector<int> >(numbers, 11) << std::endl;
		std::cout << *easyfind<std::vector<int> >(numbers, 12) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
