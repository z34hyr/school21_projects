
#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <string>
# include <iostream>
# include "ISpaceMarine.hpp"

# define GREEN  "\x1B[32m" // Green
# define CYAN  "\x1B[36m" // Cyan
# define RESET  "\x1B[0m" // Set all colors back to normal.

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine(void);
		virtual ~TacticalMarine(void);
		TacticalMarine(const TacticalMarine& marine);
		TacticalMarine& operator = (const TacticalMarine& marine);
		void	battleCry() const;
		void	rangedAttack() const;
		void	meleeAttack() const;
		ISpaceMarine* clone() const;


};

#endif