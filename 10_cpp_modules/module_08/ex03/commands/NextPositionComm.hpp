
#ifndef NEXTPOS_COMM_HPP
# define NEXTPOS_COMM_HPP

#include "Commands.hpp"

class NextPositionComm : virtual public Commands
{
	public:
		NextPositionComm(void);
		NextPositionComm(NextPositionComm const & obj);
		NextPositionComm& operator= (NextPositionComm const & obj);
		virtual ~NextPositionComm();

		void	execute(Mindopen& comm_cont);
};

#endif