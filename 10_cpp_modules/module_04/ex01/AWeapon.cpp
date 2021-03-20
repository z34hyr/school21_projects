
#include "AWeapon.hpp"

AWeapon::AWeapon(void)
{
	return;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	_name = name;
	_damage = damage;
	_action_point_cost = apcost;
	return;
}

AWeapon::~AWeapon(void)
{
	return;
}

AWeapon::AWeapon(const AWeapon& obj)
{
	obj.getName();
	return;
}

AWeapon& AWeapon::operator= (const AWeapon& obj)
{
	obj.getName();
	return *this;
}

std::string	AWeapon::getName() const
{
	return this->_name;
}

int			AWeapon::getAPCost(void) const
{
	return this->_action_point_cost;
}

int			AWeapon::getDamage(void) const
{
	return this->_damage;
}
