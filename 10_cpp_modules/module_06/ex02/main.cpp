
#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>

class Base
{
	public:
		virtual ~Base(){};
};

class A: public Base{};
class B: public Base{};
class C: public Base{};

Base* generateA(void)
{
	A* a_class = new A;
	Base* base = a_class; // upcast
	std::cout << "A class has been generated" << std::endl;
	return base;
}

Base* generateB(void)
{
	B* b_class = new B;
	Base* base = b_class; // upcast
	std::cout << "B class has been generated" << std::endl;
	return base;
}

Base* generateC(void)
{
	C* c_class = new C;
	Base* base = c_class; // upcast
	std::cout << "C class has been generated" << std::endl;
	return base;
}

Base * generate(void)
{
	Base* (*generateRand[3]) () = {&generateA, &generateB, &generateC};
	return generateRand[std::rand() % 3]();
}

void identify_from_pointer(Base * p)
{
	A* is_a = dynamic_cast<A *>(p);
	if (is_a != NULL)
	{
		std::cout << "A" << std::endl;
		return;
	}
	B* is_b = dynamic_cast<B *>(p);
	if (is_b != NULL)
	{
		std::cout << "B" << std::endl;
		return;
	}
	C* is_c = dynamic_cast<C *>(p);
	if (is_c != NULL)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify_from_reference( Base & p)
{
	try
	{
		A& is_a = dynamic_cast<A &>(p);
		p = is_a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(std::exception& e){}
	try
	{
		B& is_b = dynamic_cast<B &>(p);
		p = is_b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(std::exception& e){}
	try
	{
		C& is_c = dynamic_cast<C &>(p);
		p = is_c;
		std::cout << "C" << std::endl;
		return;
	}
	catch(std::exception& e){}
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl << "---test # " << i + 1 << "---" << std::endl;
		Base* what = generate();
		std::cout << "identify_from_pointer: ";
		identify_from_pointer(what);
		std::cout << "identify_from_reference: ";
		identify_from_reference(*what);
		delete what;
	}
	return 0;
}
