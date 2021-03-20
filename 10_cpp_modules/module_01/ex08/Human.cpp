
#include "Human.hpp"

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "meleeAttack: " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "rangedAttack: " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidatingShout: " << target << std::endl;
}
  // declare pointer to data member
  //int X::*ptiptr = &X::a;

  // declare a pointer to member function
  //void (X::* ptfptr) (int) = &X::f;
void	Human::action(std::string const & action_name, std::string const & target)
{
	void (Human::* funptr[3]) (std::string const &) = { &Human::meleeAttack, &Human::intimidatingShout, &Human::rangedAttack};
	std::string const name_mas[3] = {"meleeAttack", "intimidatingShout", "rangedAttack"};
	for (int i = 0; i < 3; i++)
	{
		if (action_name.compare(name_mas[i]) == 0)
		{
			(this->*funptr[i]) (target);
			return ;
		}
	}
	std::cout << "There is no that kind of function!" << std::endl;
}
