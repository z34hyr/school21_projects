
#ifndef ASSAULTERMINATOR_HPP
# define ASSAULTERMINATOR_HPP

# include <string>
# include <iostream>
# include "ISpaceMarine.hpp"

# define GREEN  "\x1B[32m" // Green
# define CYAN  "\x1B[36m" // Cyan
# define RESET  "\x1B[0m" // Set all colors back to normal.

class AssaultTerminator : public ISpaceMarine
{
	public:
		AssaultTerminator(void);
		virtual ~AssaultTerminator(void);
		AssaultTerminator(const AssaultTerminator& marine);
		AssaultTerminator& operator = (const AssaultTerminator& marine);
		void	battleCry() const;
		void	rangedAttack() const;
		void	meleeAttack() const;
		ISpaceMarine* clone() const;

};

#endif