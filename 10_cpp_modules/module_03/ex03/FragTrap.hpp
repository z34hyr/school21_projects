
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
		FragTrap(void);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(const FragTrap& obj);
		FragTrap& operator = (const FragTrap& obj);

		void			vaulthunter_dot_exe(std::string const & target);
		unsigned int	get_vault_exe_cost(void);
		void			set_vault_exe_cost(unsigned int vexe_cost);

	private:
		unsigned int	_vault_exe_cost;
};

#endif