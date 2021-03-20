
#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(std::string const & type);
		Ice(const Ice& obj);
		Ice& operator = (const Ice& obj);
		virtual ~Ice();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif