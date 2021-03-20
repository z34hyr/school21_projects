
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"
// 1 - highest grade
// 150 - lowest grade

# define GREEN   "\033[32m"      /* Green */
# define RED     "\033[31m"      /* Red */
# define RESET   "\033[0m"

class Bureaucrat;

class Form
{
	public:
		Form(std::string const name, unsigned int sign_grade, unsigned int exec_grade, std::string target);
		Form(const Form& obj);
		Form& operator = (const Form& obj);
		virtual	~Form(void);
		std::string			getName() const;
		unsigned int		getSignGrade() const;
		unsigned int		getExecGrade() const;
		std::string			getTarget() const;
		bool				isSigned() const;
		void				setSign(bool sign);
		bool				beSigned(Bureaucrat& obj);
		void				execute(Bureaucrat const & executor) const;
		virtual void		action() const = 0;

	private:
		Form(void);
		std::string const		_name;
		unsigned int const		_grade_to_sign;
		unsigned int const		_grade_to_exec;
		bool					_is_signed;
		std::string				_target;

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
		class FormIsNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

	std::ostream& operator << (std::ostream& z, const Form& obj);

#endif