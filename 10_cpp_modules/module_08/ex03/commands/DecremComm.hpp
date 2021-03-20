
#ifndef DECREMENT_COMM_HPP
# define DECREMENT_COMM_HPP

#include "Commands.hpp"

class DecremComm : virtual public Commands
{
	public:
		DecremComm(void);
		DecremComm(DecremComm const & obj);
		DecremComm& operator= (DecremComm const & obj);
		virtual ~DecremComm();

		void	execute(Mindopen& comm_cont);
};

#endif