
#include "SuperTrap.hpp"

SuperTrap::SuperTrap(void) : NinjaTrap(), FragTrap()
{
	std::cout << "Hello" << std::endl;
	//this->_hp = FragTrap::get_hp();
	return;
}

SuperTrap::SuperTrap(std::string name) : NinjaTrap(), FragTrap()
{
	std::cout << "SuperTrap object created" << std::endl;
	this->set_name(name);
	FragTrap::set_max_hp(100);
	FragTrap::set_hp(100);
	NinjaTrap::set_max_energy_point(120);
	NinjaTrap::set_enp(120);
	this->set_level(1);
	NinjaTrap::set_melee_damage(60);
	FragTrap::set_ranged_damage(20);
	FragTrap::set_ranged_energy_cost(10);
	NinjaTrap::set_melee_energy_cost(10);
	FragTrap::set_armor_reduction(5);
	FragTrap::set_vault_exe_cost(25);
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << SuperTrap::get_name() << " rotted in the dustbin of the universe (SuperTrap)"  << std::endl;
	//std::cout << "_hp: " << this->_hp << std::endl;
	return;
}

// copy constructor
SuperTrap::SuperTrap(const SuperTrap& obj)
{
	std::cout << "	SuperTrap object copy function called" << std::endl;
	_name = obj._name + "_copy";
	_hp = obj._hp;
	_max_hp = obj._max_hp;
	_enp = obj._enp;
	_max_energy_point = obj._max_energy_point;
	_level = obj._level;
	_melee_damage = obj._melee_damage;
	_ranged_damage = obj._ranged_damage;
	_armor_reduction = obj._armor_reduction;
	_melee_energy_cost = obj._melee_energy_cost;
	_ranged_energy_cost = obj._ranged_energy_cost;
	return;
}

//assignment operator =
SuperTrap& SuperTrap::operator = (const SuperTrap& obj)
{
	std::cout << "Equaled to perfect soldier (SuperTrap)" << std::endl;
	_name = obj._name + "_copy";
	_hp = obj._hp;
	_max_hp = obj._max_hp;
	_enp = obj._enp;
	_max_energy_point = obj._max_energy_point;
	_level = obj._level;
	_melee_damage = obj._melee_damage;
	_ranged_damage = obj._ranged_damage;
	_armor_reduction = obj._armor_reduction;
	_melee_energy_cost = obj._melee_energy_cost;
	_ranged_energy_cost = obj._ranged_energy_cost;
	return *this;
}
