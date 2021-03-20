
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat Boris("Boris", 12);
		std::cout << Boris << std::endl;
		Boris.decrementGrade();
		std::cout << Boris << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Oleg("Oleg", 0);
		std::cout << Oleg << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	try
	{
		Bureaucrat Philipp("Philipp", 1);
		std::cout << Philipp << std::endl;
		Philipp.incrementGrade();
		std::cout << Philipp << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}

	try
	{
		Bureaucrat Zahar("Zahar", 150);
		std::cout << Zahar << std::endl;
		Zahar.decrementGrade();
		std::cout << Zahar << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
