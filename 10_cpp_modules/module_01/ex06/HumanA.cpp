
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& gun) : _name(name), _my_gun(gun)
{
    std::cout << "	HumanA created" << std::endl;
    return;
}

HumanA::~HumanA(void)
{
    std::cout << "	HumanA destroyed" << std::endl;
    return;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_my_gun.getType() << std::endl;
}