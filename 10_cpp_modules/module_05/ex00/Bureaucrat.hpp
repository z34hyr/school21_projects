
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

// 1 - highest grade
// 150 - lowest grade

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