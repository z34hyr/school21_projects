
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	NinjaTrap	stranger("Kokos");
	ClapTrap	CL4PTRAP("Veniamin");
	FragTrap	FR4PTRAP("Boris");
	ScavTrap	SC4VTRAP("Alla");

	std::cout << std::endl;
	std::cout << "SUPERTRAP CREATION:" << std::endl;
	SuperTrap	Sup("Tundra");

	std::cout << "Name: " << Sup.get_name() << std::endl;
	std::cout << "Level: " << Sup.get_level() << std::endl;
	std::cout << "Energy point(s): "  << Sup.get_enp() << std::endl;
	std::cout << "Armor rduction: " << Sup.get_armor_reduction() << std::endl;
	std::cout << "HP: " << Sup.get_hp() << std::endl;
	std::cout << "Max HP: " << Sup.get_max_hp() << std::endl;
	std::cout << "Ranged damage: " << Sup.get_ranged_damage() << std::endl;
	std::cout << "Melee damage: " << Sup.get_melee_damage() << std::endl;
	std::cout << "Vault exe cost: " << Sup.get_vault_exe_cost() << std::endl;
	Sup.vaulthunter_dot_exe("Lol");
	Sup.ninjaShoebox(FR4PTRAP);
	Sup.ninjaShoebox(CL4PTRAP);
	Sup.ninjaShoebox(stranger);
	std::cout << "Setting hp = 200: " << std::endl;
	Sup.set_hp(200);
	std::cout << "Now hp: " << Sup.get_hp() << std::endl;
	Sup.set_max_hp(250);
	std::cout << "Now max hp: " << Sup.get_max_hp() << std::endl;
	Sup.set_hp(200);
	std::cout << "Now hp: " << Sup.get_hp() << std::endl;
}
