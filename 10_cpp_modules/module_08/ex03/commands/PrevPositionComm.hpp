
#ifndef PREVPOS_COMM_HPP
# define PREVPOS_COMM_HPP

#include "Commands.hpp"

class PrevPositionComm : virtual public Commands
{
	public:
		PrevPositionComm(void);
		PrevPositionComm(PrevPositionComm const & obj);
		PrevPositionComm& operator= (PrevPositionComm const & obj);
		virtual ~PrevPositionComm();

		void	execute(Mindopen& comm_cont);
};

#endif