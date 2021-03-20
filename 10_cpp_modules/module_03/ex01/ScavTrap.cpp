
#include "ScavTrap.hpp"

std::string		welcome_phrases[5] = {"Hello newcomie!\n\
To pass this gate you should tell me a password.\n\
Not \"admin\", please, I heard it 2.000 times!", \
									"You can go but I'll stand here before the Rust comes!", \
									"Need some time to authorize your ugly face. Have I seen you before?", \
									"Go go Power Rangers! Sorry, I'm a big fan. Do you wanna pass?", \
									"What did you say? No way, you're right! The password is really \"admin\""};

ScavTrap::ScavTrap(std::string name) : _name(name)
{
	std::cout << "Perfect SC4V-TP robot " << this->_name << " created" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->_name << " rotted in front of the door he guarded"  << std::endl;
	return;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& obj)
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
	return;
}

//assignment operator =
ScavTrap& ScavTrap::operator = (const ScavTrap& obj)
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

void	ScavTrap::takeDamage(unsigned int amount)
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

void	ScavTrap::beRepaired(unsigned int amount)
{
	unsigned int temp = this->_hp;

	this->_hp += amount;
	if (this->_hp > this->_max_hp)
		this->_hp = this->_max_hp;
	std::cout << this->_name << ": " << this->_hp - temp << " HP repaired, now hp = " \
	<< this->_hp << std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	
	std::cout << "SC4V-TP " << this->_name << " attacks " << target << \
	" by bow shot, causing " << this->_ranged_damage << " points of damage!" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	if (this->_enp >= this->_melee_energy_cost)
	{
		std::cout << "SC4V-TP " << this->_name << " hits " << target << \
		" in the face, causing " << this->_melee_damage << " points of damage!" << std::endl;
		this->_enp -= this->_melee_energy_cost;
	}
	else
		std::cout << "I have no power of will to touch him, need " << \
		this->_melee_energy_cost - this->_enp << " energy point(s)" << std::endl;
}

void	ScavTrap::challengeNewcomer(void)
{
	std::cout << welcome_phrases[rand() % 5] << "\n" << std::endl;
}