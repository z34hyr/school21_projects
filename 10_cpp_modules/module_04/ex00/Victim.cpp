
#include "Victim.hpp"

Victim::Victim(void)
{
	return;
}

Victim::Victim(std::string name) : _name(name)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
	return;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
	return;
}

// copy constructor
Victim::Victim(const Victim& obj)
{
	std::cout << "Made a copy of Victim" << std::endl;
	_name = obj._name + "_copy";
	return;
}

//assignment operator = overloader
Victim& Victim::operator = (const Victim& obj)
{
	std::cout << "Equaled to Victim" << std::endl;
	_name = obj._name + "_assign";
	return *this;
}

std::string		Victim::get_name(void) const
{
	return(_name);
}

void			Victim::set_name(std::string name)
{
	_name = name;
}

// << operator overloader
std::ostream& operator << (std::ostream & z, const Victim& obj)
{
	z << "I'm " << obj.get_name() << " and I like otters!" << std::endl;
	return (z);
}

void		Victim::getPolymorphed(void) const
{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}
