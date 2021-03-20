
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat Boris("Boris", 4);
	Form* robotomy = NULL;
	Form* shrubbery = NULL;
	Form* pardon = NULL;
	Form* unknown = NULL;
	Intern Vasya;
	try
	{
		robotomy = Vasya.makeForm("robotomy request", "office");
		std::cout << *robotomy << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		shrubbery = Vasya.makeForm("shrubbery creation", "plant");
		std::cout << *shrubbery << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		pardon = Vasya.makeForm("presidental pardon", "home");
		std::cout << *pardon << std::endl << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		unknown = Vasya.makeForm("what is it", "world");
		std::cout << *unknown << std::endl << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	if (robotomy)
	{
		Boris.signForm(*robotomy);
		Boris.executeForm(*robotomy);
	}
	std::cout << std::endl;
	if (shrubbery)
	{
		Boris.signForm(*shrubbery);
		Boris.executeForm(*shrubbery);
	}
	std::cout << std::endl;
	if (pardon)
	{
		Boris.signForm(*pardon);
		Boris.executeForm(*pardon);
	}
	std::cout << std::endl;
	if (unknown)
	{
		Boris.signForm(*unknown);
		Boris.executeForm(*unknown);
	}
}
