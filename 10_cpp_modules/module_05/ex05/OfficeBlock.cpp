
#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void)
{
	_intern = NULL;
	_bur_signing = NULL;
	_bur_executing = NULL;
	_queue = 0;
	//std::cout << "Bureau created! The staff is empty." << std::endl;
	return;
}

OfficeBlock::OfficeBlock(Intern* intern, Bureaucrat* bur_signing, Bureaucrat* bur_executing)
{
	if (bur_signing && bur_signing == bur_executing)
		throw OfficeBlock::SameForTwoBureaucratException();
	_intern = intern;
	_bur_signing = bur_signing;
	_bur_executing = bur_executing;
	_queue = 0;
	std::cout << "Bureau created! The staff is:" << std::endl;
	staffList();
}

OfficeBlock::~OfficeBlock(void)
{
	//std::cout << "Office Destructor called" << std::endl;
	return;
}

bool	OfficeBlock::getIntern(bool show_info) const
{
	if (_intern)
	{
		if (show_info)
			std::cout << "Intern: assigned" << std::endl;
		return true;
	}
	if (show_info)
		std::cout << "Intern: not assigned" << std::endl;
	return false;
}

bool	OfficeBlock::getBurSigning(bool show_info) const
{
	if (_bur_signing)
	{
		if (show_info)
			std::cout << "Signing bureaucrat: " << *_bur_signing << std::endl;
		return true;
	}
	if (show_info)
		std::cout << "Signing bureaucrat: not assigned" << std::endl;
	return false;
}

bool	OfficeBlock::getBurExecuting(bool show_info) const
{
	if (_bur_executing)
	{
		if (show_info)
			std::cout << "Executing bureaucrat: " << *_bur_executing << std::endl;
		return true;
	}
	if (show_info)
		std::cout << "Executing bureaucrat: not assigned" << std::endl;
	return false;	
}

void	OfficeBlock::staffList(void)
{
	getIntern(true);
	getBurSigning(true);
	getBurExecuting(true);
}

void	OfficeBlock::setIntern(Intern* intern)
{
	if (this->_intern == intern)
		throw OfficeBlock::SameInternException();
	_intern = intern;
	std::cout << "Intern is in staff now!" << std::endl;
}

void	OfficeBlock::setBurSigning(Bureaucrat* bur_signing)
{
	if (this->_bur_signing == bur_signing || this->_bur_executing == bur_signing)
		throw OfficeBlock::SameBureaucratException();
	_bur_signing = bur_signing;
	std::cout << "Signing bureaucrat " << _bur_signing->getName() << " is in staff now!" << std::endl;
}

void	OfficeBlock::setBurExecuting(Bureaucrat* bur_executing)
{
	if (this->_bur_signing == bur_executing || this->_bur_executing == bur_executing)
		throw OfficeBlock::SameBureaucratException();
	_bur_executing = bur_executing;
	if (_bur_executing)
		std::cout << "Executing bureaucrat " << _bur_executing->getName() << " is in staff now!" << std::endl;
}

Form*	OfficeBlock::doBureaucracy(std::string form_name, std::string target_name)
{
	Form* new_form;
	try
	{
		if (!_intern)
			throw OfficeBlock::NoInternException();
		if (!_bur_signing)
			throw OfficeBlock::NoSigningBureaucratException();
		if (!_bur_executing)
			throw OfficeBlock::NoExecutingBureaucratException();
		new_form = _intern->makeForm(form_name, target_name);
		_bur_signing->signForm(*new_form);
		_bur_executing->executeForm(*new_form);
		return new_form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return NULL;
}

const char* OfficeBlock::SameForTwoBureaucratException::what() const throw()
{
	return "Error occured.\n\
	You're trying to set one bureaucrat for two position.\n\
	For our bureau it's inadmissible.\n\
	One man should do one work.";
}

const char* OfficeBlock::SameInternException::what() const throw()
{
	return "Error occured.\n\
	You're trying to reset the same intern.\n\
	For our bureau it's inadmissible.\n\
	Intern is already in staff.";
}

const char* OfficeBlock::SameBureaucratException::what() const throw()
{
	return "Error occured.\n\
	You're trying to reset the same bureaucrat.\n\
	For our bureau it's inadmissible.\n\
	Bureaucrat is already in staff.";
}

const char* OfficeBlock::NoInternException::what() const throw()
{
	return "Error occured.\n\
	You're trying to do bureaucracy without intern.\n\
	For our bureau it's inadmissible.\n\
	First you should hire the intern.";
}

const char* OfficeBlock::NoSigningBureaucratException::what() const throw()
{
	return "Error occured.\n\
	You're trying to do bureaucracy without signing bureaucrat.\n\
	For our bureau it's inadmissible.\n\
	First you should hire the signing bureaucrat.";
}

const char* OfficeBlock::NoExecutingBureaucratException::what() const throw()
{
	return "Error occured.\n\
	You're trying to do bureaucracy without executing bureaucrat.\n\
	For our bureau it's inadmissible.\n\
	First you should hire the executing bureaucrat.";
}