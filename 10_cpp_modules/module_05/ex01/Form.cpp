
#include "Form.hpp"

Form::Form(void) : _name("default"), _grade_to_sign(10), _grade_to_exec(10)
{
	return;
}

Form::Form(std::string const name, unsigned int sign_grade, unsigned int exec_grade) : _name(name), _grade_to_sign(sign_grade), _grade_to_exec(exec_grade)
{
	if (sign_grade == 0 || exec_grade == 0)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	_is_signed = false;
	return;
}

Form::Form(const Form& obj) : _name(obj._name), _grade_to_sign(obj._grade_to_sign), _grade_to_exec(obj._grade_to_exec)
{
	_is_signed = obj._is_signed;
	return;
}

Form& Form::operator = (const Form& obj)
{
	_is_signed = obj._is_signed;
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form Destructor called" << std::endl;
	return;
}

std::string		Form::getName() const
{
	return _name;
}

unsigned int	Form::getSignGrade() const
{
	return _grade_to_sign;
}

unsigned int	Form::getExecGrade() const
{
	return _grade_to_exec;
}

bool			Form::isSigned() const
{
	return _is_signed;
}

bool			Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() <= _grade_to_sign)
	{
		_is_signed = true;
		return true;
	}
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

std::ostream& operator << (std::ostream& z, const Form& obj)
{
	if (obj.isSigned())
		z << "Form " << obj.getName() << " is signed." << std::endl << "Grade to sign is " << obj.getSignGrade() << std::endl << "Grade to execute is " << obj.getExecGrade();
	else
		z << "Form " << obj.getName() << " isn't signed." << std::endl << "Grade to sign is " << obj.getSignGrade() << std::endl << "Grade to execute is " << obj.getExecGrade();
	return z;
}