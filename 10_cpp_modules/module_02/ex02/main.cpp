
#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

int	main(void)
{
	Fixed	a;
	Fixed const	b( Fixed(5.05f) * Fixed(2));
	Fixed const	c(42.42f);
	Fixed const	d(b);

	a = Fixed( 1234.4321f);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	if (a < b)
		std::cout << "a < b" << std::endl;
	else
		std::cout << "b <= a" << std::endl;
	std::cout << "+ : " << c + b << std::endl;
	std::cout << "- : " << c - b << std::endl;
	std::cout << "* : " << c * b << std::endl;
	std::cout << "/ : " << c / b << std::endl;
	std::cout << "min: " << Fixed::min(a, b) << std::endl;
	std::cout << "max: " << Fixed::max(a, b) << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a-- : " << a-- << std::endl;
	std::cout << "after a-- : " << a << std::endl;
}
