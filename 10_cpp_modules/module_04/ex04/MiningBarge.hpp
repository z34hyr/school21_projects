

#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class IMiningLaser;
class IAsteroid;

class MiningBarge
{
	public:
		void equip(IMiningLaser*);
		void mine(IAsteroid*) const;
};

#endif