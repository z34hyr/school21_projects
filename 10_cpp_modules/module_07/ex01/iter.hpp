
#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>

void iter(T const * arr, int const & length, void (*function)(T const &))
{
	for (int i = 0; i < length; i++)
		function(arr[i]);
	return;
}

#endif
