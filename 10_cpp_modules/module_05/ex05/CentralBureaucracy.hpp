
#ifndef CENTARLBUREAUCRACY_HPP
# define CENTARLBUREAUCRACY_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include "OfficeBlock.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

// 1 - highest grade
// 150 - lowest grade

# define CYAN  "\x1B[36m" // Cyan
# define GREEN   "\033[32m"      /* Green */
# define RESET   "\033[0m"
# define BUREAUCRACY_SIZE 20

class Form;

struct QUEUE 
		{
			std::string		form_target; // client name
			struct QUEUE	*next;
			struct QUEUE	*prev;
		};

class CentralBureaucracy
{
	public:
		CentralBureaucracy(void);
		CentralBureaucracy(const CentralBureaucracy& obj);
		CentralBureaucracy& operator = (const CentralBureaucracy& obj);
		~CentralBureaucracy(void);

		void	feedBureacurat(Bureaucrat* bure);
		void	showBureauInfo(int number);
		QUEUE*	queueUp(std::string form_target);
		void	doBureaucracy(void);
		void	showQueue(void);
		int		queue_length(void);
		bool	check_fullness(int i); // returns 1 if bereau is full (1 inren + 1 sugner + 1 executor)
		void	fireExecBureaucrat(int block);

	private:
		OfficeBlock			_block[BUREAUCRACY_SIZE];
		void				forSakeOfCoplien(void) const;
		void				pushClient(std::string name);
		void				popClient(std::string name);
		QUEUE*				_main_queue;
		QUEUE*				add_last(std::string form_target);
		QUEUE*				get_first();
		void				clean_queue();
		};

	std::ostream& operator << (std::ostream& z, const CentralBureaucracy& obj);

#endif