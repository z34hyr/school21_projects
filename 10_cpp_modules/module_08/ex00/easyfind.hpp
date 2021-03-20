
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <exception>
#include <algorithm>

class NumberNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "NumberNotFoundException";
		}
};

template<typename T>

typename T::iterator easyfind(T & cont, int num)
{
	typename T::iterator vect_iter = std::find(cont.begin(), cont.end(), num);
	if (vect_iter != cont.end())
		return vect_iter;
	throw NumberNotFoundException();
}

#endif