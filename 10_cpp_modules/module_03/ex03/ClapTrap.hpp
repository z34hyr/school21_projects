
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
		ClapTrap(void);
		ClapTrap(std::string name);
		~ClapTrap(void);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator = (const ClapTrap& obj);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		unsigned int	get_hp(void) const;
		unsigned int	get_max_hp(void) const;
		unsigned int	get_enp(void) const;
		unsigned int	get_max_energy_point(void) const;
		unsigned int	get_level(void) const;
		std::string		get_name(void) const;
		unsigned int	get_melee_damage(void) const;
		unsigned int	get_ranged_damage(void) const;
		unsigned int	get_armor_reduction(void) const;
		unsigned int	get_melee_energy_cost(void) const;
		unsigned int	get_ranged_energy_cost(void) const;

		void			set_hp(unsigned int hp);
		void			set_max_hp(unsigned int max_hp);
		void			set_enp(unsigned int enp);
		void			set_max_energy_point(unsigned int max_en_p);
		void			set_level(unsigned int level);
		void			set_name(std::string name);
		void			set_melee_damage(unsigned int melee_damage);
		void			set_ranged_damage(unsigned int ranged_damage);
		void			set_armor_reduction(unsigned int armor_reduction);
		void			set_melee_energy_cost(unsigned int melee_energy_cost);
		void			set_ranged_energy_cost(unsigned int ranged_energy_cost);

	protected:
		unsigned int			_hp;
		unsigned int			_max_hp;
		unsigned int			_enp;
		unsigned int			_max_energy_point;
		unsigned int			_level;
		std::string				_name;
		unsigned int			_melee_damage;
		unsigned int			_ranged_damage;
		unsigned int			_armor_reduction;

		unsigned int			_melee_energy_cost;
		unsigned int			_ranged_energy_cost;
};

#endif