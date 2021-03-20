#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <string>
# include <iomanip> 

class Phonebook
{
    public:
		Phonebook(void);
		~Phonebook(void);
		void		f_add_contact(uint16_t* counter, uint16_t const book_size);
		void		f_show_short_list(void);
		void		f_show_contact(void);

	private:
		std::string			_field_value[11];
		uint16_t			_cont_num;
		std::string const	_field_name[11] = {"first name", 
											"last name",
											"nickname",
											"login",
											"postal address",
											"email address",
											"phone number",
											"birthday date",
											"favorite meal",
											"underwear color",
											"darkest secret"};
};

#endif
