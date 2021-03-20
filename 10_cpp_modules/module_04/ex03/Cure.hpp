
#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include "Character.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(std::string const & type);
		Cure(const Cure& obj);
		Cure& operator = (const Cure& obj);
		virtual ~Cure();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif