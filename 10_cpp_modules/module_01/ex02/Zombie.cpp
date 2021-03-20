
#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << '<' << this->_name << " (" << this->_type << \
	")> wanna piece of you!" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->set_name(name);
	std::cout << "	Creator: +1 zombie" << std::endl;
    return;
}

Zombie::~Zombie(void)
{
	std::cout << "	Destructor: -1 zombie" << std::endl;
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
