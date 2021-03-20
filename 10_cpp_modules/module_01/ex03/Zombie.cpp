
#include "Zombie.hpp"

std::int16_t	Zombie::_total = 0;

void	Zombie::announce(void)
{
	std::cout << '<' << this->_name << " (" << this->_type << \
	")> wanna piece of you!" << std::endl;
}

Zombie::Zombie(void)
{
	std::cout << "	Creator: +1 zombie. total = " << ++Zombie::_total << std::endl;
    return;
}

Zombie::~Zombie(void)
{
	std::cout << "	Destructor: -1 zombie. total = " << --Zombie::_total << std::endl;
    return;
}

void	Zombie::set_name(std::string name)
{
	Zombie::_name = name;
}

void	Zombie::set_type(std::string type)
{
	Zombie::_type = type;
}
