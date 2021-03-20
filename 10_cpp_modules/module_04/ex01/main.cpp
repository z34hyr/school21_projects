
#include "AWeapon.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int main()
{
	Character* me = new Character("me");
	std::cout << *me;
	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	//me->equip(pr);
	std::cout << *me;
	me->attack(b);
	me->equip(pr);
	me->attack(b);
	std::cout << *me;
	while (b)
	{
		me->attack(b);
		if (me->getIsKilled())
		{
			b = NULL;
			me->resetIsKilled();
		}
		std::cout << *me;
	}
	me->equip(pf);
	while (c)
	{
		me->recoverAP();
		std::cout << *me;
		me->attack(c);
		if (me->getIsKilled())
		{
			c = NULL;
			me->resetIsKilled();
		}
	}
	std::cout << *me;
	delete me;
	delete pr;
	delete pf;
	delete c;
}
