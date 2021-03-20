
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

# define GREEN   "\033[32m"      /* Green */
# define RED     "\033[31m"      /* Red */
# define RESET   "\033[0m"

# define ATTACK_COST 10
# define AP_RECOVER 10

class Character
{
	public:
		Character(std::string const & name);
		~Character();
		Character(const Character& obj);
		Character& operator = (const Character& obj);

		void recoverAP();
		void equip(AWeapon* weapon);
		void attack(Enemy* enemy);
		std::string getName() const;
		int	 getAP() const;
		std::string getWeaponType() const;
		void		resetIsKilled();
		bool		getIsKilled();

	protected:
		Character(void);
		std::string		_name;
		int				_action_point;
		int				_max_action_point;
		AWeapon*		_weapon;
		bool			_is_killed;
};

std::ostream& operator << (std::ostream& z, const Character& obj);

#endif
