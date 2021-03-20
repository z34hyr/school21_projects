
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		std::cout << "	FragTrap class:" << std::endl;
		FragTrap first_one("Babai");
		FragTrap another("Barbie");
		FragTrap first_one_copy(first_one);
		for (int i = 0; i < 2; i++)
		{
			first_one.takeDamage(30);
			first_one.beRepaired(11);
			first_one.rangedAttack("Kolobok");
			first_one.meleeAttack("Krastan");
		}
		first_one_copy.takeDamage(10);
		first_one_copy.vaulthunter_dot_exe("Zombie");
	}

	{
		std::cout << "	ScavTrap class:" << std::endl;
		ScavTrap gatekeeper("GoalKeeper");
		for (int i = 0; i < 5; i++)
			gatekeeper.challengeNewcomer();
	}
}