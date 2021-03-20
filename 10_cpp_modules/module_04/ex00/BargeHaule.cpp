
#include "BargeHaule.hpp"

BargeHaule::BargeHaule(void)
{
	return;
}

BargeHaule::BargeHaule(std::string name) : Victim(name)
{
	_name = name;
	std::cout << "Menya zvat " << YELLOW << _name << RESET << std::endl;
	return;
}

BargeHaule::~BargeHaule(void)
{
	std::cout << "For the tzar..." << std::endl;
	return;
}

// copy constructor
BargeHaule::BargeHaule(const BargeHaule& obj)
{
	std::cout << "Made a copy of BargeHaule" << std::endl;
	_name = obj._name + "_copy";
	return;
}

//assignment operator = overloader
BargeHaule& BargeHaule::operator = (const BargeHaule& obj)
{
	std::cout << YELLOW << _name << RESET << " equaled to BargeHaule" << std::endl;
	_name = obj._name + "_assign";
	return *this;
}

void	BargeHaule::getPolymorphed(void) const
{
	std::cout << YELLOW << _name << RESET << " has been turned into a boyar!!!" << std::endl;
}

// << operator overloader
std::ostream& operator << (std::ostream & z, const BargeHaule& obj)
{
	z << "I'm " << YELLOW << obj.get_name() << RESET << " and I like to haule a barge!" << std::endl;
	return (z);
}
