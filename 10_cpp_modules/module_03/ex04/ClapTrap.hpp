
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
		ClapTrap(void);
		ClapTrap(std::string name);
		virtual ~ClapTrap(void);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator = (const ClapTrap& obj);

		virtual void	rangedAttack(std::string const & target);
		virtual void	meleeAttack(std::string const & target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);

		virtual unsigned int	get_hp(void) const;
		virtual unsigned int	get_max_hp(void) const;
		virtual unsigned int	get_enp(void) const;
		virtual unsigned int	get_max_energy_point(void) const;
		virtual unsigned int	get_level(void) const;
		virtual std::string		get_name(void) const;
		virtual unsigned int	get_melee_damage(void) const;
		virtual unsigned int	get_ranged_damage(void) const;
		virtual unsigned int	get_armor_reduction(void) const;
		virtual unsigned int	get_melee_energy_cost(void) const;
		virtual unsigned int	get_ranged_energy_cost(void) const;

		virtual void			set_hp(unsigned int hp);
		virtual void			set_max_hp(unsigned int max_hp);
		virtual void			set_enp(unsigned int enp);
		virtual void			set_max_energy_point(unsigned int max_en_p);
		virtual void			set_level(unsigned int level);
		virtual void			set_name(std::string name);
		virtual void			set_melee_damage(unsigned int melee_damage);
		virtual void			set_ranged_damage(unsigned int ranged_damage);
		virtual void			set_armor_reduction(unsigned int armor_reduction);
		virtual void			set_melee_energy_cost(unsigned int melee_energy_cost);
		virtual void			set_ranged_energy_cost(unsigned int ranged_energy_cost);

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