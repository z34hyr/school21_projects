
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

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
	for (int i = 0; i < 6; i++)
	{
		std::cout << std::endl;
		b.challengeNewcomer();
	}
}
