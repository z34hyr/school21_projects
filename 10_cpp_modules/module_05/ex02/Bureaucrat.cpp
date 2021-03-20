
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	return;
}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade) : _name(name)
{
	if (grade >= 1 && grade <= 150)
		_grade = grade;
	else if (grade == 0)
		throw Bureaucrat::GradeTooHighException();
	else
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Burreaucrat " << CYAN << _name << RESET << " has been created" << std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	_grade = obj.getGrade();
	return;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& obj)
{
	_grade = obj.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	return;
}

std::string		Bureaucrat::getName() const
{
	return _name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return _grade;
}

void		Bureaucrat::incrementGrade()
{
	if (_grade > 1)
		_grade -= 1;
	else
		throw Bureaucrat::GradeTooHighException();
	return;
}

void		Bureaucrat::decrementGrade()
{
	if (_grade >= 1 && _grade < 150)
		_grade += 1;
	else if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	return;
}

void			Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << "Bureaucrat " << CYAN << this->getName() << RESET << " cannot sign " \
		 << form.getName() << " form because of sign cost is higher than bureacurat rank" << std::endl;
		std::cerr << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << CYAN << this->getName() << RESET << " executes " << GREEN << form.getName() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << CYAN << this->getName() << RESET << " can't execute " << GREEN << form.getName() << RESET << std::endl;
		std::cerr << e.what() << std::endl;
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

std::ostream& operator << (std::ostream& z, const Bureaucrat& obj)
{
	z << "Bureaucrat " << obj.getName() << " has grade " << obj.getGrade();
	return z;
}
