
#include "FragTrap.hpp"

std::string		attack_pool[5] = {"Blight Bot", "Funzerking", "Mechromagician", "Meat Unicycle", "Shhhhhhhhhhh...trap"};

FragTrap::FragTrap(std::string name) : _name(name)
{
	std::cout << "Perfect FR4G-TP robot " << this->_name << " created" << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->_name << " rotted in the dustbin of the universe"  << std::endl;
	return;
}

// copy constructor
FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "Made a perfect copy of perfect soldier" << std::endl;
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
	_vault_exe_cost = obj._vault_exe_cost;
	return;
}

//assignment operator =
FragTrap& FragTrap::operator = (const FragTrap& obj)
{
	std::cout << "Equaled to perfect soldier" << std::endl;
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
	_vault_exe_cost = obj._vault_exe_cost;
	return *this;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	unsigned int temp = this->_hp;

	this->_hp += this->_armor_reduction;
	if (this->_hp >= amount)
		this->_hp -= amount;
	else
		this->_hp = 0;
	std::cout << this->_name << ": " << temp - this->_hp << " damage taken, now hp = "\
	<< this->_hp << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	unsigned int temp = this->_hp;

	this->_hp += amount;
	if (this->_hp > this->_max_hp)
		this->_hp = this->_max_hp;
	std::cout << this->_name << ": " << this->_hp - temp << " HP repaired, now hp = " \
	<< this->_hp << std::endl;
}

void	FragTrap::rangedAttack(std::string const & target)
{
	
	std::cout << "FR4G-TP " << this->_name << " attacks " << target << \
	" by bow shot, causing " << this->_ranged_damage << " points of damage!" << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	if (this->_enp >= this->_melee_energy_cost)
	{
		std::cout << "FR4G-TP " << this->_name << " hits " << target << \
		" in the face, causing " << this->_melee_damage << " points of damage!" << std::endl;
		this->_enp -= this->_melee_energy_cost;
	}
	else
		std::cout << "I have no power of will to touch him, need " << \
		this->_melee_energy_cost - this->_enp << " energy point(s)" << std::endl;
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	if (this->_enp >= this->_vault_exe_cost)
	{
		//rnd attack
		std::cout << "The universe chose \"" << attack_pool[std::rand() % 5] << "\" attack on " << target << std::endl;
		this->_hp = this->_max_hp;
		this->_enp -= this->_vault_exe_cost;
	}
	else
		std::cout << this->_name << " have no power of will to touch " << target << ", need " << \
		this->_vault_exe_cost - this->_enp << " energy point(s)" << std::endl;
}
