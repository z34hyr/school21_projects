
#include "Cure.hpp"

Cure::Cure(void)
{
	_type = "cure";
	return;
}
/*
Cure::Cure(std::string const & type)
{
	_type = type;
	return;
}
*/
Cure::~Cure(void)
{
	return;
}

Cure::Cure(const Cure& obj) : AMateria(obj)
{
	return;
}

Cure& Cure::operator = (const Cure& obj)
{
	AMateria::operator=(obj);
	return *this;
}

AMateria* Cure::clone() const
{
	AMateria* temp = new Cure(*this);
	return temp;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
	increaseXP(10);
}
