
#include "utility.hpp"
#include <iterator>

int main()
{
	std::map<int, int> lol;
	lol[0] = 1;
	lol[1] = 2;
	lol[5] = 12;
	lol[3] = 22;
	
	std::cout << "nonexisted val: " << lol[11] << std::endl;
	std::cout << "size: " << lol.size() << std::endl;
	std::map<int, int>::iterator lol_b = lol.begin();
	std::map<int, int>::iterator lol_e = lol.end();
	while (lol_b != lol_e)
	{
		std::cout << lol_b->first << " => " << lol_b->second << std::endl;
		++lol_b;
	}
	//std::pair<int, int> test_pair;
	// test_pair.first = 11;
	// test_pair.second = 12;
	//test_pair = std::make_pair(11, 13);
	//std::cout << "default pair: " << test_pair.first << " " << test_pair.second << std::endl;
	//ft::map<int, int, std::greater<int> > lulz;
	ft::map<int, int> lulz;
	lulz[1] = 2;
	std::pair<ft::map<int, int>::iterator, bool> rez;
	std::pair<int, int> p1(2, 22);
	std::pair<int, int> p2(11, 22);
	lulz[-1] = 2;
	lulz[10] = 2;
	lulz[1] = 999;
	lulz.insert(lulz.begin(), p2);

	//lulz.erase(-1);
	//lulz.erase(++lulz.begin());
	rez = lulz.insert(p1);
	if (rez.second)
		std::cout << "	Added some new value\n";
	else
		std::cout << "	Just refresh value\n";
	//lulz.erase(++lulz.begin(), --lulz.end());
	ft::map<int,int>::key_compare kk = lulz.key_comp();
	
	//std::iterator::InputIterator a;
	ft::map<int, int> to_add;
	to_add[-99] = 19; to_add[13] = 2; to_add[0] = 191; to_add[66] = 19;
	lulz.insert(to_add.begin(), to_add.end());
	ft::map<int, int>::iterator i_b = lulz.begin();
	ft::map<int, int>::iterator i_e = lulz.end();
	ft::map<int, int>::iterator to_find = lulz.find(1);
	if (lulz.count(-99))
		std::cout << "I found smth!\n";
	if (to_find != i_e)
	{
		std::cout << "Found val: " << to_find->second << "\n";
	}
	while (i_b != i_e)
	{
		std::cout << "key: " << i_b->first << "; val: " << i_b->second << "\n";
		++i_b;
	}
	ft::map<int, int>::iterator to_lower = lulz.lower_bound(2);
	ft::map<int, int>::iterator to_upper = lulz.upper_bound(2);
	if (to_lower != i_e)
	{
		std::cout << "lower bound: " << to_lower->first << "\n";
	}
	if (to_upper != i_e)
	{
		std::cout << "upper bound: " << to_upper->first << "\n";
	}
	std::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> er = lulz.equal_range(1);
	if (er.first != i_e)
	{
		std::cout << "found some:" << er.first->first << "\n";
	}
	// ft::map<int, int>::const_iterator to_lower_const = lulz.lower_bound(-200);
	// if (to_lower_const != i_e)
	// {
	// 	std::cout << "lower bound: " << to_lower_const->first << "\n";
	// }
	std::map<int, int> a;
	a[1] = 10;
	a[5] = 2;
	a[0] = 3;
	std::map<int, int>::iterator au = a.upper_bound(1);
	std::map<int, int>::iterator al = a.lower_bound(1);
	std::map<int,int>::iterator aie = a.end();
	if (au != aie)
		std::cout << "upper:! " << au->first << std::endl;
	if (al != aie)
		std::cout << "lower:! " << al->first << std::endl;
}
