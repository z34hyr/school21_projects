
#include "ZombieHorde.hpp"

std::string ZombieHorde::_name_pool[10] = {"Alex", "Boris", "Igor", "Sergey", "Kesha", \
		"Natasha", "Katerina", "Lena", "Nastasya", "Olga"};

ZombieHorde::ZombieHorde(int N)
{
	this->_ZombiePack = new Zombie[N];
	this->_number = N;
	for (int i = 0; i < N; i++)
	{
		_ZombiePack[i].set_name(_name_pool[std::rand() % 10]);
		_ZombiePack[i].set_type("horde pack");
	}
    return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] _ZombiePack;
	return;
}

void	ZombieHorde::announce(void)
{
	for (int i = 0; i < _number; i++)
		_ZombiePack[i].announce();
}
