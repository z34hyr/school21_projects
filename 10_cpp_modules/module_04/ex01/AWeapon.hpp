
#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <string>
# include <iostream>

class AWeapon
{	
	public:
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();
		AWeapon(const AWeapon& obj);
		AWeapon& operator= (const AWeapon& obj);
		std::string		getName() const;
		int 			getAPCost() const;
		int 			getDamage() const;
		virtual void	attack() const = 0;
	protected:
		AWeapon(void);
		std::string		_name;
		int				_damage;
		int				_action_point_cost;
};

#endif
