
#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include <string>
# include "Sorcerer.hpp"

# define CYAN  "\x1B[36m" // Yellow
# define RESET   "\033[0m" // RESET

class Peon: public Victim
{
	public:
		Peon(std::string name);
		virtual ~Peon(void);
		Peon(const Peon& obj);
		Peon& operator = (const Peon& obj);

		void	getPolymorphed(void) const;
	private:
		Peon(void);
};

	std::ostream& operator << (std::ostream& z, const Peon& obj);

#endif