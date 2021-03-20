

#include <iostream>
#include <string>

class Main
{
	public:
		Main(void){ std::cout << "Main created" << std::endl; };
		~Main(){ std::cout << "Main deleted" << std::endl; };
		float f;
		float	getN() { return (f);};
		void	setN(float z) { f = z; };
};

class A : public virtual Main
{
	public:
		A(void){ std::cout << "A created" << std::endl; };
		~A(){ std::cout << "A deleted" << std::endl; };
		//int	getN() { return (A::f);};
};

class B : public virtual Main
{
	public:
		B(void){ std::cout << "B created" << std::endl; };
		~B(){ std::cout << "B deleted" << std::endl; };
		//float	getN() { return (f);};
};

class C : public A, public B
{
	public:
		C(void){ std::cout << "C created" << std::endl; };
		~C(){ std::cout << "C deleted" << std::endl; };
		float f;
};

int main(void)
{
	C* cc = new C;
	
	//std::cout << cc->A::getN() << std::endl;
	//std::cout << cc->B::getN() << std::endl;
	cc->getN();
	return (1);
}