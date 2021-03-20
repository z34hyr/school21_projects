
#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
    public:
		HumanB(std::string name);
		~HumanB(void);

		void		attack(void);
		void 		setWeapon(Weapon& weapon_type);

	private:
		std::string	_name;
		Weapon* 	_my_gun;
};

#endif