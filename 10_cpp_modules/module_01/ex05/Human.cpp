
#include "Human.hpp"

Human::Human(void)
{
    return;
}

Human::~Human(void)
{
    return;
}

Brain	Human::getBrain(void)
{
	return (this->brain);
}

std::string	Human::identify(void) const
{
	return (this->brain.identify());
}
