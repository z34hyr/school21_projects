#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon	some_weapon = Weapon("some club");
		HumanA	new_warrior = HumanA("Boris", some_weapon);
		new_warrior.attack();
		some_weapon.setType("some other type of club");
		new_warrior.attack();
	}
	std::cout << "=========================" << std::endl;
	{
		Weapon	some_weapon = Weapon("some club");
		HumanB	new_warrior = HumanB("Evgen");
		new_warrior.setWeapon(some_weapon);
		new_warrior.attack();
		some_weapon.setType("some other type of club");
		new_warrior.attack();
	}
}
