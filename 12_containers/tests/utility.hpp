
#pragma once

#include <vector>
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstring>
#include "vector.hpp"
#include "list.hpp"

# define CYAN  "\x1B[36m" // Cyan
# define GREEN   "\033[32m" // Green
# define YELLOW "\033[33m" // Yellow
# define WHITE "\033[37m" // White
# define RESET   "\033[0m"

struct container_info
{
	std::string owner;
	std::string color;
	std::string type;
};

container_info STL;
container_info MINE;

class bzz
{
	public:
		bzz() { _val = 1; };
		bzz(int val) : _val(val) {};
		virtual ~bzz() { };
		void printVal() { std::cout << _val << std::endl; }
	private:
		int _val;
};

void print_test_name(std::string test_name);

template <typename T>
void print_iterable(T container, container_info WHICH)
{
	typename T::iterator i_b = container.begin();
	typename T::iterator i_e = container.end();
	int counter = 0;
	std::cout << "================================" << std::endl;
	std::cout << "Container type: " << WHICH.color << WHICH.owner << " " << WHICH.type << RESET << std::endl;
	//std::cout << WHICH.color << "size " << container.size() << RESET << "; " << container.max_size() << " - max_size; " << container.capacity() << " - capacity." << std::endl;
	std::cout << WHICH.color << "print forward: " << RESET << std::endl;
	while (i_b != i_e)
	{
		std::cout << *i_b << " ";
		++i_b;
		counter += 1;
	}
	std::cout << std::endl;
	//std::cout << WHICH.color << "(total " << counter << ")" << RESET << std::endl;
}

template <typename T>
void print_iterable_reverse(T container, container_info WHICH)
{
	typename T::reverse_iterator i_b = container.rbegin();
	typename T::reverse_iterator i_e = container.rend();
	int counter = 0;
	//std::cout << "================================" << std::endl;
	//std::cout << "Container type: " << WHICH.color << WHICH.owner << " " << WHICH.type << RESET << std::endl;
	//std::cout << WHICH.color << "size " << container.size() << RESET << "; " << container.max_size() << " - max_size; " << container.capacity() << " - capacity." << std::endl;
	std::cout << WHICH.color << "print backward: " << RESET << std::endl;
	while (i_b != i_e)
	{
		std::cout << *i_b << " ";
		++i_b;
		counter += 1;
	}
	std::cout << WHICH.color << "(total " << counter << ")" << RESET << std::endl;
}

void fill_info(std::string type)
{
	STL.type = type;
	MINE.type = type;
}

void print_test_name(std::string test_name, std::string command)
{
	std::cout << YELLOW;
	for (int i = 0; i < test_name.length(); i++)
		std::cout << "=";
	std::cout << std::endl;
	std::cout << test_name << std::endl;
	std::cout << "command: " << WHITE << command << YELLOW << std::endl;
	for (int i = 0; i < test_name.length(); i++)
		std::cout << "=";
	std::cout << RESET << std::endl;
}