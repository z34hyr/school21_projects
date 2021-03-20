
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
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name)
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
		std::cout << "Bureaucrat " << this->getName() << " cannot sign " \
		 << form.getName() << " form because of sign cost is higher than bureacurat rank" << std::endl;
		std::cerr << e.what() << '\n';
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
