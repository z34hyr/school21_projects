
#include "PowerFist.hpp"

PowerFist::PowerFist(void)
{
	_name = "Power Fist";
	_damage = 50;
	_action_point_cost = 8;
	return;
}

PowerFist::~PowerFist(void)
{
	return;
}

PowerFist::PowerFist(const PowerFist& obj)
{
	_name = obj._name + "_copy";
	_action_point_cost = obj._action_point_cost;
	_damage = obj._damage;
	return;
}

PowerFist& PowerFist::operator = (const PowerFist& obj)
{
	_name = obj._name + "_assign";
	_action_point_cost = obj._action_point_cost;
	_damage = obj._damage;
	return *this;
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}