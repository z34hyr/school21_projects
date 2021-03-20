
#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
	public:
		SuperMutant();
		virtual ~SuperMutant();
		SuperMutant(const SuperMutant &obj);
		SuperMutant& operator= (const SuperMutant &obj);
		void takeDamage(int amount);
};


#endif
