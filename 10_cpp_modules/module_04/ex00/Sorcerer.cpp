#include "Sorcerer.hpp"

Sorcerer::Sorcerer(void)
{
	return;
}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << this->_name << ", " << this->_title << ", is born!" << std::endl;
	return;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << this->_name << ", " << this->_title << ", is dead. \
Consequences will never be the same!" << std::endl;
	return;
}

// copy constructor
Sorcerer::Sorcerer(const Sorcerer& obj)
{
	std::cout << "Made a copy of sorcerer" << std::endl;
	_name = obj._name + "_copy";
	_title = obj._title + "_copy";
	return;
}

//assignment operator = overloader
Sorcerer& Sorcerer::operator = (const Sorcerer& obj)
{
	std::cout << "Equaled to sorcerer" << std::endl;
	_name = obj._name + "_assign";
	_title = obj._title + "_assign";
	return *this;
}

std::string		Sorcerer::get_name(void) const
{
	return _name;
}

void			Sorcerer::set_name(std::string name)
{
	_name = name;
}

std::string		Sorcerer::get_title(void) const
{
	return(_title);
}

void			Sorcerer::set_title(std::string title)
{
	_title = title;
}

// << operator overloader
std::ostream& operator << (std::ostream & z, const Sorcerer& obj)
{
	z << "" << "I am " << obj.get_name() << ", " << obj.get_title() << ", and I like ponies!" << std::endl;
	return (z);
}

void			Sorcerer::polymorph(const Victim & victim) const
{
	victim.getPolymorphed();
	return;
}
