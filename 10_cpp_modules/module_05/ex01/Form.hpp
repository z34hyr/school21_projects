
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
// 1 - highest grade
// 150 - lowest grade

class Bureaucrat;

class Form
{
	public:
		Form(std::string const name, unsigned int sign_grade, unsigned int exec_grade);
		Form(const Form& obj);
		Form& operator = (const Form& obj);
		~Form(void);
		std::string			getName() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecGrade() const;
		bool				isSigned() const;
		bool				beSigned(Bureaucrat& obj);

	private:
		Form(void);
		std::string const		_name;
		unsigned int const		_grade_to_sign;
		unsigned int const		_grade_to_exec;
		bool					_is_signed;

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

	std::ostream& operator << (std::ostream& z, const Form& obj);

#endif