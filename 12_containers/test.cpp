
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstring>
#include "vector.hpp"

# define CYAN  "\x1B[36m" // Cyan
# define GREEN   "\033[32m" // Green
# define YELLOW "\033[33m" // Yellow
# define WHITE "\033[37m" // White
# define RESET   "\033[0m"

struct container_info
{
	std::string owner;
	std::string color;
	std::string type;
};

container_info STL;
container_info MINE;

class bzz
{
	public:
		bzz() { val = 1; };
		virtual ~bzz() { };
		void printVal() { std::cout << val << std::endl; }
	private:
		int val;
};

void print_test_name(std::string test_name);

template <typename T>
void print_iterable(T container, container_info WHICH)
{
	typename T::iterator i_b = container.begin();
	typename T::iterator i_e = container.end();
	int counter = 0;
	std::cout << "================================" << std::endl;
	std::cout << "Container type: " << WHICH.color << WHICH.owner << " " << WHICH.type << RESET << std::endl;
	std::cout << WHICH.color << "size " << container.size() << RESET << "; " << container.max_size() << " - max_size; " << container.capacity() << " - capacity." << std::endl;
	std::cout << WHICH.color << "print forward: " << RESET << std::endl;
	while (i_b != i_e)
	{
		std::cout << *i_b << " ";
		++i_b;
		counter += 1;
	}
	std::cout << WHICH.color << "(total " << counter << ")" << RESET << std::endl;
}

template <typename T>
void print_iterable_reverse(T container, container_info WHICH)
{
	typename T::reverse_iterator i_b = container.rbegin();
	typename T::reverse_iterator i_e = container.rend();
	int counter = 0;
	//std::cout << "================================" << std::endl;
	//std::cout << "Container type: " << WHICH.color << WHICH.owner << " " << WHICH.type << RESET << std::endl;
	//std::cout << WHICH.color << "size " << container.size() << RESET << "; " << container.max_size() << " - max_size; " << container.capacity() << " - capacity." << std::endl;
	std::cout << WHICH.color << "print backward: " << RESET << std::endl;
	while (i_b != i_e)
	{
		std::cout << *i_b << " ";
		++i_b;
		counter += 1;
	}
	std::cout << WHICH.color << "(total " << counter << ")" << RESET << std::endl;
}

void fill_info(std::string type)
{
	STL.type = type;
	MINE.type = type;
}

void print_test_name(std::string test_name, std::string command)
{
	std::cout << YELLOW;
	for (int i = 0; i < test_name.length(); i++)
		std::cout << "=";
	std::cout << std::endl;
	std::cout << test_name << std::endl;
	std::cout << "command: " << WHITE << command << YELLOW << std::endl;
	for (int i = 0; i < test_name.length(); i++)
		std::cout << "=";
	std::cout << RESET << std::endl;
}

