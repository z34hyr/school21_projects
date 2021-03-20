
#ifndef INCREMENT_COMM_HPP
# define INCREMENT_COMM_HPP

#include "Commands.hpp"

class IncremComm : virtual public Commands
{
	public:
		IncremComm(void);
		IncremComm(IncremComm const & obj);
		IncremComm& operator= (IncremComm const & obj);
		virtual ~IncremComm();

		void	execute(Mindopen& comm_cont);
};

#endif