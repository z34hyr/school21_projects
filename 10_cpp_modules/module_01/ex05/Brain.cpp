#include "Brain.hpp"
#include <memory>
# include <sstream> 

Brain::Brain(void)
{
	const void * address = static_cast<const void*>(this);
	std::stringstream ss;
	ss << address;
	this->_address = ss.str();
    return;
}

Brain::~Brain(void)
{
    return;
}

std::string Brain::identify(void) const
{
	return (this->_address);
}
