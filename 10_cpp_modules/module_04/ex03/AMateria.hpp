
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	private:
		unsigned int	_xp;

	protected:
		AMateria(void);
		std::string		_type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& obj);
		AMateria& operator = (const AMateria& obj);
		virtual ~AMateria();
		std::string const & getType() const; //Returns the materia type
		unsigned int	getXP() const; //Returns the Materia's XP
		void			increaseXP(unsigned int size);

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
