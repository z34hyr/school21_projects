
#include "utility.hpp"

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

int main()
{
	STL.owner = "STL";
	STL.color = GREEN;
	MINE.owner = "my";
	MINE.color = CYAN;

	fill_info("list");

	std::list<int> meow;//(5,11);
	meow.insert(++meow.begin(), 3, 11);
	std::list<int> some(5, 5);

	meow.splice(++meow.begin(), some, ++some.begin(), ++(++(++some.begin())));
	//meow.splice(--meow.end(), some);
	//meow.resize(0);
	std::cout << "std size: " << meow.size() << std::endl;
	//meow.erase(meow.end());
	print_iterable(&meow, STL);
	print_iterable(&some, STL);

	ft::list<int> mymy(5, 2);
	ft::list<int> za(6, 15);
	mymy.splice(--mymy.end(), za);
	
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
	
	mymy.insert(mymy.begin(), 999);
	mymy.insert(mymy.begin(), 999);
	print_iterable(&mymy, MINE);
	mymy.resize(0);
	print_iterable(&mymy, MINE);

	mymy.insert(mymy.begin(), 1, 888);
	print_iterable(&mymy, MINE);
	//mymy.erase(++mymy.begin());
	//mymy.erase(--mymy.end());
	print_iterable(&mymy, MINE);
	mymy.insert(mymy.end(), 3, 600);
	mymy.erase(--(--mymy.end()));
	ft::list<int> zahar(2, 1);

	mymy.insert(mymy.begin(), zahar.begin(), zahar.end());
	print_iterable(&mymy, MINE);
	//mymy.swap(zahar);
	mymy.insert(++mymy.begin(), 1, 11);
	std::cout << *(--mymy.end()) << std::endl;
	print_iterable(&mymy, MINE);
	//mymy.erase(mymy.begin());
	//std::
	//mymy.erase(++(++mymy.begin()), mymy.end());
	std::cout << *++mymy.begin() << std::endl;
	mymy.erase(++(++mymy.begin()), --mymy.end());
	std::cout << mymy.size() << std::endl;
	//std::cout << *mymy.erase(++mymy.begin()) << std::endl;
	print_iterable(&mymy, MINE);
	mymy.assign(5, 12);
	print_iterable(&mymy, MINE);
	ft::list<int> tofill(5, 7);
	mymy.splice(++mymy.begin(), tofill, ++tofill.begin());
	mymy.splice(mymy.begin(), tofill, tofill.begin(), --tofill.end());
	//mymy.assign(tofill.begin(), tofill.end());
	print_iterable(&mymy, MINE);
	//print_iterable(&tofill, MINE);
	//mymy.remove(7);
	//mymy.remove(12);
	std::cout << mymy.size() << std::endl;
	mymy.unique();
	std::cout << mymy.size() << std::endl;
	print_iterable(&mymy, MINE);

	ft::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	first.merge(first);
	print_iterable(&first, MINE);
	
	// (second is now empty)

	second.push_back (2.1);
	print_iterable(&second, MINE);
	
	first.merge(second,mycomparison);
	print_iterable(&first, MINE);
	first.reverse();
	print_iterable(&first, MINE);
	//mymy.clear();
	//std::cout << std::count(mymy.begin(), mymy.end(), 15) << std::endl;
	// insert in the begining
	
	

  ft::list<std::string> mylist;
  ft::list<std::string>::iterator it;
 mylist.push_back ("Tarez");
  mylist.push_back ("one");
  mylist.push_back ("two");
  mylist.push_back ("three");
  mylist.push_back ("Taree");
  mylist.push_back ("Tzree");
  mylist.push_back ("Txree");

  mylist.sort();

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  mylist.sort(compare_nocase);

  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  ft::list<int>::iterator it1;
// int myints[]= {15,36,7,17,20,39,4,1};
//   ft::list<int> mylist1 (myints,myints+8);   // 15 36 7 17 20 39 4 1
ft::list<int> mylist1;
mylist1.push_back(15);
mylist1.push_back(36);
mylist1.push_back(7);
mylist1.push_back(17);
mylist1.push_back(20);
mylist1.push_back(39);
mylist1.push_back(4);
mylist1.push_back(1);
ft::list<int> cop;
cop = mylist1;
ft::list<int> zop(cop);
print_iterable(&cop, MINE);
std::cout << zop.size() << "\n";
print_iterable(&zop, MINE);
std::cout << cop.size() << "\n";
  mylist1.remove_if (single_digit);           // 15 36 17 20 39
print_iterable(&mylist1, MINE);
  mylist1.remove_if (is_odd());               // 36 20
//mylist1.reverse();
ft::swap(cop, mylist1);

print_iterable(&mylist1, MINE);
print_iterable(&cop, MINE);
ft::swap(cop, mylist1);

print_iterable(&mylist1, MINE);
print_iterable(&cop, MINE);
  return 0;
}
