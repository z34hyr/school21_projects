
#include "FragTrap.hpp"

std::string		attack_pool[5] = {"Blight Bot", "Funzerking", "Mechromagician", "Meat Unicycle", "Shhhhhhhhhhh...trap"};

FragTrap::FragTrap(void)
{
	std::cout << "Perfect FR4G-TP robot " << get_name() << " created" << std::endl;
	return;
}

FragTrap::FragTrap(std::string name)
{
	set_max_hp(100);
	set_hp(100);
	set_name(name);
	this->set_max_energy_point(100);
	this->set_enp(100);
	set_level(1);
	set_melee_damage(30);
	set_ranged_damage(20);
	set_ranged_energy_cost(10);
	set_melee_energy_cost(10);
	set_armor_reduction(5);

	set_vault_exe_cost(25);
	std::cout << "Perfect FR4G-TP robot " << get_name() << " created" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->get_name() << " rotted in the dustbin of the universe (FragTrap)"  << std::endl;
	return;
}

// copy constructor
FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "Made a perfect copy of perfect soldier (FragTrap)" << std::endl;
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

	set_vault_exe_cost(get_vault_exe_cost());
	return;
}

//assignment operator =
FragTrap& FragTrap::operator = (const FragTrap& obj)
{
	std::cout << "Equaled to perfect soldier (FragTrap)" << std::endl;
	set_name(obj.get_name() + "_assigned");
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

	set_vault_exe_cost(get_vault_exe_cost());
	return *this;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (get_enp() >= get_vault_exe_cost())
	{
		//rnd attack
		std::cout << "The universe chose \"" << attack_pool[std::rand() % 5] << "\" attack on " << target << std::endl;
		set_hp(get_max_energy_point());
		set_enp(get_enp() - get_vault_exe_cost());
	}
	else
		std::cout << get_name() << " have no power of will to touch " << target << ", need " << \
		get_vault_exe_cost() - get_enp() << " energy point(s)" << std::endl;
}

void	FragTrap::set_vault_exe_cost(unsigned int vexe_cost)
{
	_vault_exe_cost = vexe_cost;
}

unsigned int	FragTrap::get_vault_exe_cost(void)
{
	return(_vault_exe_cost);
}