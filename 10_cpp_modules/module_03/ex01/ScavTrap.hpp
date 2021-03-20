
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>

class ScavTrap
{
    public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(const ScavTrap& obj);
		ScavTrap& operator = (const ScavTrap& obj);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer(void);

	private:
		unsigned int			_hp = 100;
		unsigned int			_max_hp = 100;
		unsigned int			_enp = 50;
		unsigned int			_max_energy_point = 50;
		unsigned int			_level = 1;
		std::string				_name;
		unsigned int			_melee_damage = 20;
		unsigned int			_ranged_damage = 15;
		unsigned int			_armor_reduction = 3;

		unsigned int			_melee_energy_cost = 10;
		unsigned int			_ranged_energy_cost = 10;
		unsigned int 			_vault_exe_cost = 25;
};

#endif