
#ifndef COMMANDS_HPP
# define COMMANDS_HPP

# include <iostream>
//# include "../Mindopen.hpp"
class Mindopen;

class Commands
{
	public:
		Commands();
		virtual ~Commands();
		virtual void	execute(Mindopen& comm_cont) = 0;
};

# include "../Mindopen.hpp"

#endif