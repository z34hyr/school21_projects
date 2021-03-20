
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>

# include "ICharacter.hpp"
# include "AMateria.hpp"

# define MAGENTA  "\x1B[35m" // Magenta
# define CYAN  "\x1B[36m" // Cyan
# define RESET  "\x1B[0m" // Set all colors back to normal.

class Character : public ICharacter
{
	private:
		Character(void);
		AMateria*		_inventory[4];
		std::string		_name;
		int	_count;

	public:
		Character(std::string const & name);
		Character(const Character& obj);
		Character& operator = (const Character& obj);
		virtual ~Character();
		
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

#endif