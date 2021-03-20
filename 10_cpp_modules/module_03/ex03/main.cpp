
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "	FragTrap:" << std::endl;
	FragTrap	a("Soldier");
	for (int i = 0; i < 6; i++)
	{
		std::cout << std::endl;
		a.vaulthunter_dot_exe("SomeBadGuy");
	}
	std::cout << std::endl;

	std::cout << "	ScavTrap:" << std::endl;
	ScavTrap b("Doorkeeper");
	b.meleeAttack("SomeGuy");
	for (int i = 0; i < 6; i++)
	{
		std::cout << std::endl;
		b.challengeNewcomer();
	}

	std::cout << std::endl;

	std::cout << "	NinjaTrap:" << std::endl;

	NinjaTrap	stranger("Kokos");
	ClapTrap	CL4PTRAP("Veniamin");

	stranger.ninjaShoebox(stranger);
	std::cout << std::endl;
	stranger.ninjaShoebox(CL4PTRAP);
	std::cout << std::endl;
	stranger.ninjaShoebox(a);
	std::cout << std::endl;
	stranger.ninjaShoebox(b);

}
