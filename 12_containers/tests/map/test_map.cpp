
#include "utility.hpp"
#include "map.hpp"
#include <iterator>

int main()
{
	fill_info("map");
	print_test_name("default constructor test", "map<int, int> map;");

	std::map<int, int> stl_map;
	ft::map<int, int> my_map;
	print_both_maps(&stl_map, &my_map);
	// empty test
	print_test_name("empty test", "map.empty();");
	std::cout << "is stl map empty ? : " << stl_map.empty() << "\n";
	std::cout << "is my map empty ? : " << my_map.empty() << "\n";


	print_test_name("empty container 'get value' test", "std::cout << map[10]");
	std::cout << "get value by key 10 (STL) : " << stl_map[10] << ";\n";
	std::cout << "get valut by key 10 (ft) : " << my_map[10] << ";\n";

	// empty test
	print_test_name("empty test", "map.empty();");
	std::cout << "is stl map empty ? : " << stl_map.empty() << "\n";
	std::cout << "is my map empty ? : " << my_map.empty() << "\n";

	// insert value by [], access with []
	print_test_name("empty container 'set value' and element access test", "std::cout << map[10] = 20");
	stl_map[10] = 20; my_map[10] = 20;
	std::cout << "set value of key 10 (STL): " << stl_map[10] << ";\n";
	std::cout << "set value of key 10 (ft): " << my_map[10] << ";\n";
	
	// insert with hint
	print_test_name("insert with hint test", "std::pair<int, int> new_pair(55, -55), map.insert(pair)");
	std::pair<int, int> new_pair1(15, 0);
	stl_map.insert(stl_map.begin(), new_pair1);
	my_map.insert(my_map.begin(), new_pair1);
	
	print_both_maps(&stl_map, &my_map);

	// insert single value with pair
	print_test_name("insert single element test", "std::pair<int, int> new_pair(55, -55), map.insert(pair)");
	std::pair<int, int> new_pair(55, -55);
	stl_map.insert(new_pair); my_map.insert(new_pair);

	print_both_maps(&stl_map, &my_map);

	// insert three values
	print_test_name("insert more single element test", "map[-20] = 2; map[4] = 1; map[0] = -1;");
	stl_map[-20] = 2; stl_map[4] = 1; stl_map[0] = -1;
	my_map[-20] = 2; my_map[4] = 1; my_map[0] = -1;

	print_both_maps(&stl_map, &my_map);

	// change value with []
	print_test_name("refresh value test", "set first two as 99 and 98");
	stl_map.begin()->second = 99; (++stl_map.begin())->second = 98;
	my_map.begin()->second = 99; (++my_map.begin())->second = 98;

	print_both_maps(&stl_map, &my_map);

	// insert value with iterators, + one key is also in container (so refresh value)
	print_test_name("insert value with iterators test", "insert(iterator start, iterator finish)");
	std::map<int, int> help_std_map;
	help_std_map[-300] = 2; help_std_map[15] = -111; help_std_map[2] = 2;
	
	stl_map.insert(help_std_map.begin(), help_std_map.end());
	my_map.insert(help_std_map.begin(), help_std_map.end());
	
	print_both_maps(&stl_map, &my_map);

	// assign constructor test
	print_test_name("assign constructor test", "map_assign<int, int> = prev_map");
	std::map<int, int> stl_map_assign;
	stl_map_assign = stl_map;
	ft::map<int, int> my_map_assign;
	my_map_assign = my_map;
	print_both_maps(&stl_map_assign, &my_map_assign);

	// copy constructor test
	print_test_name("copy constructor test", "map_copy<int, int>(prev_map)");
	std::map<int, int> stl_map_copy(stl_map);
	ft::map<int, int> my_map_copy(my_map);
	print_both_maps(&stl_map_copy, &my_map_copy);

	// iterator constructor
	print_test_name("iterator constructor test", "map_iter<int, int>(prev_map.begin(), prev_map.end())");
	std::map<int, int> stl_map_iter(stl_map.begin(), stl_map.end());
	ft::map<int, int> my_map_iter(my_map.begin(), my_map.end());
	print_both_maps(&stl_map_iter, &my_map_iter);

	// erase by existing key
	print_test_name("erase by existing key test", "map_iter.erase(15)");
	size_t result_stl = stl_map_iter.erase(15);
	size_t result_my = my_map_iter.erase(15);
	std::cout << "stl result: " << result_stl << "\n";
	std::cout << "my result: " << result_my << "\n";
	print_both_maps(&stl_map_iter, &my_map_iter);

	// erase by nonexisting key
	print_test_name("erase by nonexisting key test", "map_iter.erase(10000)");
	size_t result_s = stl_map_iter.erase(10000);
	size_t result_m = my_map_iter.erase(10000);
	std::cout << "stl result: " << result_s << "\n";
	std::cout << "my result: " << result_m << "\n";
	print_both_maps(&stl_map_iter, &my_map_iter);

	// erase by iterator
	print_test_name("erase by iterator", "map_iter.erase(++map.begin())");
	std::map<int, int>::iterator er = ++stl_map.begin();
	ft::map<int, int>::iterator mer = ++my_map.begin();
	stl_map_iter.erase(er);
	my_map_iter.erase(mer);
	print_both_maps(&stl_map_iter, &my_map_iter);

	//erase by range of iterators
	print_test_name("erase by range of iterators", "map_iter.erase(map.begin(), ++++map.begin())");
	stl_map_iter.erase(stl_map_iter.begin(), ++++++stl_map_iter.begin());
	my_map_iter.erase(my_map_iter.begin(), ++++++my_map_iter.begin());
	std::cout << "MAP_ITER BEFORE SWAP WITH MAP: \n";
	print_both_maps(&stl_map_iter, &my_map_iter);

	// swap test
	print_test_name("swap test", "map_iter.swap(map)");
	stl_map_iter.swap(stl_map);
	my_map_iter.swap(my_map);
	std::cout << "MAP: \n";
	print_both_maps(&stl_map, &my_map);
	std::cout << "MAP_ITER AFTER SWAP WITH MAP: \n";
	print_both_maps(&stl_map_iter, &my_map_iter);

	// find
	print_test_name("find by key test", "map_iter.find(55)");
	std::cout << "stl result (iterator->first) " << stl_map_iter.find(55)->first << "\n";
	std::cout << "my result (iterator->first) " << my_map_iter.find(55)->first << "\n";
	// find const
	print_test_name("find by key test const", "map_iter.find(55)");
	std::map<int, int>::const_iterator stl_ci = stl_map_iter.find(55);
	ft::map<int, int>::const_iterator my_ci = my_map_iter.find(55);
	std::cout << "stl result (const_iterator->first) " << stl_ci->first << "\n";
	std::cout << "my result (const_iterator->first) " << my_ci->first << "\n";
	//count +
	print_test_name("count existing key test", "map_iter.count(55)");
	std::cout << "stl result " << stl_map_iter.count(55) << "\n";
	std::cout << "my result " << my_map_iter.count(55) << "\n";

	//count - 
	print_test_name("count nonexisting key test", "map_iter.count(100000)");
	std::cout << "stl result " << stl_map_iter.count(100000) << "\n";
	std::cout << "my result " << my_map_iter.count(100000) << "\n";

	// lower bound
	print_test_name("lower bound test", "map_iter.lower bound(10)");
	std::cout << "stl lower bound result " << stl_map_iter.lower_bound(10)->first << "\n";
	std::cout << "my lower bound result " << my_map_iter.lower_bound(10)->first << "\n";
	// upper bound
	print_test_name("upper bound test", "map_iter.lower bound(10)");
	std::cout << "stl upper bound result " << stl_map_iter.upper_bound(10)->first << "\n";
	std::cout << "my upper bound result " << my_map_iter.upper_bound(10)->first << "\n";
	// upper bound const
	print_test_name("upper bound const test", "const_iterator = my_map_iter.upper_bound(10)");
	ft::map<int,int>::const_iterator cmiub = my_map_iter.upper_bound(10);
	std::cout << "upper bound const value: " << cmiub->first << " => " << cmiub->second << std::endl;
	// lower bound const
	print_test_name("lower bound const test", "const_iterator = my_map_iter.lower_bound(10)");
	ft::map<int,int>::const_iterator cmilb = my_map_iter.lower_bound(10);
	std::cout << "lower bound const value: " << cmilb->first << " => " << cmiub->second << std::endl;
	// upper bound
	print_test_name("upper bound test", "map_iter.lower bound(10000)");
	std::map<int,int>::iterator siub = stl_map_iter.upper_bound(10000);
	std::map<int,int>::iterator sie = stl_map_iter.end();
	if (siub == sie)
		std::cout << "stl: can't find upper bound, returned end iterator\n";
	ft::map<int,int>::iterator miub = my_map_iter.upper_bound(10000);
	ft::map<int,int>::iterator mie = my_map_iter.end();
	if (miub == mie)
		std::cout << "my: can't find upper bound, returned end iterator\n";
	// equal range
	print_test_name("equal range test", "map_iter.equal range(10)");
	std::cout << "stl equal_range result " << stl_map_iter.equal_range(10).first->first << "\n";
	std::cout << "my equal_range result " << my_map_iter.equal_range(10).first->first << "\n";

	//reverse iterator:
	print_test_name("reverse iterator test", "create + iter");
	print_map_reverse(&stl_map_iter, STL);
	print_map_reverse(&my_map_iter, MINE);

	// const begin test
	print_test_name("const iterator test", "const_iterator = map.begin()");
	ft::map<int,int>::const_iterator con_iter = my_map_iter.begin();
	std::cout << "const_iterator: " << con_iter->first << " => " << con_iter->second << ";\n";
	print_test_name("const reverse iterator test", "const_reverse_iterator = map.rbegin()");

	ft::map<int,int>::const_reverse_iterator con_rev_iter = my_map_iter.rbegin();
	std::cout << "const_reverse_iterator: " << con_rev_iter->first << " => " << con_rev_iter->second << ";\n";
	
	// clear test
	print_test_name("clear test", "map_iter.clear()");
	stl_map_iter.clear();
	my_map_iter.clear();
	print_both_maps(&stl_map_iter, &my_map_iter);
	// map container with key_compare as std::greater<int>
	{
		print_test_name("map container with key_compare as std::greater<int>", "map<int, int, std::greater<int> >");
	
		std::map< int, int, std::greater<int> > stl_greater;
		ft::map< int, int, std::greater<int> > my_greater;
		stl_greater[-10] = 2; stl_greater[5] = 1; stl_greater[20] = 12;
		my_greater[-10] = 2; my_greater[5] = 1; my_greater[20] = 12;
		print_map(&stl_greater, STL);
		std::cout << STL.color << "size " << stl_greater.size() << RESET << ";" << std::endl;
		//print_iterable_reverse(arr, STL);
		print_map(&my_greater, MINE);
		std::cout << MINE.color << "size " << my_greater.size() << RESET << ";" << std::endl;
	}
}
