
#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <string>
# include <iostream>
# include "ISquad.hpp"

# define MAGENTA  "\x1B[35m" // Magenta
# define CYAN  "\x1B[36m" // Cyan
# define RESET  "\x1B[0m" // Set all colors back to normal.

class Squad : public ISquad
{
	public:
		Squad();
		~Squad();
		Squad(const Squad& squad);
		Squad& operator = (const Squad& squad);
		int	getCount() const;
		ISpaceMarine*	getUnit(int N) const;
		int push(ISpaceMarine*);


	private:
		int	_count;
		ISpaceMarine**	_squad;
};

#endif