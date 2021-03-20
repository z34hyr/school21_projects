#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
    public:
		Human(void);
		~Human(void);
		std::string		identify(void) const;
		Brain			getBrain();

	private:
		Brain const		brain;
		uint16_t		_iq;
		uint16_t		_weight;
};

#endif