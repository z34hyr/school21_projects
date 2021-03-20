
#include <string>
#include <iostream>
#include <cstdlib>

#include "Array.hpp"

template<typename T>
void	show_all(T* arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

// class SomeClass
// {
// 	public:
// 		SomeClass(){_number = std::rand() % 10; return;};
// 		~SomeClass(){};
// 		int	get_number() const {return _number;};
// 	private:
// 		int _number;
// };
// std::ostream& operator << (std::ostream& z, const SomeClass& obj)
// {
// 	z << obj.get_number();
// 	return z;
// }


int main()
{
	int * z = new int();
	std::cout << "z: " << *z << std::endl;
	delete z;
	unsigned int size = 10;
	Array<>	a;
	try
	{
		std::cout << a[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout.precision(1);
	std::cout << std::fixed << "a size (before assignation): " << a.size() << std::endl;
	Array<> b(size);

	b[0] = 1.0;
	for (unsigned int i = 1; i < b.size(); i++)
		b[i] += b[i-1] + 1;
	std::cout << "b array:" << std::endl;
	::show_all(&b[0], b.size());
	std::cout << "b size: " << b.size() << std::endl;
	b[0] = 20;
	Array<> c(b);
	std::cout << "c size: " << b.size() << std::endl;
	a = b;
	std::cout << "Before changes: " << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
	std::cout << "c[0]: " << c[0] << std::endl;
	a[0] = 10;
	c[0] = 111;
	std::cout << "After changes: " << std::endl;
	std::cout << "a[0]: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;
	std::cout << "c[0]: " << c[0] << std::endl;	

	Array<char> arr_alpha(26);
	arr_alpha[0] = 'a';
	for (unsigned int i = 1; i < arr_alpha.size(); i++)
		arr_alpha[i] += arr_alpha[i-1] + 1;
	std::cout << "arr_alpha:" << std::endl;
	::show_all(&arr_alpha[0], arr_alpha.size());

	try
	{
		std::cout << b[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "b error:" << std::endl;
		std::cerr << e.what() << '\n';
	}
	Array<std::string> str_arr(4);
	try
	{
		str_arr[0] = "Russia";
		str_arr[1] = "Belarus";
		str_arr[2] = "Ukraine";
		str_arr[3] = "Kazakhstan";
		str_arr[4] = "NoSpace";
	}
	catch(const std::exception& e)
	{
		std::cerr << "str_arr error:" << std::endl;
		std::cerr << e.what() << '\n';
	}
	::show_all(&str_arr[0], str_arr.size());
	// Array<SomeClass> class_arr(5);
	// SomeClass num_1;
	// SomeClass num_2;
	// SomeClass num_3;
	// SomeClass num_4;
	// SomeClass num_5;
	// class_arr[0] = num_1;
	// class_arr[1] = num_2;
	// class_arr[2] = num_3;
	// class_arr[3] = num_4;
	// class_arr[4] = num_5;
	// ::show_all(&class_arr[0], 5);
}