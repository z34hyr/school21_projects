
#include "Fixed.class.hpp"

const int	_fb_number = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	Fixed::_fp_value = 0;
	return;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor constructor called" << std::endl;
	return;
}

// copy constructor
Fixed::Fixed(const Fixed& obj)// : _fp_value(obj._fp_value)
{
	std::cout << "Copy constructor called" << std::endl;
	_fp_value = obj.getRawBits();
	return;
}

//assignment operator =
Fixed& Fixed::operator = (const Fixed& obj)
{
	std::cout << "Assignation operator called" << std::endl;
	_fp_value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fp_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}
