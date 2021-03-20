
#include <string>
#include <iostream>
#include "TacticalMarine.hpp"
#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

int main()
{
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISquad* vlc = new Squad;
	vlc->push(bob);
	vlc->push(jim);
	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	Squad* my_squad = new Squad;
	ISpaceMarine* jack = new TacticalMarine;
	ISpaceMarine* josh = new TacticalMarine;
	ISpaceMarine* zack = new AssaultTerminator;
	ISpaceMarine* zohan = new AssaultTerminator;
	ISpaceMarine* zahar = new AssaultTerminator;

	my_squad->push(jack);
	my_squad->push(josh);
	my_squad->push(zack);
	my_squad->push(zohan);
	my_squad->push(zahar);
	my_squad->push(jack);
	my_squad->push(NULL);
	my_squad->getUnit(3)->battleCry();
}