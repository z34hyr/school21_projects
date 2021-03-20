
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45, target)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade(), obj.getTarget())
{
	setSign(obj.isSigned());
	return;
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& obj)
{
	setSign(obj.isSigned());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

void	RobotomyRequestForm::action() const
{
	std::cout << "Noises: pshhhh-sssbaaam" << std::endl;
	if (rand() % 2)
		std::cout << RED << this->getTarget() << RESET << " has been robotomized successfully" << std::endl;
	else
		std::cout << RED << this->getTarget() << RESET << " has not been robotomized" << std::endl;
}
