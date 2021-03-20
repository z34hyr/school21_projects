
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>  

class ShrubberyCreationForm : virtual public Form
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm& obj);
		virtual ~ShrubberyCreationForm(void);

		void		action() const;

	private:
		ShrubberyCreationForm(void);
};

#endif