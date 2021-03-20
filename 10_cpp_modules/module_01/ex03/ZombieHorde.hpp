#ifndef ZOMBIE_HORDE_HPP
# define ZOMBIE_HORDE_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieHorde
{
    public:
		ZombieHorde(int N);
		~ZombieHorde(void);
		void	announce(void);

	private:
		static std::string	_name_pool[10];
		Zombie*	_ZombiePack;
		int		_number;
};

#endif