
#include "Fixed.class.hpp"
#include <cmath>

const int	Fixed::_frac_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	Fixed::_value = 0;
	return;
}

Fixed::Fixed(const int param)
{
	std::cout << "Parametric constructor called (int)" << std::endl;
	this->_value = (param << Fixed::_frac_bits);
}

Fixed::Fixed(const float param)
{
	std::cout << "Paramteric constructor called (float)" << std::endl;
	this->_value = static_cast<int>(roundf(param * (1 << this->_frac_bits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor constructor called" << std::endl;
	return;
}

// copy constructor
Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = obj.getRawBits();
	return;
}

//assignment operator overload
Fixed& Fixed::operator = (const Fixed& obj)
{
	_value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::toInt(void) const
{
	return(this->_value >> this->_frac_bits);
}

float		Fixed::toFloat(void) const
{
	 return (static_cast<float>(this->_value) / (1 << this->_frac_bits));
}

// << operator overload
std::ostream& operator << (std::ostream & z, const Fixed& obj)
{
	z << obj.toFloat();
	return (z);
}
