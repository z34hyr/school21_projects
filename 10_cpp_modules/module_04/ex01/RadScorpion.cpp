
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void)
{
	_type = "RasScorpion";
	this->_hp = 80;
	std::cout << "* click click click *" << std::endl;
	return;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" << std::endl;
	return;
}

RadScorpion::RadScorpion(const RadScorpion& obj)
{
	_hp = obj._hp;
	_type = obj._type;
	return;
}

RadScorpion& RadScorpion::operator = (const RadScorpion& obj)
{
	_hp = obj._hp;
	_type = obj._type;
	return *this;
}
