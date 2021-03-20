
#include "Character.hpp"

Character::Character(void)
{
	_name = "default";
	_weapon = NULL;
	_action_point = 40;
	_max_action_point = 40;
	_is_killed = false;
	std::cout << "Character default created" << std::endl;
	return;
}

Character::Character(std::string const & name)
{
	_name = name;
	_weapon = NULL;
	_action_point = 40;
	_max_action_point = 40;
	_is_killed = false;
	std::cout << "Character " << GREEN << _name << RESET << " created" << std::endl;
	return;
}

Character::~Character(void)
{
	std::cout << "Character " << GREEN << _name << RESET <<  " RIP" << std::endl;
	return;
}

Character::Character(const Character& obj)
{
	_name = obj._name;
	_action_point = obj._action_point;
	_max_action_point = obj._max_action_point;
	_weapon = obj._weapon;
	return;
}

Character& Character::operator = (const Character& obj)
{
	_name = obj._name;
	_action_point = obj._action_point;
	_max_action_point = obj._max_action_point;
	_weapon = obj._weapon;
	return *this;
}

void	Character::recoverAP()
{
	if (_action_point + AP_RECOVER >= _max_action_point)
		_action_point = _max_action_point;
	else
	{
		_action_point += AP_RECOVER;
		std::cout << "Character AP has been recovered by 10" << std::endl;
	}

}

void Character::equip(AWeapon* weapon)
{
	_weapon = weapon;
}

void Character::attack(Enemy* enemy)
{
	if (_weapon && enemy != NULL && this->_weapon->getAPCost() <= this->_action_point)
	{
		this->_weapon->attack();
		_action_point -= ATTACK_COST;
		std::cout << GREEN << _name << RESET << " attacks " << RED << enemy->getType() << RESET << " with a " << this->_weapon->getName() << std::endl;
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() == 0)
		{
			delete enemy;
			enemy = NULL;
			_is_killed = true;
			std::cout << "Enemy destroyed!!" << std::endl;
		}
	}
	else if (_weapon == NULL)
		std::cout << GREEN << getName() << RESET << " is unarmed - can't attack" << std::endl;
	else if (this->_weapon->getAPCost() > this->_action_point)
		std::cout << getName() << " has not enough AP - can't attack" << std::endl;
	else
		std::cout << "NO ENEMY!" << std::endl;
}

std::string Character::getName() const
{
	return this->_name;
}

int Character::getAP() const
{
	return this->_action_point;
}

std::string Character::getWeaponType() const
{
	if (_weapon)
		return ("wields a " + this->_weapon->getName());
	else
		return "is unarmed";
}

// << operator overloader
std::ostream& operator << (std::ostream & z, const Character& obj)
{
	z << GREEN << obj.getName() << RESET << " has " << obj.getAP() << " AP and " << obj.getWeaponType() << std::endl;
	return (z);
}

void		Character::resetIsKilled()
{
	_is_killed = false;
}

bool		Character::getIsKilled()
{
	return _is_killed;
}