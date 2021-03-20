
#ifndef PUTSYMB_COMM_HPP
# define PUTSYMB_COMM_HPP

#include "Commands.hpp"

class PutSymbComm : virtual public Commands
{
	public:
		PutSymbComm(void);
		PutSymbComm(PutSymbComm const & obj);
		PutSymbComm& operator= (PutSymbComm const & obj);
		virtual ~PutSymbComm();

		void	execute(Mindopen& comm_cont);
};

#endif