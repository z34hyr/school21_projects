
#include "Ice.hpp"

Ice::Ice(void)
{
	_type = "ice";
	return;
}
/*
Ice::Ice(std::string const & type)
{
	_type = type;
	return;
}
*/
Ice::~Ice(void)
{
	return;
}

Ice::Ice(const Ice& obj) : AMateria(obj)
{
	return;
}

Ice& Ice::operator = (const Ice& obj)
{
	AMateria::operator=(obj);
	return *this;
}

AMateria* Ice::clone() const
{
	AMateria* temp = new Ice(*this);
	return temp;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	increaseXP(10);
}
