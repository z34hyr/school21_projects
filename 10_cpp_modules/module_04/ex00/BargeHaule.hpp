
#ifndef BARGEHAULE_HPP
# define BARGEHAULE_HPP

# include <iostream>
# include <string>
# include "Sorcerer.hpp"

# define YELLOW  "\033[33m" // Yellow
# define RESET   "\033[0m"

class BargeHaule: public Victim
{
	public:
		BargeHaule(std::string name);
		virtual ~BargeHaule(void);
		BargeHaule(const BargeHaule& obj);
		BargeHaule& operator = (const BargeHaule& obj);

		void	getPolymorphed(void) const;

	private:
		BargeHaule(void);

};

	std::ostream& operator << (std::ostream& z, const BargeHaule& obj);

#endif