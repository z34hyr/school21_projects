
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
	//std::cout << WHICH.color << "size " << container.size() << RESET << "; " << container.max_size() << " - max_size; " << container.capacity() << " - capacity." << std::endl;
	std::cout << WHICH.color << "print forward: " << RESET << std::endl;
	while (i_b != i_e)
	{
		std::cout << *i_b << " ";
		++i_b;
		counter += 1;
	}
	std::cout << std::endl;
	//std::cout << WHICH.color << "(total " << counter << ")" << RESET << std::endl;
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

		std::vector<int> arr(3, 11);
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		ft::vector<int> myarr(3, 11);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);
	}
	{
		print_test_name("iterator constructor test", "int i_arr[] = {1, 2, 10};,\n std::vector<int> arr(i_arr, i_arr + sizeof(i_arr) / sizeof(int));");

		int i_arr[] = {1, 2, 10};
		std::vector<int> arr(i_arr, i_arr + sizeof(i_arr) / sizeof(int));
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		ft::vector<int> myarr(i_arr, i_arr + sizeof(i_arr) / sizeof(int));
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);
	}

	{
		print_test_name("basic constructor + push_back + pop_back test", "vector<int>;\nloop push_back()\nloop pop_back()");

		std::vector<int> arr;
		ft::vector<int> myarr;
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		//	push_back
		for (int i = 0; i < 70; i += 11)
		{
			arr.push_back(i);
			myarr.push_back(i);
		}
		std::cout << "push_back result:" << std::endl;
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		//	at
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
		//	front + back
		print_test_name("front() + back() test", "arr.front(), arr.back()");
		std::cout << "STL front(): " << arr.front() << "; STL back(): " << arr.back() << std::endl;
		std::cout << "MINE front(): " << myarr.front() << "; MINE back(): " << myarr.back() << std::endl;

		//	pop_back
		print_test_name("pop_back test", "loop arr.pop_back()");
		for (int i = 0; i < 70; i += 11)
		{
			arr.pop_back();
			myarr.pop_back();
		}
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		//	assign
		print_test_name("assign test", "arr.assign(2, 999)");

		arr.assign(2, 999);
		myarr.assign(2, 999);
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		print_test_name("assign test", "arr.assign");

		std::vector<int> some_arr;
		int ar[] = {1, -12, 24, 20, 22, -19, 12, 20, 22, -100};

		arr.assign(&ar[0], &ar[9]);
		myarr.assign(&ar[0], &ar[9]);
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		//	insert
		print_test_name("insert test", "arr.insert");

		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);
		arr.insert(arr.begin() + 2, 999);
		arr.insert(arr.begin() + 3, 888);
		arr.insert(arr.begin(), arr.begin() + 2, arr.begin() + 3);
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);

		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);
		myarr.insert(myarr.begin() + 2, 999);
		myarr.insert(myarr.begin() + 3, 888);
		myarr.insert(myarr.begin(), myarr.begin() + 2, myarr.begin() + 3);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		//	erase
		print_test_name("erase test", "arr.erase");
		arr.erase(arr.begin() + 3);
		arr.erase(arr.begin(), arr.begin() + 3);
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);

		myarr.erase(myarr.begin() + 3);
		myarr.erase(myarr.begin(), myarr.begin() + 3);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		//	swap
		print_test_name("swap test", "arr.swap + std::swap");
		std::vector<int> arr_some(5, 111);
		arr.swap(arr_some);
		std::swap(arr, arr_some);
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);

		ft::vector<int> myarr_some(5, 111);
		myarr.swap(myarr_some);
		ft::swap(myarr_some, myarr);
		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);

		arr.clear();
		myarr.clear();
		print_iterable(arr, STL);
		std::cout << STL.color << "size " << arr.size() << RESET << "; " << arr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(arr, STL);

		print_iterable(myarr, MINE);
		std::cout << MINE.color << "size " << myarr.size() << RESET << "; " << myarr.capacity() << " - capacity." << std::endl;
		print_iterable_reverse(myarr, MINE);
	}
}
