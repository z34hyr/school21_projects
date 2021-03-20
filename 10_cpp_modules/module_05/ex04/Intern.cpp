
#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << MAGENTA << "Intern " << RESET << " has been created" << std::endl;
	return;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
	return;
}

Intern::Intern(const Intern& obj)
{
	obj.forSakeOfCoplien();
	return;
}

Intern& Intern::operator= (const Intern& obj)
{
	obj.forSakeOfCoplien();
	return *this;
}

void	Intern::forSakeOfCoplien(void) const
{
	//do nothing
	return;
}

Form*	Intern::makePresidentalForm(std::string target)
{
	PresidentalPardonForm* form = new PresidentalPardonForm(target);
	return (form);
}

Form*	Intern::makeRobotomyForm(std::string target)
{
	RobotomyRequestForm* form = new RobotomyRequestForm(target);
	return (form);
}

Form*	Intern::makeShrubberyForm(std::string target)
{
	ShrubberyCreationForm* form = new ShrubberyCreationForm(target);
	return (form);
}

Form*	Intern::makeForm(std::string name, std::string target)
{
	Form* (Intern::* possibleForms[3]) (std::string) = { &Intern::makePresidentalForm, &Intern::makeRobotomyForm, &Intern::makeShrubberyForm};
	std::string const formNames[3] = {"presidental pardon" ,"robotomy request", "shrubbery creation"};
	std::cout << MAGENTA << "Intern " << RESET << " trying to find form \"" << name << "\"..." << std::endl;
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			Form* newForm = (this->*possibleForms[i])(target);
			std::cout << MAGENTA << "Intern" << RESET << " creates form targeted " << RED << target << RESET << ":" << std::endl;
			std::cout  << *newForm << std::endl;
			return newForm;
		}
	}
	std::cout << "No possible form \"" << name << "\"" << std::endl;
	throw Intern::NoPossibleFormException();
	return NULL;
}

const char* Intern::NoPossibleFormException::what() const throw()
{
	return "NoPossibleFormException";
}
