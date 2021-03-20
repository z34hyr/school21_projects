
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void)
{
	_type = "Super Mutant";
	this->_hp = 170;
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh..." << std::endl;
	return;
}

SuperMutant::SuperMutant(const SuperMutant& obj)
{
	_hp = obj._hp;
	_type = obj._type;
	return;
}

SuperMutant& SuperMutant::operator = (const SuperMutant& obj)
{
	_hp = obj._hp;
	_type = obj._type;
	return *this;
}

void		SuperMutant::takeDamage(int damage)
{
	damage -= 3;
	if (damage > 0)
	{
		if (damage > this->_hp)
			_hp = 0;
		else
			_hp -= damage;
	}
	std::cout << "Enemy has been attacked, now hp is " << _hp << std::endl;
}
