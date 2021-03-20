
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << CYAN << "* teleports from space *" << RESET << std::endl;
	return;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << CYAN << "I’ll be back..." << RESET << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator& term)
{
	term.battleCry();
	return;
}
	
AssaultTerminator& AssaultTerminator::operator = (const AssaultTerminator& term)
{
	term.battleCry();
	return *this;
}

void	AssaultTerminator::battleCry() const
{
	std::cout << CYAN << "This code is unclean. PURIFY IT!" << RESET << std::endl;
}

void	AssaultTerminator::rangedAttack() const
{
	std::cout << CYAN << "* does nothing *" << RESET << std::endl;
}

void	AssaultTerminator::meleeAttack() const
{
	std::cout << CYAN << "* attacks with chainfists *" << RESET << std::endl;
}

ISpaceMarine* AssaultTerminator::clone() const
{
	ISpaceMarine*	copy = new AssaultTerminator();
	return copy;
}