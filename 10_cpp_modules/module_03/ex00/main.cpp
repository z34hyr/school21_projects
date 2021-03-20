
#include "FragTrap.hpp"

int main(void)
{
		FragTrap first_one("Babai");
		FragTrap first_one_copy(first_one);
		FragTrap assign = first_one;
		first_one.takeDamage(30);
		first_one.beRepaired(11);
		first_one.rangedAttack("Kolobok");
		first_one.meleeAttack("Krastan");
		first_one.takeDamage(100);
		first_one.takeDamage(10);
		first_one_copy.takeDamage(10);
		for (int i = 0; i < 6; i++)
		{
			first_one_copy.vaulthunter_dot_exe("Zombie");
			std::cout << std::endl;
		}
}
