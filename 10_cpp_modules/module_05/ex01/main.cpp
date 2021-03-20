
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat Boris("Boris", 12);
		Form form1("reference", 20, 20);
		std::cout << Boris << std::endl;
		Boris.decrementGrade();
		std::cout << Boris << std::endl << std::endl;
		Boris.signForm(form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat Elena("Elena", 12);
		Form form1("medicine", 2, 20);
		std::cout << Elena << std::endl << std::endl;
		Elena.signForm(form1);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
