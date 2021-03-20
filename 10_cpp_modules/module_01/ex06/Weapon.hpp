//Make a Weapon class, that has a type string, and a getType that returns a const
//reference to this string. Also has a setType.

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
    public:
		Weapon(std::string weapon_type);
		~Weapon(void);
		void			setType(std::string type);
		std::string 	const &	getType();
	private:
		std::string		_type;

};

#endif