
#include "Form.hpp"

Form::Form(void) : _name("default"), _grade_to_sign(10), _grade_to_exec(10)
{
	return;
}

Form::Form(std::string const name, unsigned int sign_grade, unsigned int exec_grade, std::string target) : \
 _name(name), _grade_to_sign(sign_grade), _grade_to_exec(exec_grade), _target(target)
{
	if (sign_grade == 0 || exec_grade == 0)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150 || exec_grade > 150)
		throw Form::GradeTooLowException();
	_is_signed = false;
	std::cout << "Form " << GREEN << _name << RESET << " has been created" << std::endl;
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

std::string		Form::getTarget() const
{
	return _target;
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

void			Form::setSign(bool sign)
{
	_is_signed = sign;
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

void		Form::execute(Bureaucrat const & executor) const
{
	if (!_is_signed)
		throw Form::FormIsNotSigned();
	if (executor.getGrade() > this->getExecGrade())
		throw Form::GradeTooLowException();
	this->action();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "GradeTooLowException";
}

const char* Form::FormIsNotSigned::what() const throw()
{
	return "FormIsNotSigned";
}

std::ostream& operator << (std::ostream& z, const Form& obj)
{
	if (obj.isSigned())
		z << GREEN << obj.getName() << RESET << " (is signed)." << std::endl << "Grade to sign is " << obj.getSignGrade() << std::endl << "Grade to execute is " << obj.getExecGrade();
	else
		z << GREEN << obj.getName() << RESET << " (isn't signed)." << std::endl << "Grade to sign is " << obj.getSignGrade() << std::endl << "Grade to execute is " << obj.getExecGrade();
	return z;
}
