
#include "Pony.hpp"

uint16_t		Pony::_ponies_counter = 0;

Pony::Pony(void)
{
	std::cout << "	Creator: +1 pony" << std::endl;
	Pony::add_pony();
	return;
}

Pony::~Pony(void)
{
	std::cout << "	Destroyer: -1 pony" << std::endl;
	Pony::delete_pony();
	return;
}

void	Pony::add_pony(void)
{
	Pony::_ponies_counter += 1;
}

void	Pony::delete_pony(void)
{
	if (Pony::_ponies_counter > 0)
		Pony::_ponies_counter -= 1;
	else
		std::cout << "no more ponies! can't delete!" << std::endl;
}

uint16_t	Pony::get_counter(void)
{
	return (Pony::_ponies_counter);
}
