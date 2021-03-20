#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP

# include <iostream>
# include <string>
# include "Zombie.hpp"

class ZombieEvent
{
    public:
		ZombieEvent(void);
		~ZombieEvent(void);
		void	setZombieType(std::string type, Zombie* zombie);
		Zombie* newZombie(std::string name);

	private:
		std::string _type;
};

#endif