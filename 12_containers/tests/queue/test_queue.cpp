
#include "queue.hpp"
//#include "utility.hpp"

int main()
{
	ft::list<int> mylist (2,200);

	//ft::queue<int> que(mylist);
	//ft::queue<int> plov(mylist);
	std::cout << "create queue with values of mylist:\n";
	ft::queue<int> zzz(mylist);
	std::cout << "head: " << zzz.front() << std::endl;
	std::cout << "tail: " << zzz.back() << std::endl;
	std::cout << "after push(20): \n";
	zzz.push(20);
	std::cout << "head: " << zzz.front() << std::endl;
	std::cout << "tail: " << zzz.back() << std::endl;

	//std::cout << 
}