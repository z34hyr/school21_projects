
#include "Peon.hpp"

Peon::Peon(void)
{
	return;
}

Peon::Peon(std::string name) : Victim(name)
{
	_name = name;
	std::cout << "Zog zog." << std::endl;
	return;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
	return;
}

// copy constructor
Peon::Peon(const Peon& obj)
{
	std::cout << "Made a copy of Peon" << std::endl;
	_name = obj._name + "_copy";
	return;
}

//assignment operator = overloader
Peon& Peon::operator = (const Peon& obj)
{
	std::cout << CYAN << _name << RESET << " equaled to Peon" << std::endl;
	_name = obj._name + "_assign";
	return *this;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << CYAN << _name << RESET << " has been turned into a pink pony!" << std::endl;
}

// << operator overloader
std::ostream& operator << (std::ostream & z, const Peon& obj)
{
	z << "I'm " << CYAN << obj.get_name() << RESET << " and I like otters!" << std::endl;
	return (z);
}
