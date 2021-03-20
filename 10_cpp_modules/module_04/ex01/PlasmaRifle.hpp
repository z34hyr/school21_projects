
#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon 
{
	public:
		PlasmaRifle();
		PlasmaRifle(const PlasmaRifle &copy);
		virtual ~PlasmaRifle();
		PlasmaRifle& operator= (const PlasmaRifle &copy);
		
		void attack() const;	
};

#endif
