
#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
	this->setType(weapon_type);
    return;
}

Weapon::~Weapon(void)
{
    return;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const &	Weapon::getType(void)
{
	std::string const &	type_ref = this->_type;
	return (type_ref);
}