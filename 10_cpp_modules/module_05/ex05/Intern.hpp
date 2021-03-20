
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
// 1 - highest grade
// 150 - lowest grade

# define MAGENTA  "\x1B[35m" // Magenta
# define CYAN  "\x1B[36m" // Cyan
# define GREEN   "\033[32m"      /* Green */
# define RESET   "\033[0m"

class Form;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& obj);
		Intern& operator = (const Intern& obj);
		~Intern(void);

		Form*	makeForm(std::string name, std::string target);

		void	forSakeOfCoplien(void) const;

	private:
		Form*	makePresidentalForm(std::string target);
		Form*	makeRobotomyForm(std::string target);
		Form*	makeShrubberyForm(std::string target);
		class NoPossibleFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

	std::ostream& operator << (std::ostream& z, const Intern& obj);

#endif