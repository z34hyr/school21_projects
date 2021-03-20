

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	_xp = 0;
	return;
}

AMateria::~AMateria(void)
{
	return;
}

AMateria::AMateria(const AMateria& obj) : _xp(0), _type(obj._type)
{
	return;
}

AMateria& AMateria::operator = (const AMateria& obj)
{
	_type = obj._type;
	_xp = 0;
	return *this;
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return _type;
}

unsigned int	AMateria::getXP() const
{
	return _xp;
}

void AMateria::use(ICharacter& target)
{
	increaseXP(10);
	std::cout << target.getName() << std::endl;
	return;
}

void			AMateria::increaseXP(unsigned int size)
{
	_xp += size;
	return;
}
