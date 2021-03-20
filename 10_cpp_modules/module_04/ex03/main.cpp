
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	AMateria* cure = new Cure();
	AMateria* ice = new Ice();

	ICharacter* me = new Character("Boris");
/*
	for (int i = 0; i < 3; i++)
	{
		std::cout << "cure XP: " << cure->getXP() << std::endl;
		cure->use(*me);
		std::cout << "ice XP: " << ice->getXP() << std::endl;
		ice->use(*me);
	}
*/
	me->equip(ice);
	me->equip(cure);
	delete me;

	Character* me1 = new Character("Boris");

	AMateria* cure1 = new Cure();
	AMateria* ice1 = new Ice();
	AMateria* cure2 = cure1->clone();
	me1->equip(ice1);
	me1->equip(cure1);
	//Character* someone = new Character(*me1);
	Character* someone = new Character("John");
	*someone = *me1;
	delete me1;
	MateriaSource* source = new MateriaSource();
	MateriaSource* copy_source = new MateriaSource();

	//AMateria* cure2 = new Cure();
	std::cout << cure2->getType() << std::endl;
	for (int i = 0; i < 6; i++)
		source->learnMateria(cure2);
	someone->equip(source->createMateria("cure"));
	someone->use(2, *someone);

	*copy_source = *source;
	someone->equip(copy_source->createMateria("cure"));
	someone->use(3, *someone);
	delete someone;
	delete source;
	delete copy_source;
	delete cure2;
}
