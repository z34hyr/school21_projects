
#include "iter.hpp"

#include <string>

void	do_smth_with_char(char const & elem)
{
	std::cout << elem << std::endl;
	return;
}

void	do_smth_with_int(int const & elem)
{
	std::cout << elem << std::endl;
	return;
}

void	do_smth_with_float(float const & elem)
{
	std::cout.precision(1);
	std::cout << std::fixed << elem << std::endl;
	return;
}

void	do_smth_with_arr_arr(std::string const & elem)
{
	std::cout << elem << std::endl;
	return;
}

int main()
{
	char	arr_c[5] = {'a', 'b', 'c', 'd', 'e'};
	int		arr_i[5] = {1, 2, 3, 4, 5};
	float	arr_f[5] = {10.0f, 12.0f, 14.0f, 16.0f, 18.0f};
	std::string	arr_arr_c[] = {"Black", "White", "Yellow", "Pink", "Cyan"};
	int size = 5;

	std::cout << std::endl << "with chars' array:" << std::endl;
	::iter(arr_c, size, &do_smth_with_char);
	std::cout << std::endl << "with integers' array:" << std::endl;
	::iter(arr_i, size, &do_smth_with_int);
	std::cout << std::endl << "with floats' array:" << std::endl;
	::iter(arr_f, size, &do_smth_with_float);
	std::cout << std::endl << "with array of strings:" << std::endl;
	::iter(arr_arr_c, size, &do_smth_with_arr_arr);
}
