
#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>
# include <string>
# include "Sorcerer.hpp"

class Victim
{
	public:
		Victim(std::string name);
		virtual ~Victim(void);
		Victim(const Victim& obj);
		Victim& operator = (const Victim& obj);

		std::string		get_name(void) const;
		void			set_name(std::string name);
		void			introduction(void);
		virtual void 	getPolymorphed(void) const;
		
	protected:
		Victim(void);
		std::string _name;
};

	std::ostream& operator << (std::ostream& z, const Victim& obj);

#endif