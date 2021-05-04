
#include "utility.hpp"

int main()
{
	STL.owner = "STL";
	STL.color = GREEN;
	MINE.owner = "my";
	MINE.color = CYAN;

	ft::list<int> myl;
	std::list<int> lst;
	std::cout << "ret end" << std::endl;
	for (int i = 0; i < 5; i += 1)
		myl.push_back(i);
	for (int i = 0; i < 5; i += 1)
		myl.push_front(i);
	myl.pop_back();
	myl.pop_front();
	myl.pop_back();
	myl.pop_front();
	myl.push_back(999);
	std::cout << "FRONT: " << myl.front() << "; BACK: " << myl.back() << std::endl;
	std::cout << myl.max_size() << " " << lst.max_size() << std::endl;
	//std::cout << myl.front() << std::endl;
	ft::list<int>::iterator i_b = myl.begin();
	ft::list<int>::iterator i_e = myl.end();
	int i = 0;
	while (i_b != i_e)
	{
		std::cout << *i_b << " ";
		++i_b;
		i++;
	}
	std::cout << std::endl;
	std::cout << lst.front() << std::endl;
}
