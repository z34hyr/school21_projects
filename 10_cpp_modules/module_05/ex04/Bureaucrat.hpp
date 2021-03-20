
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
// 1 - highest grade
// 150 - lowest grade

# define CYAN  "\x1B[36m" // Cyan
# define GREEN   "\033[32m"      /* Green */
# define RESET   "\033[0m"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(std::string const name, unsigned int grade);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator = (const Bureaucrat& obj);
		~Bureaucrat(void);
		std::string			getName() const;
		unsigned int		getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& form);
		void				executeForm(Form const & form);

	private:
		Bureaucrat(void);
		std::string const	_name;
		unsigned int		_grade;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

	std::ostream& operator << (std::ostream& z, const Bureaucrat& obj);

#endif