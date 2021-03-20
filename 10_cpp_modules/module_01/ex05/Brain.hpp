#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Brain
{
    public:
		Brain(void);
		~Brain(void);
		std::string	identify(void) const;

	private:
		uint16_t	_iq;
		uint16_t	_weight;
		std::string _address;
};

#endif