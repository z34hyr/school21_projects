
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	_count = 0;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << "MateriaSource created" << std::endl;
	return;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destroyed" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
	_count = 0;
	return;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	this->operator=(obj);
	return;
}

MateriaSource& MateriaSource::operator = (const MateriaSource& obj)
{
	std::cout << "Materia assignation: " << std::endl;
	if (this != &obj)
	{
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

void MateriaSource::learnMateria(AMateria* m)
{
	if (_count < 4 && m)
	{
		_inventory[_count] = m->clone();
		_count += 1;
	}
	else
		std::cout << "No empty slots!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i]->getType() == type)
		{
			std::cout << "FOUND! type = " << this->_inventory[i]->getType() << std::endl;
			AMateria* materia = this->_inventory[i]->clone();
			return materia;
		}
	}
	std::cout << "can't find this type" << std::endl;
	return NULL;
}
