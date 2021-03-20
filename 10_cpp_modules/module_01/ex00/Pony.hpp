#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>
# include <string>

class Pony
{
    public:
		Pony(void);
		~Pony(void);

		void    ponyOnTheHeap(void);
		void    ponyOnTheStack(void);
		static void		add_pony(void);
		static void		delete_pony(void);
		static uint16_t	get_counter(void);

	private:
		static uint16_t		_ponies_counter;
		std::string		_name;
		std::string		_color;
		uint16_t		_height;
		uint16_t		_weight;
		uint16_t		_age;
		std::string		_breed;
};

#endif