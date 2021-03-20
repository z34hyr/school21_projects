
#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
    public:
		HumanA(std::string name, Weapon& gun);
		~HumanA(void);

		void		attack(void);

	private:
		std::string	_name;
		Weapon& 	_my_gun; // looks like we left it unitialized! but it inits in Constructor function
};

#endif