
#ifndef COMMON_RULES_HPP
# define COMMON_RULES_HPP

#include <exception>
#include <iostream>

#define ARR_SIZE 30000

class FileErrorException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "FileErrorException";
		}
};

class WrongBracesSequenceException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "WrongBracesSequenceException";
		}
};

class WrongBracesCountException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "WrongBracesCountException";
		}
};

class WrongCharacterException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "WrongCharacterException";
		}
};

class CantIncrementException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "CantIncrementException";
		}
};

class CantDecrementException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "CantDecrementException";
		}
};

class OutOfRangeException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "OutOfRangeException";
		}
};

#endif
