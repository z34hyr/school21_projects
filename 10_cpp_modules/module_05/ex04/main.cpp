
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	OfficeBlock* office_1 = new OfficeBlock();
	Intern* Vasya = new Intern();
	Bureaucrat* SigningBure = new Bureaucrat("Oleg Borisich", 15);
	Bureaucrat* ExecutingBure = new Bureaucrat("Stanislaw Venedictovich", 50);
	office_1->setIntern(Vasya);
	office_1->setBurSigning(SigningBure);
	office_1->setBurExecuting(ExecutingBure);
	office_1->staffList();
	Form* some_form;
	some_form = office_1->doBureaucracy("presidental pardon", "Forest");
	delete Vasya;
	delete SigningBure;
	delete ExecutingBure;
	delete some_form;
	delete office_1;

	std::cout << std::endl << std::endl;
	Intern* Petya = new Intern();
	Bureaucrat* SigningKlerk = new Bureaucrat("Alla Albertovna", 15);
	
	try
	{
		OfficeBlock* office_2 = new OfficeBlock(Petya, SigningKlerk, NULL);
		office_2->staffList();
		Form* some_form1;
		some_form1 = office_2->doBureaucracy("presidental pardon", "Petrov");
		//office_2->setIntern(Petya);
		Bureaucrat* ExecutingKlerk = new Bureaucrat("Viyacheslav Fedorovich", 2);
		//office_2->setBurExecuting(SigningKlerk);
		office_2->setBurExecuting(ExecutingKlerk);
		some_form1 = office_2->doBureaucracy("presidental pardon", "Petrov");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// int main()
// {
// 	Intern     idiotOne;
// 	Bureaucrat	hermes = Bureaucrat("Hermes Conrad", 37);
// 	Bureaucrat	bob = Bureaucrat("Bobby Bobson", 123);
// 	OfficeBlock	ob;
	
// 	ob.setIntern(&idiotOne);
// 	ob.setBurSigning(&bob);
// 	ob.setBurExecuting(&hermes);
// 	try
// 	{
// 		ob.doBureaucracy("mutant pig termination", "Pigley");
// 	}
// 	catch (std::exception & e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// }