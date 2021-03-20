
#include "Character.hpp"

Character::Character(void)
{
	return;
}

Character::Character(std::string const & name)
{
	_count = 0;
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << MAGENTA << _name << RESET << " character created" << std::endl;
	return;
}

Character::~Character(void)
{
	
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		_count = 0;
	}
	std::cout << MAGENTA << _name << RESET << " character deleted" << std::endl;
	return;
}

Character::Character(const Character& obj)
{
	std::cout << "Character copy: " << std::endl;
	this->operator=(obj);
	return;
}

Character& Character::operator = (const Character& obj)
{
	std::cout << "Character assignation: " << std::endl;
	if (this != &obj)
	{
		_name = obj.getName();
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (obj._inventory[i])
			{
				_inventory[i] = obj._inventory[i]->clone();
				_count += 1;
			}
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL || _count == 4)
		std::cout << "Can't equip" << std::endl;
	else
	{
		_inventory[_count++] = m;
		std::cout << MAGENTA << _name << RESET << " equiped with " << CYAN << m->getType() << ", count = " << _count << std::endl;
	}
	return;
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		std::cout << "Wrong idx" << std::endl;
	else if (_inventory[idx] == NULL)
		std::cout << "Slot is already unequiped" << std::endl;
	else
	{
		_inventory[idx] = NULL;
		_count -= 1;
		while (idx < _count)
		{
			_inventory[idx] = _inventory[idx + 1];
			_inventory[idx + 1] = NULL;
			idx += 1;
		}
		std::cout << "Unequiped, also shifted left" << std::endl;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		std::cout << "Wrong idx" << std::endl;
	else if (idx > _count - 1)
		std::cout << "Can't use - empty slot" << std::endl;
	else
		_inventory[idx]->use(target);
}
