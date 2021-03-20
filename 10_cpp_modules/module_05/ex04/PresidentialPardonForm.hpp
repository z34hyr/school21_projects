
#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

# include "Form.hpp"

class PresidentalPardonForm : virtual public Form
{
	public:
		PresidentalPardonForm(std::string target);
		PresidentalPardonForm(const PresidentalPardonForm& obj);
		PresidentalPardonForm& operator = (const PresidentalPardonForm& obj);
		~PresidentalPardonForm(void);

		void		action() const;

	private:
		PresidentalPardonForm(void);
};

#endif