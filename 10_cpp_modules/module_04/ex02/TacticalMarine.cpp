
#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
	std::cout << GREEN << "Tactical Marine ready for battle!" << RESET << std::endl;
	return;
}

TacticalMarine::~TacticalMarine()
{
	std::cout << GREEN << "Aaargh..." << RESET << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine& marine)
{
	marine.battleCry();
	return;
}
	
TacticalMarine& TacticalMarine::operator = (const TacticalMarine& marine)
{
	marine.battleCry();
	return *this;
}

void	TacticalMarine::battleCry() const
{
	std::cout << GREEN << "For the holy PLOT!" << RESET << std::endl;
}

void	TacticalMarine::rangedAttack() const
{
	std::cout << GREEN << "* attacks with a bolter *" << RESET << std::endl;
}

void	TacticalMarine::meleeAttack() const
{
	std::cout << GREEN << "* attacks with a chainsword *" << RESET << std::endl;
}

ISpaceMarine* TacticalMarine::clone() const
{
	ISpaceMarine*	copy = new TacticalMarine();
	return copy;
}