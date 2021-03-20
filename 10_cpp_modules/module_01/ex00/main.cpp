
#include "Pony.hpp"

void    ponyOnTheHeap(void)
{
	std::cout << "	We're in ponyOnTheHeap: " << std::endl; 
	Pony*	new_heap_pony = new Pony;
	delete new_heap_pony;
	std::cout << "	ponies counter befor exit: " << Pony::get_counter() << std::endl;
}

void    ponyOnTheStack(void)
{
	std::cout << "	We're in ponyOnTheStack: " << std::endl; 
    Pony    new_stack_pony;
	std::cout << "	ponies counter before exit: " << Pony::get_counter() << std::endl;
}

int     main(void)
{
	std::cout << "Creating pony on heap:" << std::endl;
	ponyOnTheHeap();
	std::cout << "So we're out of ponyOnTheHeap (instance delete manualy), ponies counter: " << Pony::get_counter() << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "Creating pony on stack:" << std::endl;
	ponyOnTheStack();
	std::cout << "So we're out of ponyOnTheStack (instance deletes automatically), so ponies counter: " << Pony::get_counter() << std::endl;
}
