
#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include <iostream>
# include <string>
#include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap: public virtual NinjaTrap, public virtual FragTrap
{
    public:
		SuperTrap(void);
		SuperTrap(std::string name);;
		SuperTrap(const SuperTrap& obj);
		SuperTrap& operator = (const SuperTrap& obj);
		~SuperTrap(void);
};

#endif