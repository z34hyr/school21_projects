
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>

class FragTrap
{
    public:
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(const FragTrap& obj);
		FragTrap& operator = (const FragTrap& obj);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	vaulthunter_dot_exe(std::string const & target);

	private:
		unsigned int			_hp = 100;
		unsigned int			_max_hp = 100;
		unsigned int			_enp = 100;
		unsigned int			_max_energy_point = 100;
		unsigned int			_level = 1;
		std::string				_name;
		unsigned int			_melee_damage = 30;
		unsigned int			_ranged_damage = 20;
		unsigned int			_armor_reduction = 5;

		unsigned int			_melee_energy_cost = 10;
		unsigned int			_ranged_energy_cost = 10;
		unsigned int 			_vault_exe_cost = 25;
};

#endif