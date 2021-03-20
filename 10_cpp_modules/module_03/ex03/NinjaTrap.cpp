
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void)
{
	return;
}

NinjaTrap::NinjaTrap(std::string name)
{
	set_max_hp(60);
	set_hp(60);
	set_name(name);
	set_max_energy_point(120);
	set_enp(120);
	set_level(1);
	set_melee_damage(60);
	set_ranged_damage(5);
	set_ranged_energy_cost(10);
	set_melee_energy_cost(10);
	set_armor_reduction(0);

	std::cout << "Perfect Ninja robot " << this->_name << " created" << std::endl;
	return;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << this->_name << " rotted in the dustbin of the universe"  << std::endl;
	return;
}

// copy constructor
NinjaTrap::NinjaTrap(const NinjaTrap& obj)
{
	std::cout << "Made a perfect copy of perfect soldier (NinjaTrap)" << std::endl;
	set_name(obj.get_name() + "_copy");
	set_max_hp(obj.get_max_hp());
	set_hp(obj.get_hp());
	set_max_energy_point(obj.get_max_energy_point());
	set_enp(obj.get_enp());
	set_level(obj.get_level());
	set_melee_damage(obj.get_melee_damage());
	set_ranged_damage(obj.get_ranged_damage());
	set_melee_energy_cost(obj.get_melee_energy_cost());
	set_ranged_energy_cost(obj.get_ranged_energy_cost());
	set_armor_reduction(obj.get_armor_reduction());
	return;
}

//assignment operator =
NinjaTrap& NinjaTrap::operator = (const NinjaTrap& obj)
{
	std::cout << "Equaled to perfect soldier (NinjaTrap)" << std::endl;
	std::cout << "Made a perfect copy of perfect soldier (ScavTrap)" << std::endl;
	set_name(obj.get_name() + "_copy");
	set_max_hp(obj.get_max_hp());
	set_hp(obj.get_hp());
	set_max_energy_point(obj.get_max_energy_point());
	set_enp(obj.get_enp());
	set_level(obj.get_level());
	set_melee_damage(obj.get_melee_damage());
	set_ranged_damage(obj.get_ranged_damage());
	set_melee_energy_cost(obj.get_melee_energy_cost());
	set_ranged_energy_cost(obj.get_ranged_energy_cost());
	set_armor_reduction(obj.get_armor_reduction());
	return *this;
}

void	NinjaTrap::ninjaShoebox(const ClapTrap& obj)
{
	std::cout << "Ninja now mimics ClapTrap object:" << std::endl;
	std::cout << "Hi! My name is " << obj.get_name() << std::endl;
}

void	NinjaTrap::ninjaShoebox(const NinjaTrap& obj)
{
	std::cout << "Ninja now mimics NinjaTrap object:" << std::endl;
	std::cout << "Hi! My name is " << obj.get_name() << std::endl;
}

void	NinjaTrap::ninjaShoebox(const FragTrap& obj)
{
	std::cout << "Ninja now mimics FragTrap object:" << std::endl;
	std::cout << "Hi! My name is " << obj.get_name() << std::endl;
}

void	NinjaTrap::ninjaShoebox(const ScavTrap& obj)
{
	std::cout << "Ninja now mimics ScavTrap object:" << std::endl;
	std::cout << "Hi! My name is " << obj.get_name() << std::endl;
}
