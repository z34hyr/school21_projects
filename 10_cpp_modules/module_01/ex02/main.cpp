
#include "ZombieEvent.hpp"

std::string	name_pool[10] = {"Alex", "Boris", "Igor", "Sergey", "Kesha", \
		"Natasha", "Katerina", "Lena", "Nastasya", "Olga"};

void	randomChump(void)
{
    Zombie*		new_one;
	ZombieEvent	new_event;

	new_one = new_event.newZombie(name_pool[std::rand() % 10]);
	new_event.setZombieType("some random dude", new_one);
	std::cout << "Anounce ON HEAP zombie: " ;
	new_one->announce();
    delete new_one;
}

int main(void)
{
	std::string	inp_type;
	ZombieEvent local_event;
	randomChump();
	Zombie		handly("Innokentii");
	local_event.setZombieType("newborn zombie", &handly);
	std::cout << "Anounce ON STACK zombie: " << std::endl;
	handly.announce();
	local_event.setZombieType("grown up zombie", &handly);
	handly.announce();
}
