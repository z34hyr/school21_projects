
#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap: public virtual ClapTrap
{
    public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		~NinjaTrap(void);
		NinjaTrap(const NinjaTrap& obj);
		NinjaTrap& operator = (const NinjaTrap& obj);

		void	ninjaShoebox(const ClapTrap& obj);
		void	ninjaShoebox(const NinjaTrap& obj);
		void	ninjaShoebox(const FragTrap& obj);
		void	ninjaShoebox(const ScavTrap& obj);

};

#endif