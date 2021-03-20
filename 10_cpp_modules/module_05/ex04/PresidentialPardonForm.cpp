
#include "PresidentialPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm(std::string target) : Form("PresidentalPardonForm", 25, 5, target)
{
	return;
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade(), obj.getTarget())
{
	setSign(obj.isSigned());
	return;
}

PresidentalPardonForm& PresidentalPardonForm::operator = (const PresidentalPardonForm& obj)
{
	setSign(obj.isSigned());
	return *this;
}

PresidentalPardonForm::~PresidentalPardonForm(void)
{
	return;
}

void	PresidentalPardonForm::action() const
{
	std::cout << RED << this->getTarget() << RESET << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
