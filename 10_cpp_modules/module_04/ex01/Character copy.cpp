
#include "Character.hpp"

Character::Character(void)
{
	_name = "default";
	_weapon = NULL;
	_action_point = 40;
	std::cout << "Character default created" << std::endl;
	return;
}

Character::Character(std::string const & name)
{
	_name = name;
	_weapon = NULL;
	_action_point = 40;
	std::cout << "Character " << _name << " created" << std::endl;
	return;
}

Character::~Character(void)
{
	std::cout << "Character " << _name <<  " RIP" << std::endl;
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
	if (_action_point + 10 >= _max_action_point)
		_action_point = _max_action_point;
	else
		_action_point += 10;
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
		std::cout << _name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
		enemy->takeDamage(this->_weapon->getDamage());
		if (enemy->getHP() == 0)
		{
			delete enemy;
			enemy = NULL;
			std::cout << "Enemy destroyed!!" << std::endl;
		}
	}
	else if (_weapon == NULL)
		std::cout << getName() << " is unarmed" << std::endl;
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
	z << obj.getName() << " has " << obj.getAP() << " AP and " << obj.getWeaponType() << std::endl;
	return (z);
}
