
#include "Enemy.hpp"

Enemy::Enemy(void)
{
	_type = "default";
	_hp = 100;
	return;
}

Enemy::Enemy(int hp, std::string const & type)
{
	_hp = hp;
	_type = type;
	std::cout << "Enemy " << _type << " created" << std::endl;
	return;
}

Enemy::~Enemy(void)
{
	std::cout << "Enemy " << _type << " deleted" << std::endl;
	return;
}

Enemy::Enemy(const Enemy& obj)
{
	_hp = obj._hp;
	_type = obj._type;
	return;
}

Enemy& Enemy::operator = (const Enemy& obj)
{
	_hp = obj._hp;
	_type = obj._type;
	return *this;
}

std::string	Enemy::getType() const
{
	return this->_type;
}

int			Enemy::getHP(void) const
{
	return this->_hp;
}

void		Enemy::takeDamage(int damage)
{
	if (damage > 0)
	{
		if (damage > this->_hp)
			_hp = 0;
		else
			_hp -= damage;
	}
	std::cout << "Enemy has been attacked, now hp is " << _hp << std::endl;
}
