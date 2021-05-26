
#include "utility.hpp"
#include "list.hpp"

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

bool is_less(int first, int second);


int main()
{
	fill_info("list");

	// std::list<int> meow;//(5,11);
	// print_iterable(&meow, STL);
	// meow.insert(++meow.begin(), 3, 11);
	// std::list<int> some(5, 5);
	// std::list<int>::iterator zza = ++meow.begin();
	// std::cout << *zza << ";\n";

	// meow.splice(++meow.begin(), some, ++some.begin(), ++(++(++some.begin())));
	//meow.splice(--meow.end(), some);
	//meow.resize(0);
	// std::cout << "std size: " << meow.size() << std::endl;
	// //meow.erase(meow.end());
	// print_iterable(&meow, STL);
	// print_iterable(&some, STL);

	// print empty list 
	print_test_name("create and print empty list", "list<int> mymy1;");
	ft::list<int> mymy1;
	print_iterable(&mymy1, MINE);

	// add value to empty list
	print_test_name("push_back value to an empty list", "mymy1.push_back(22);");
	mymy1.push_back(22);
	print_iterable(&mymy1, MINE);

	// push_front test
	print_test_name("push_front value test", "mymy1.push_front(404);\npush_front(808);\npush_front(1200);");
	mymy1.push_front(404);
	mymy1.push_front(808);
	mymy1.push_front(1200);
	print_iterable(&mymy1, MINE);

	// pop_front test
	print_test_name("pop_front value test", "mymy1.pop_front()");
	mymy1.pop_front();
	print_iterable(&mymy1, MINE);

	// pop_back test
	print_test_name("pop_back value test", "mymy1.pop_back()");
	mymy1.pop_back();
	print_iterable(&mymy1, MINE);

	// assign test
	print_test_name("assign int diapasone test", "mymy1.assign(1, 42);");
	mymy1.assign(1, 42);
	print_iterable(&mymy1, MINE);

	print_test_name("assign iterator diapasone test", "ft::list<int> iter_list(5, 5);\nmymy1.assign(iter_list.begin(), iter_list.end());");
	ft::list<int> iter_list(5, 5);
	mymy1.assign(iter_list.begin(), iter_list.end());
	print_iterable(&mymy1, MINE);
	std::cout << "\niter_list is not deleted with assignation:\n";
	print_iterable(&iter_list, MINE);

	// create list with integer diapasone
	print_test_name("create list with int diapasone", "list<int> mymy(5, 2);");
 	ft::list<int> mymy(5, 2);
	print_iterable(&mymy, MINE);

	// create list with iterator diapasone
	print_test_name("create list with iterator diapasone", "list_iter(++mymy.begin(), --mymy.end();");
	ft::list<int> list_iter(++mymy.begin(), --mymy.end());
	print_iterable(&list_iter, MINE);

	// splice test
	print_test_name("splice test #1", "mymy.splice(--mymy.end(), list(6, 16))");
 	ft::list<int> za(6, 15);
 	mymy.splice(--mymy.end(), za);
	print_iterable(&mymy, MINE);

 	// test resize:
 	print_test_name("resize test #1", "resize(list.size()");
 	print_iterable(&mymy, MINE);
	std::cout << "size before: " << mymy.size() << std::endl;	
	mymy.resize(mymy.size());
	print_iterable(&mymy, MINE);
	std::cout << "size after: " << mymy.size() << std::endl;

	print_test_name("resize test #2", "resize(n > list.size()");
	print_iterable(&mymy, MINE);
	std::cout << "size before: " << mymy.size() << std::endl;	
	mymy.resize(mymy.size() + 6, 99);
	print_iterable(&mymy, MINE);
	std::cout << "size after: " << mymy.size() << std::endl;
	print_test_name("resize test #3", "resize(n < list.size()");
	
	print_iterable(&mymy, MINE);
	std::cout << "size before: " << mymy.size() << std::endl;	
	mymy.resize(2);
	print_iterable(&mymy, MINE);
	std::cout << "size after: " << mymy.size() << std::endl;

	print_test_name("resize test #4", "resize(0)");
	print_iterable(&mymy, MINE);
	std::cout << "size before: " << mymy.size() << std::endl;	
	mymy.resize(0);
	print_iterable(&mymy, MINE);
	std::cout << "size after: " << mymy.size() << std::endl;
	
	// insert test
	print_test_name("insert test #1", "insert(iterator mymy.begin(), size_type 1, const value_type& 888)");
	mymy.insert(mymy.begin(), 1, 888);
	print_iterable(&mymy, MINE);

	print_test_name("insert test #2", "insert(iterator mymy.end(), size_type 3, const value_type& 600)");
	mymy.insert(mymy.end(), 3, 600);
	std::cout << "LAST ELEMENT: " << *(--mymy.end()) << std::endl;
	print_test_name("insert test #3", "insert(iterator mymy.begin(), size_type 1, const value_type& 1888)");
	mymy.insert(mymy.begin(), 1, 1888);
	std::cout << "LAST ELEMENT: " << *(--mymy.end()) << std::endl;
	print_iterable(&mymy, MINE);

	// erase test
	print_test_name("erase test #1", "mymy.erase(--mymy.end());");
	mymy.erase(--mymy.end());
	print_iterable(&mymy, MINE);
	print_test_name("erase test #2", "mymy.erase(--(--mymy.end()));");
	mymy.erase(--(--mymy.end()));	
	print_iterable(&mymy, MINE);
	std::cout << "LAST ELEMENT: " << *(--mymy.end()) << std::endl;
	ft::list<int> zahar(2, 1);

	// insert test
	print_test_name("insert test #4", "insert (iterator position, InputIterator first, InputIterator last)");
	mymy.insert(mymy.begin(), zahar.begin(), zahar.end());
	print_iterable(&mymy, MINE);
	std::cout << "LAST ELEMENT: " << *(--mymy.end()) << std::endl;

	print_test_name("insert test #5", "insert (iterator position, const value_type& val");
	mymy.insert(++++mymy.begin(), 777);
 	print_iterable(&mymy, MINE);

 	ft::list<int> tofill(5, 7);

	// splice test
	print_test_name("splice test #2", "ft::list<int> tofill(5, 7);\nmymy.splice(++mymy.begin(), tofill, ++tofill.begin());");
 	mymy.splice(++mymy.begin(), tofill, ++tofill.begin());
	print_iterable(&mymy, MINE);
	std::cout << "\nlist 'tofill' after this splice: \n";
	print_iterable(&tofill, MINE);

	// erase test
	print_test_name("erase test #3", "mymy.erase(++mymy.begin(), --(--mymy.end()));");
	mymy.erase(++mymy.begin(), --(--mymy.end()));	
	//mymy.erase(++mymy.begin(), (mymy.end()));	
	print_iterable(&mymy, MINE);

	// splice test
	print_test_name("splice test #3", "ft::list<int> tofill(5, 7);\nmymy.splice(mymy.begin(), tofill, tofill.begin(), tofill.end());");
 	mymy.splice(mymy.begin(), tofill, tofill.begin(), tofill.end());
 	print_iterable(&mymy, MINE);
	std::cout << "\nlist 'tofill' after this splice: \n";
	print_iterable(&tofill, MINE);
	
	//remove test
	print_test_name("remove test #1", "mymy.remove(7)");
	mymy.remove(7);
	print_iterable(&mymy, MINE);
	print_test_name("remove test #1", "mymy.remove(12)");
	mymy.remove(12);
	print_iterable(&mymy, MINE);
	print_test_name("remove test #3", "mymy.remove(888)");
	mymy.remove(888);
	print_iterable(&mymy, MINE);
// 	std::cout << mymy.size() << std::endl;
// 	mymy.unique();
// 	std::cout << mymy.size() << std::endl;
 	

 	ft::list<double> first, second;

 	first.push_back (3.1);
 	first.push_back (2.2);
 	first.push_back (2.9);

 	second.push_back (3.7);
 	second.push_back (7.1);
 	second.push_back (1.4);

 	first.sort();
 	second.sort();
	//print_iterable(&first, MINE);

	// merge
	print_test_name("merge test #1", "first.merge(second)");
	std::cout << "\nfirst before merge:\n";
	print_iterable(&first, MINE);
	std::cout << "\nsecond before merge:\n";
	print_iterable(&second, MINE);
 	first.merge(second);
	std::cout << "\nfirst after merge:\n";
 	print_iterable(&first, MINE);
	std::cout << "\nsecond after merge:\n";
 	print_iterable(&second, MINE);
	
 	// (second is now empty)

 	second.push_back (2.1);
 	//print_iterable(&second, MINE);
	print_test_name("merge test #2", "second.push_back (2.1);\nfirst.merge(second, mycomparison)");
 	first.merge(second,mycomparison);
 	print_iterable(&first, MINE);
	
	ft::list<std::string> mylist;
	ft::list<std::string>::iterator it;
	mylist.push_back ("Tarez");
	mylist.push_back ("one");
	mylist.push_back ("two");
	mylist.push_back ("three");
	mylist.push_back ("Taree");
	mylist.push_back ("Tzree");
	mylist.push_back ("Txree");

	// sort test
	print_test_name("sort test #1", "mylist.sort();");
	std::cout << "\nmylist before sort:\n";
	print_iterable(&mylist, MINE);
	mylist.sort();
	std::cout << "\nmylist after sort:\n";
	print_iterable(&mylist, MINE);
	print_test_name("sort test #1", "mylist.sort(compare_nocase);");
   	mylist.sort(compare_nocase);
	print_iterable(&mylist, MINE);

  ft::list<int>::iterator it1;
//int myints[]= {15,36,7,17,20,39,4,1};
//ft::list<int> mylist1 (myints,myints+8);   // 15 36 7 17 20 39 4 1
ft::list<int> mylist1;
mylist1.push_back(15);
mylist1.push_back(36);
mylist1.push_back(7);
mylist1.push_back(17);
mylist1.push_back(20);
mylist1.push_back(39);
mylist1.push_back(4);

//assignment overloader test
ft::list<int> cop;
print_test_name("assignment overloader test", "cop = mylist1;");
std::cout << "\nmylist :\n";
print_iterable(&mylist1, MINE);

cop = mylist1;
std::cout << "\ncop :\n";
print_iterable(&cop, MINE);
cop.reverse();
print_iterable(&cop, MINE);
//std::cout << "end: " << *--cop.end() << ";\n";

//copy constructoor test
ft::list<int> zop(cop);
print_test_name("assignment overloader test", "list<int> zop(cop);");
print_iterable(&zop, MINE);

// reverse test
print_test_name("reverse test", "lzop.reverse();");
zop.reverse();
print_test_name("remove_if test", "mylist1.remove_if (single_digit); ");

// remove_if test
mylist1.remove_if (single_digit);           // 15 36 17 20 39
print_iterable(&mylist1, MINE);
print_test_name("remove_if test", "mylist1.remove_if (is_odd()); ");
mylist1.remove_if (is_odd());               // 36 20
print_iterable(&mylist1, MINE);
//mylist1.reverse();

// swap test:
print_test_name("swap test", "ft::swap(cop, mylist1);");
std::cout << "LISTS BEFORE SWAP:\n";
print_iterable(&mylist1, MINE);
print_iterable(&cop, MINE);
ft::swap(cop, mylist1);
std::cout << "\nLISTS AFTER SWAP:\n";
print_iterable(&mylist1, MINE);
print_iterable(&cop, MINE);

// unique test:
print_test_name("unique test", "test_unique.unique();");
ft::list<int> test_unique;
test_unique.push_back(15);
test_unique.push_back(36);
test_unique.push_back(7);
test_unique.push_back(17);
test_unique.push_back(20);
test_unique.push_back(17);
test_unique.push_back(39);
test_unique.push_back(4);
test_unique.push_back(17);
std::cout << "test_unique.size = " << test_unique.size() << "\n";
test_unique.sort();
print_iterable(&test_unique, MINE);
print_iterable_reverse(&test_unique, MINE);
ft::list<int>::const_reverse_iterator iz_b = test_unique.rbegin();
ft::list<int>::const_reverse_iterator iz_e = test_unique.rend();
std::cout << "by cost_reverse_iterator:\n";
while (iz_b != iz_e)
{
	std::cout << *iz_b << " ";
	++iz_b;
}
std::cout << "\n";
test_unique.unique();
print_iterable(&test_unique, MINE);
print_test_name("unique with predicate test", "test_unique.unique(is_less);");
test_unique.unique(is_less);
print_iterable(&test_unique, MINE);

print_test_name("operations comparison test", "==, !=, >, <");
ft::list<int> l1, l2;
l1.push_front(1); l2.push_front(1);
l1.push_front(3); l2.push_front(3);
std::cout << "l1.push_front(1); l2.push_front(1);\n\
l1.push_front(3); l2.push_front(3);\n";
if (l1 == l2)
	std::cout << "l1 = l2\n";
l1.push_front(3);
std::cout << "l1.push_front(3);\n";
if (l1 != l2)
	std::cout << "l1 != l2\n";
if (l2 < l1)
	std::cout << "l2 < l1\n";
if (l1 > l2)
	std::cout << "l1 > l2\n";
if (l2 <= l1)
	std::cout << "l2 <= l1\n";
if (l1 >= l2)
	std::cout << "l1 >= l2\n";

return 0;
}

bool is_less(int first, int second)
{
	return (first - second <= 3 ? true : false);
};