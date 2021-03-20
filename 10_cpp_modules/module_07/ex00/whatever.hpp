
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>

void swap(T & x, T & y)
{
	T temp = x;
	x = y;
	y = temp;
	return;
}

template<typename T>
T const & max(T const & x, T const & y)
{
	return (y >= x ? y : x);
}

template<typename T>
T const & min(T const & x, T const & y)
{
	return (y <= x ? y : x);
}

#endif
