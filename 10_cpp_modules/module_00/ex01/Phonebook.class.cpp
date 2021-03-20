
#include "Phonebook.class.hpp"

Phonebook::Phonebook(void)
{
    return;
}

Phonebook::~Phonebook(void)
{
    return;
}

void Phonebook::f_add_contact(uint16_t* counter, uint16_t const book_size)
{
	uint16_t i;

	i = 0;
	if (*counter == book_size)
	{
		std::cout << "Sorry, you can't add new contact \
- pooPhone is out of memory." << std::endl;
		return;
	}
	std::cout << "=== OK, adding a contact ===" << std::endl;
	//for (uint16_t i = 0; i < 11; i += 1)
	while (i < 11)
	{
		std::cout << "Type " << this->_field_name[i] << " : ";
		//std::cin >> this->field_value[i];
		std::getline(std::cin, this->_field_value[i]);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return;
		}
		if (this->_field_value[i].empty())
			std::cout << "Insert smth!" << std::endl;
		else
			i += 1;
	}
	std::cout << "==Contact successfully created, " << *counter + 1 \
	<< " of " << book_size << " slots is busy==" << std::endl;
	*counter += 1;
	this->_cont_num = *counter;
	return;
}

void	Phonebook::f_show_short_list(void)
{
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << this->_cont_num << '|';
	for (uint16_t z = 0; z < 3; z += 1)
	{
		if (this->_field_value[z].size() <= 10)
		{
			std::cout << std::setfill(' ') << std::setw(10);
			std::cout << this->_field_value[z];
		}
		else
			std::cout << this->_field_value[z].substr(0, 9) << '.';
		std::cout << '|';
	}
	std::cout << std::endl;
	return;
}

void	Phonebook::f_show_contact(void)
{
	for (int i = 0; i < 11; i++)
		std::cout << this->_field_name[i] << " : " << this->_field_value[i] << std::endl;
}
