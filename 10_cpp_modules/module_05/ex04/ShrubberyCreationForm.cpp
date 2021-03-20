
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137, target)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : Form(obj.getName(), obj.getSignGrade(), obj.getExecGrade(), obj.getTarget())
{
	setSign(obj.isSigned());
	return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& obj)
{
	setSign(obj.isSigned());
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

void	ShrubberyCreationForm::action() const
{
	std::string file_name = this->getTarget() + "_shrubbery";
	std::ofstream outfile (file_name.c_str());
	outfile << \
"     /\\\n\
    / o\\\n\
   /o   \\\n\
  /__ 0__\\\n\
     ||" << std::endl;
	outfile << \
"    __\n\
   (  )\n\
  (    )\n\
   (  )\n\
    ||" << std::endl;
	outfile.close();
}
