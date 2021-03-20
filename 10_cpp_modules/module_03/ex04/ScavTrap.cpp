
#include "ScavTrap.hpp"

std::string		welcome_phrases[5] = {"Hello newcomie!\n\
To pass this gate you should tell me a password.\n\
Not \"admin\", please, I heard it 2.000 times!", \
									"You can go but I'll stand here before the Rust comes!", \
									"Need some time to authorize your ugly face. Have I seen you before?", \
									"Go go Power Rangers! Sorry, I'm a big fan. Do you wanna pass?", \
									"What did you say? No way, you're right! The password is really \"admin\""};

ScavTrap::ScavTrap(void)
{
	set_max_hp(100);
	set_hp(100);
	set_name("basic");
	set_max_energy_point(50);
	set_enp(50);
	set_level(1);
	set_melee_damage(20);
	set_ranged_damage(15);
	set_ranged_energy_cost(10);
	set_melee_energy_cost(10);
	set_armor_reduction(3);
	std::cout << "Perfect FR4G-TP robot " << get_name() << " created" << std::endl;
	return;
}

ScavTrap::ScavTrap(std::string name)
{
	set_max_hp(100);
	set_hp(100);
	set_name(name);
	set_max_energy_point(50);
	set_enp(50);
	set_level(1);
	set_melee_damage(20);
	set_ranged_damage(15);
	set_ranged_energy_cost(10);
	set_melee_energy_cost(10);
	set_armor_reduction(3);

	std::cout << "Perfect SC4V-TP robot " << get_name() << " created" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << get_name() << " rotted in front of the door he guarded (ScavTrap)"  << std::endl;
	return;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& obj)
{
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
	return;
}

//assignment operator =
ScavTrap& ScavTrap::operator = (const ScavTrap& obj)
{
	std::cout << "Equaled to perfect soldier (ScavTrap)" << std::endl;
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
	return *this;
}

void	ScavTrap::challengeNewcomer(void)
{
	std::cout << welcome_phrases[rand() % 5] << "\n" << std::endl;
}