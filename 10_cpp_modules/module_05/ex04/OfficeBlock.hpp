
#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "Intern.hpp"

class OfficeBlock
{
	public:
		OfficeBlock(void);
		OfficeBlock(Intern* intern, Bureaucrat* bur_signing, Bureaucrat* bur_executing);
		~OfficeBlock(void);

		void	getIntern(void) const;
		void	getBurSigning(void) const;
		void	getBurExecuting(void) const;
		void	setIntern(Intern* intern);
		void	setBurSigning(Bureaucrat* bur_signing);
		void	setBurExecuting(Bureaucrat* bur_executing);
		void	staffList(void);

		Form*	doBureaucracy(std::string form_name, std::string target_name);

	private:
		Intern*		_intern;
		Bureaucrat* _bur_signing;
		Bureaucrat* _bur_executing;
		class SameForTwoBureaucratException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SameInternException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SameBureaucratException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoInternException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoSigningBureaucratException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NoExecutingBureaucratException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

	std::ostream& operator << (std::ostream& z, const OfficeBlock& obj);

#endif