int main()
{
	STL.owner = "STL";
	STL.color = GREEN;
	MINE.owner = "my";
	MINE.color = CYAN;
	//////////////////////////////
	// VECTOR TESTS				//
	//////////////////////////////
	fill_info("vector");
	{
		print_test_name("integral constructor test", "vector<int> arr(3, 11);");

		//int i_arr[] = {1, 2, 10};
		std::vector<int> arr(3, 11);
		print_iterable(arr, STL);
		std::cout << arr.capacity() << std::endl;
		print_iterable_reverse(arr, STL);
		ft::vector<int> myarr(3, 11);
		print_iterable(myarr, MINE);
		print_iterable_reverse(myarr, MINE);
	}
	{
		print_test_name("iterator constructor test", "int i_arr[] = {1, 2, 10};,\n std::vector<int> arr(i_arr, i_arr + sizeof(i_arr) / sizeof(int));");

		int i_arr[] = {1, 2, 10};
		std::vector<int> arr(i_arr, i_arr + sizeof(i_arr) / sizeof(int));
		print_iterable(arr, STL);
		std::cout << arr.capacity() << std::endl;
		print_iterable_reverse(arr, STL);
		ft::vector<int> myarr(i_arr, i_arr + sizeof(i_arr) / sizeof(int));
		print_iterable(myarr, MINE);
		print_iterable_reverse(myarr, MINE);
	}

	{
		print_test_name("basic constructor + push_back test", "vector<int>;\n loop push_back()");

		std::vector<int> arr;
		for (int i = 0; i < 50; i += 11)
			arr.push_back(i);
		print_iterable(arr, STL);
		print_iterable_reverse(arr, STL);
		ft::vector<int> myarr;
		for (int i = 0; i < 50; i += 11)
			myarr.push_back(i);
		print_iterable(myarr, MINE);
		print_iterable_reverse(myarr, MINE);

		print_test_name("at() test", "vector<int>;\nvect.at()");
		try
		{
			arr.at(100);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "arr.at(2): " << arr.at(2) << std::endl;
		try
		{
			myarr.at(100);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "myarr.at(2): " << myarr.at(2) << std::endl;

		print_test_name("front() + back() test", "arr.front(), arr.back()");
		std::cout << "STL front(): " << arr.front() << "; STL back(): " << arr.back() << std::endl;
		std::cout << "MINE front(): " << myarr.front() << "; MINE back(): " << myarr.back() << std::endl;

	}
	// std::cout << "reverse iter: " << std::endl;
	// while (z_b != z_e)
	// {
	// 	std::cout << *z_b << " ";
	// 	++z_b;
	// }
	// std::cout << std::endl;
	// std::vector<int> copy_arr(arr);
	// print_std_vect(copy_arr);
	// std::vector<int> ass_arr;
	// ass_arr = arr;
	// print_std_vect(ass_arr);
	// //ft::vector<int> my_arr (i_arr, i_arr + sizeof(i_arr) / sizeof(int));
	// ft::vector<int> my_arr(5);
	// std::fill(my_arr.begin(), my_arr.end(), 911);
	// ft::vector<int> my_ass_arr;
	// my_ass_arr = my_arr;
	// ft::vector<int> my_arr1 (3, 11);
	// //ft::vector<int> copy_my_arr(my_arr);
	// my_arr.swap(my_arr1);
	// //ft::swap(my_arr, my_arr1);
	// print_ft_vect(my_arr);
	// {
	// 	ft::vector<int>::iterator i_b = my_arr.begin();
	// 	ft::vector<int>::iterator i_e = my_arr.end();

	// 	ft::vector<int>::reverse_iterator ri_b = my_arr.rbegin();
	// 	ft::vector<int>::reverse_iterator ri_e = my_arr.rend();
	// 	while (i_b != i_e)
	// 	{
	// 		std::cout << *i_b << " ";
	// 		++i_b;
	// 	}
	// 	std::cout << std::endl;
	// }
	// {
	// 	ft::vector<int>::iterator i_b2 = my_arr1.begin();
	// 	ft::vector<int>::iterator i_e2 = my_arr1.end();
	// 	while (i_b2 != i_e2)
	// 	{
	// 		std::cout << *i_b2 << " ";
	// 		++i_b2;
	// 	}
	// 	std::cout << std::endl;
	// }
	// ft::swap(my_arr, my_arr1);
	// {
	// 	ft::vector<int>::iterator i_b = my_arr.begin();
	// 	ft::vector<int>::iterator i_e = my_arr.end();
	// 	while (i_b != i_e)
	// 	{
	// 		std::cout << *i_b << " ";
	// 		++i_b;
	// 	}
	// 	std::cout << std::endl;
	// }
	// {
	// 	ft::vector<int>::iterator i_b2 = my_arr1.begin();
	// 	ft::vector<int>::iterator i_e2 = my_arr1.end();
	// 	while (i_b2 != i_e2)
	// 	{
	// 		std::cout << *i_b2 << " ";
	// 		++i_b2;
	// 	}
	// 	std::cout << std::endl;
	// }
	// ft::vector<int>::iterator i_b1 = copy_my_arr.begin();
	// ft::vector<int>::iterator i_e1 = copy_my_arr.end();
	// while (i_b1 != i_e1)
	// {
	// 	std::cout << *i_b1 << " ";
	// 	++i_b1;
	// }
	// std::cout << std::endl;
	// std::vector<int> stdv;
	// for (int i = 0; i < 5; i++)
	// 	stdv.push_back(i);
	// print_std_vect(stdv);
	// std::vector<int> stdv1;
	// for (int i = 0; i < 7; i += 2)
	// 	stdv1.push_back(i);
	// //stdv.assign(stdv1.begin(), stdv1.begin() + 3);
	// stdv.assign(10, 998);
	// //stdv.swap(stdv1);
	// print_std_vect(stdv);
	// ft::vector<int> myv;
	// for (int i = 0; i < 5; i++)
	// 	myv.push_back(i);
	
	// ft::vector<int> myv1;
	// for (int i = 0; i < 7; i += 2)
	// 	myv1.push_back(i);
	//myv.assign(myv1.begin(), myv1.begin() + 3);
	//myv1.swap(myv);
	//stdv.insert(stdv.begin() + 2, 9, 111);
	// myv.assign(10, 998);
	//stdv.insert(stdv.begin() + 1, 1, 999);
	//print_std_vect(stdv);
	//std::cout << *(stdv.erase(stdv.begin(), stdv.begin() + 1)) << std::endl;
	//print_std_vect(stdv);
	// std::cout << "stdv size: " << stdv.size() << " stdv capacity: " << stdv.capacity() << std::endl;
	//myv.insert(myv.begin() + 2, 9, 111);
	//myv.insert(myv.begin() + 1, 1, 999);
	//std::cout << *(myv.erase(myv.begin(), myv.begin() + 1)) << std::endl;
	// ft::vector<int>::iterator i_b = myv.begin();
	// ft::vector<int>::iterator i_e = myv.end();
	// while (i_b != i_e)
	// {
	// 	std::cout << *i_b << " ";
	// 	++i_b;
	// }
	// std::cout << std::endl;
	// std::cout << "myv size: " << myv.size() << " myv capacity: " << myv.capacity() << std::endl;

	// std::vector<bzz*> wow1;
	// ft::vector<bzz*> wow;
	// bzz elem;
	// wow1.push_back(&elem);
	// wow.push_back(&elem);
// 	std::vector<float> vect;
// 	//std::cout << "begin: " << vect.front() << ", back: " << vect.back() << std::endl;
// 	for (int i = 0; i < 4; i++)
// 	{
// 		vect.push_back(11 + i);
// 	}
// 	try
// 	{
// 		//std::cout << vect.at(0) << std::endl;
// 		std::cout << "begin: " << vect.front() << ", back: " << vect.back() << std::endl;
// 	}
// 	catch(const std::out_of_range& e)
// 	{
// 		std::cerr << "Out of range error: " << e.what() << '\n';
// 	}
// 	//vect.insert(vect.begin() + 2, 111);
// 	print_std_vect(vect);
// 	std::cout << vect.size() << " " << vect.capacity() << std::endl;
// 	// for (int i = 0; i < 10; i++)
// 	// {
// 	// 	vect.pop_back();
// 	// 	print_std_vect(vect);
// 	// }
	
// 	std::cout << vect.size() << " " << vect.capacity() << std::endl;
// 	std::vector<float>::iterator lol = vect.begin() + 1;
// 	vect.insert(lol, 1);
// 	print_std_vect(vect);
// 	ft::vector<float> my_vect;
	
// 	for (int i = 0; i < 4; i++)
// 	{
// 		my_vect.push_back(11 + i);
// 	}
// 	try
// 	{
// 		std::cout << my_vect.at(0) << std::endl;
// 		std::cout << "begin: " << my_vect.front() << ", back: " << my_vect.back() << std::endl;
// 	}
// 	catch(const std::out_of_range& e)
// 	{
// 		std::cerr << "Out of range error: " << e.what() << '\n';
// 	}
// 	{
// 		ft::vector<float>::iterator fi_b = my_vect.begin();
// 		ft::vector<float>::iterator fi_e = my_vect.end();
// 		while (fi_b != fi_e)
// 		{
// 			std::cout << *fi_b << " | ";
// 			++fi_b;
// 		}
// 		std::cout << std::endl;
// 		std::cout << my_vect.size() << " " << my_vect.capacity() << std::endl;
// 	}
// 	ft::vector<float>::iterator lol1 = my_vect.begin() + 1;
// 	my_vect.insert(lol1, 11111);
// 	{
// 		ft::vector<float>::iterator fi_b = my_vect.begin();
// 		ft::vector<float>::iterator fi_e = my_vect.end();
// 		while (fi_b != fi_e)
// 		{
// 			std::cout << *fi_b << " | ";
// 			++fi_b;
// 		}
// 		std::cout << std::endl;
// 		std::cout << my_vect.size() << " " << my_vect.capacity() << std::endl;
// 	}

// //  	std::vector<float> vect;
	
// // 	for (int i = 0; i < 10; i++)
// // 	{
// // 		vect.push_back(11 + i);
// // 		//std::cout << vect.size() << " vs " << vect.capacity() << std::endl;
// // 	}
// // 	const std::size_t N = 10;
// //     int* a = new int[N];
// //     int* end = a + N;
// //     for (std::ptrdiff_t i = N; i > 0; --i)
// //         std::cout << (*(end - i) = i) << ' ';
// //     delete[] a;
// // 	std::cout << std::endl;
// // 	//vect.resize(3, -0.1);
// // 	vect.resize(3,-0.1);
// // std::cout << vect[4] << " - see that? " << std::endl;
// // 	//vect.reserve(20);
// // 	std::vector<float>::iterator i_b = vect.begin();
// // 	std::vector<float>::iterator i_e = vect.end();
// // 	std::ptrdiff_t zal = i_b - i_e;
// // 	std::cout << zal << " - ptrdiff" << std::endl;
// // 	int z = 0;
// // 	while (i_b != i_e)
// // 	{
// // 		if (z == 4)
// // 		{
// // 			std::vector<float>::iterator zza = i_b;
// // 			std::cout << *(zza + 2) << " " << *zza  << std::endl;
// // 			std::cout << zza[2] << " " << *zza  << std::endl;
// // 		}
// // 		std::cout << *i_b << " | ";// << std::endl;
// // 		++i_b;
// // 		z += 1;
// // 	}
// // std::cout << std::endl;
// // std::cout << vect.size() << " " << vect.capacity() << " " << vect.max_size() << std::endl;

// // ft::vector<float> uno;

// // for (int i = 0; i < 10; i++)
// // {
// // 	uno.push_back(11 + i);
// // 	std::cout << uno[i] << " ; " << uno.size() << " vs " << uno.capacity() << std::endl;
// // }
// // uno.resize(3,-0.1);
// // std::cout << uno[4] << " - see that? " << std::endl;
// // std::cout << uno.size() << " " << uno.capacity() << " " << uno.max_size() << std::endl;

// // ft::vector<float>::iterator fti_b = uno.begin();
// // ft::vector<float>::iterator fti_e = uno.end();
// // std::ptrdiff_t zal_ft = fti_b - fti_e;
// // 	std::cout << zal_ft << " - ptrdiff" << std::endl;

// // ft::vector<float>::iterator someiter;
// // int i = 0;
// // while (fti_b != fti_e)
// // {
// // 	if (i == 4)
// // 	{
// // 		someiter = fti_b;
// // 		std::cout << *(someiter + 2) << " " << *someiter << std::endl;
// // 		std::cout << someiter[2] << " " << *someiter << std::endl;
// // 		ft::vector<float>::iterator onemoreiter(fti_b);
// // 		std::cout << "onemoreiter i=4: " << *onemoreiter << std::endl;
// // 	}
// // 	std::cout << *fti_b << " | ";// << std::endl;
// // 	++fti_b;
// // 	i += 1;
// // }
// // std::cout << std::endl;

// {
// 	bzz *someclass = new bzz[10];
// 	std::vector<std::string> colour {"Blue", "Red", "Orange"};
// 	std::vector<std::string> blew {"Zal"};
// 	blew.swap(colour);
// 	colour.clear();
// 	std::cout << colour[0] << std::endl;
// 	// std::vector<bzz*> std_bzz;
// 	// for (int i = 0; i < 10; i++)
// 	// 	std_bzz.push_back(&someclass[i]);
// 	// //std::cout << std_bzz.max_size() << std::endl;
// 	// //std::cout << std_bzz.empty() << std::endl;
// 	// someclass[1].printVal();
// 	// std_bzz.clear();
// 	// someclass[1].printVal();
// 	// std::cout << std_bzz.size() << std::endl;
// 	// std::cout << "std res: ";
// 	// std_bzz[0]->printVal();
// 	// //delete[] someclass;
// }

// {
// 	//ft::vector<std::string> colour {"Blue", "Red", "Orange"};
// 	//ft::vector<std::string> blew {"Zal"};
// 	// blew.swap(colour);
// 	// colour.clear();
// 	// std::cout << colour[0] << std::endl;
// 	ft::vector<int> z1;
// 	ft::vector<int> z2;
// 	z1.push_back(1);
// 	z1.push_back(2);
// 	z1.push_back(3);
// 	z2.push_back(11);
// 	z2.push_back(12);
// 	//z1.swap(z2);
// 	//swap(z1, z2);
// 	//std::cout << z1[0] << std::endl;
// 	bzz *someclass1 = new bzz[10];
// 	ft::vector<bzz*> ft_bzz;
// 	for (int i = 0; i < 10; i++)
// 		ft_bzz.push_back(&someclass1[i]);
// 	//std::cout << ft_bzz.max_size() << std::endl;
// 	//std::cout << ft_bzz.empty() << std::endl;
// 	someclass1[1].printVal();
// 	ft_bzz.clear();
// 	std::cout << "my res: ";
// 	someclass1[1].printVal();
// 	//delete[] someclass1;
// }
// // ft::vector<bzz*> my_bzz;
// // for (int i = 0; i < 10; i++)
// // 	my_bzz.push_back(&someclass[i]);
// // std::cout << my_bzz.max_size() << std::endl;
// // std::cout << my_bzz.empty() << std::endl;

// // ft::vector<bzz*>::iterator bzzi_b1 = my_bzz.begin();
// // ft::vector<bzz*>::iterator bzzi_e1 = my_bzz.end();






// //delete[] someclass;

}
