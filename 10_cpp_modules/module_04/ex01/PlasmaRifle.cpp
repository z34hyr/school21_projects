
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void)
{
	_name = "Plasma Rifle";
	_damage = 21;
	_action_point_cost = 5;
	return;
}

PlasmaRifle::~PlasmaRifle(void)
{
	return;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle& obj)
{
	_name = obj._name + "_copy";
	_action_point_cost = obj._action_point_cost;
	_damage = obj._damage;
	return;
}

PlasmaRifle& PlasmaRifle::operator = (const PlasmaRifle& obj)
{
	_name = obj._name + "_assign";
	_action_point_cost = obj._action_point_cost;
	_damage = obj._damage;
	return *this;
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}