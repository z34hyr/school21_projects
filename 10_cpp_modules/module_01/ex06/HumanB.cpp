
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "	HumanB created" << std::endl;
    return;
}

HumanB::~HumanB(void)
{
	std::cout << "	HumanB destroyed" << std::endl;
    return;
}

void	HumanB::setWeapon(Weapon& weapon_type)
{
	this->_my_gun = &weapon_type;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_my_gun->getType() << std::endl;
}
