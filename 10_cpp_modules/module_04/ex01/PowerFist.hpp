
#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon 
{
	public:
		PowerFist();
		PowerFist(const PowerFist &copy);
		virtual ~PowerFist();
		PowerFist& operator= (const PowerFist &copy);
		
		void attack() const;	
};

#endif
