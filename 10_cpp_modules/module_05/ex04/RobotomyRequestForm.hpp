
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include "Form.hpp"

class RobotomyRequestForm : virtual public Form
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator = (const RobotomyRequestForm& obj);
		~RobotomyRequestForm(void);

		void		action() const;

	private:
		RobotomyRequestForm(void);
};

#endif