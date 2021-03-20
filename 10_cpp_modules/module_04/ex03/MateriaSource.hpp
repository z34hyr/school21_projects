
#ifndef MATERIA_HPP
# define MATERIA_HPP

# include <iostream>
# include <string>

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		_inventory[4];
		unsigned int	_count;

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator = (const MateriaSource& obj);
		virtual ~MateriaSource();
		
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);

};

#endif