
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "	Parent class (ClapTrap) constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	set_name(name);
	std::cout << "	" << get_name() << " - Parent class (ClapTrap) constructor (named) called" << std::endl;
	return;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "	" << get_name() << " - Parent class (ClapTrap) destructor called"  << std::endl;
	return;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "	ClapTrap object copy function called" << std::endl;
	_name = obj.get_name() + "_copy";
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
ClapTrap& ClapTrap::operator = (const ClapTrap& obj)
{
	std::cout << "ClapTrap assignment operator function called" << std::endl;
	_name = obj.get_name() + "_assign";
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int temp = get_hp();

	_hp += _armor_reduction;
	if (_hp >= amount)
		_hp -= amount;
	else
		set_hp(0);
	std::cout << get_name() << ": " << temp - get_hp() << " damage taken, now hp = "\
	<< get_hp() << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	unsigned int temp = this->_hp;

	_hp += amount;
	if (_hp > _max_hp)
		_hp = _max_hp;
	std::cout << _name << ": " << get_hp() - temp << " HP repaired, now hp = " \
	<< _hp << std::endl;
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	
	std::cout << _name << " attacks " << target << \
	" by bow shot, causing " << _ranged_damage << " point(s) of damage!" << std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	if (_enp >= _melee_energy_cost)
	{
		std::cout << _name << " hits " << target << \
		" in the face, causing " << _melee_damage << " point(s) of damage!" << std::endl;
		_enp -= _melee_energy_cost;
	}
	else
		std::cout << "I have no power of will to touch him, need " << \
		get_melee_energy_cost() - get_enp() << " energy point(s)" << std::endl;
}

unsigned int	ClapTrap::get_hp(void) const
{
	return(this->_hp);
}

unsigned int	ClapTrap::get_level(void) const
{
	return(this->_level);
}

unsigned int	ClapTrap::get_armor_reduction(void) const
{
	return(this->_armor_reduction);
}

unsigned int	ClapTrap::get_enp(void) const
{
	return(this->_enp);
}

unsigned int	ClapTrap::get_max_energy_point(void) const
{
	return(this->_max_energy_point);
}

unsigned int	ClapTrap::get_max_hp(void) const
{
	return(this->_max_hp);
}

unsigned int	ClapTrap::get_melee_damage(void) const
{
	return(this->_melee_damage);
}

unsigned int	ClapTrap::get_melee_energy_cost(void) const
{
	return(this->_melee_energy_cost);
}

std::string		ClapTrap::get_name(void) const
{
	return(this->_name);
}

unsigned int	ClapTrap::get_ranged_damage(void) const
{
	return(this->_ranged_damage);
}

unsigned int	ClapTrap::get_ranged_energy_cost(void) const
{
	return(this->_ranged_energy_cost);
}

void			ClapTrap::set_hp(unsigned int hp)
{
	if (hp <= get_max_hp())
		_hp = hp;
	else
		_hp = get_max_hp();
}

void			ClapTrap::set_max_hp(unsigned int max_hp)
{
	_max_hp = max_hp;
}

void			ClapTrap::set_armor_reduction(unsigned int red)
{
	_armor_reduction = red;
}

void			ClapTrap::set_enp(unsigned int enp)
{
	if (enp <= get_max_energy_point())
		_enp = enp;
	else
		_enp = get_max_energy_point();
}

void			ClapTrap::set_max_energy_point(unsigned int max_enp)
{
	_max_energy_point = max_enp;
}

void			ClapTrap::set_level(unsigned int level)
{
	_level = level;
}

void			ClapTrap::set_melee_damage(unsigned int melee_damage)
{
	_melee_damage = melee_damage;
}

void			ClapTrap::set_ranged_damage(unsigned int ranged_damage)
{
	_ranged_damage = ranged_damage;
}

void			ClapTrap::set_melee_energy_cost(unsigned int melee_energy_cost)
{
	_melee_energy_cost = melee_energy_cost;
}

void			ClapTrap::set_ranged_energy_cost(unsigned int ranged_energy_cost)
{
	_ranged_energy_cost = ranged_energy_cost;
}

void			ClapTrap::set_name(std::string name)
{
	_name = name;
}
