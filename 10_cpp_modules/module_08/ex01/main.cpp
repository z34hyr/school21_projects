
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include "span.hpp"

template<typename T>
void	showElem(T elem)
{
	std::cout << elem << std::endl;
}

int	main()
{
	Span empty_class(200);
	std::cout << "size vect_class: " << empty_class.getSize() << std::endl;
	try
	{
		std::cout << "shortest span: " << empty_class.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	empty_class.addNumber(999);
	try
	{
		std::cout << "longest span: " << empty_class.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span vect_class(4);
	try
	{
		vect_class.addNumber(100);
		vect_class.addNumber(2);
		vect_class.addNumber(20);
		vect_class.addNumber(40);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "size vect_class: " << vect_class.getSize() << std::endl;
	std::cout << "shortest span: " << vect_class.shortestSpan() << std::endl;
	std::cout << "longest span: " << vect_class.longestSpan() << std::endl;

	Span vect_class2(20000);
	try
	{
		int rnd_arr[20000];
		for (int i = 0; i < 20000; i++)
			rnd_arr[i] = std::rand() % 1000;
		vect_class2.addNumber(rnd_arr, 20000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "size vect_class2: " << vect_class2.getSize() << std::endl;
	std::cout << "shortest span: " << vect_class2.shortestSpan() << std::endl;
	std::cout << "longest span: " << vect_class2.longestSpan() << std::endl;
}

// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(5);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// }
