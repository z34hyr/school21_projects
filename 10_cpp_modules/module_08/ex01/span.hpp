
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>

class Span
{
	public:
		Span(unsigned int N);
		Span(Span const & obj);
		Span& operator= (Span const & obj);
		~Span();
		void	addNumber(int num);
		void	addNumber(int* num_arr, unsigned int size);
		int		shortestSpan();
		int		longestSpan();
		std::vector<int>	getVect() const;

		unsigned int getSize();

	private:
		Span(void);
		std::vector<int>		_vect_set;
		unsigned int	_size;
		class ClassIsFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "ClassIsFullException";
				};
		};
		class ClassIsEmptyException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "ClassIsEmptyException";
				};
		};
		class OnlyOneNumberException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "OnlyOneNumberException";
				};
		};
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "OutOfRangeException";
				};
		};
};

#endif