
#include "Squad.hpp"

Squad::Squad()
{
	std::cout << MAGENTA << "New Squad created" << RESET << std::endl;
	_squad = NULL;
	_count = 0;
	return;
}

Squad::~Squad()
{
	std::cout << "Destroyer:" << std::endl;
	for (int i = 0; i < _count; i++)
	{
		delete this->_squad[i];
		this->_squad[i] = NULL;
	}
	if (_squad)
	{
		delete[] this->_squad;
		this->_squad = NULL;
	}
	std::cout << MAGENTA << "Squad destroyed" << RESET << std::endl;
	return;
}

Squad::Squad(const Squad& squad)
{
	_count = 0;
	_squad = NULL;
	this->operator=(squad);
	return;
}

Squad& Squad::operator = (const Squad& squad)
{
	std::cout << "==Assignation operator overloader==" << std::endl;
	if (this == &squad)
		return *this;
	if (this->_squad)
	{
		for (int i = 0; i < this->_count; i++)
		{
			delete this->_squad[i];
			this->_squad[i] = NULL;
		}
		this->_count = 0;
		delete[] this->_squad;
		this->_squad = NULL;
	}
	if (squad.getCount() > 0)
	{
		for (int i = 0; i < squad.getCount(); i++)
			this->push(squad._squad[i]->clone());
	}
	return *this;
}

int	Squad::getCount() const
{
	return _count;
}

ISpaceMarine*	Squad::getUnit(int N) const
{
	if (_count > 0 && N >= 0 && _count >= N + 1)
		return _squad[N];
	else if (N < 0)
		std::cout << "Wrong request (N < 0)" << std::endl;
	else if (_count == 0)
		std::cout << "Squad is empty" << std::endl;
	else if (_count < N + 1)
		std::cout << "There is less units in the squad than N" << std::endl;
	return NULL;
}

int				Squad::push(ISpaceMarine* new_unit)
{
	if (_squad && new_unit)
	{
		for (int i = 0; i < _count; i++)
		{
			if (_squad[i] == new_unit)
			{
				std::cout << "This fighter is already in our squad!" << std::endl;
				return _count;
			}
		}
	}
	else if (!new_unit)
	{
		std::cout << "You're trying to add non-existing unit" << std::endl;
		return _count;
	}
	ISpaceMarine** temp = new ISpaceMarine*[_count + 1];
	if (_squad)
	{
		for (int i = 0; i < _count; i++)
			temp[i] = _squad[i];
		delete[] _squad;
		_squad = NULL;
	}
	++_count;
	temp[_count - 1] = new_unit;
	temp[_count - 1]->battleCry();

	_squad = temp;
	std::cout << "Added. Count = " << this->getCount() << std::endl;
	return _count;
}
