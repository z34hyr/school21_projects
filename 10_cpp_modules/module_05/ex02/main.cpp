
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat Boris("Boris", 20);
		PresidentalPardonForm home("home");
		RobotomyRequestForm machine("office");
		ShrubberyCreationForm shrubbery("plant");
		Boris.signForm(home);
		Boris.executeForm(home);
		Boris.signForm(machine);
		for (int i = 0; i < 5; i++)
			Boris.executeForm(machine);
		Boris.signForm(shrubbery);
		Boris.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
