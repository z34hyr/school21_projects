
#include "Intern.hpp"

Intern::Intern(void)
{
	return;
}

Intern::~Intern(void)
{
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
	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			Form* newForm = (this->*possibleForms[i])(target);
			std::cout << MAGENTA << "Intern" << RESET << " creates form " << RED << target << RESET << std::endl;
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