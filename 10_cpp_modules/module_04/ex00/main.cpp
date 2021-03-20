
#include <string>
#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "BargeHaule.hpp"

int main()
{
	Sorcerer robert("Robert", "the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	BargeHaule ivan("Ivan");
	std::cout << robert << jim << joe << ivan;
	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(ivan);
}