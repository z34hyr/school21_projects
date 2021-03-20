
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
# include <algorithm>

#include "mutantstack.hpp"

// int	main()
// {
// 	MutantStack<int> new_stack;
// 	new_stack.push(100);
// 	new_stack.push(150);
// 	new_stack.push(122);
// 	new_stack.push(1);
// 	MutantStack<int>::iterator iter_begin = new_stack.begin();
// 	MutantStack<int>::iterator iter_end = new_stack.end();
// 	while (iter_begin != iter_end)
// 	{
// 		std::cout << *iter_begin << std::endl;
// 		iter_begin++;
// 	}
// }

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(21);
	mstack.push(42);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "s size vs mstack size: " << s.size() << " : " << mstack.size() << std::endl;
	return 0;
}