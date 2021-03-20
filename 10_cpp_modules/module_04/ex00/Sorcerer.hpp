
#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include <string>
# include "Victim.hpp"

# define GREEN   "\033[32m"      /* Green */
# define RED     "\033[31m"      /* Red */
# define RESET   "\033[0m"

class Victim;

class Sorcerer
{
	public:
		Sorcerer(std::string name, std::string title);
		~Sorcerer(void);
		Sorcerer(const Sorcerer& obj);
		Sorcerer& operator = (const Sorcerer& obj);

		std::string		get_name(void) const;
		void			set_name(std::string name);
		std::string		get_title(void) const;
		void			set_title(std::string title);
		void			introduction(void);
		void			polymorph(const Victim & victim) const;

	private:
		Sorcerer(void);
		std::string _name;
		std::string _title;
};

	std::ostream& operator << (std::ostream& z, const Sorcerer& obj);

#endif