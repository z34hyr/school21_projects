
#ifndef PRINTSYMB_COMM_HPP
# define PRINTSYMB_COMM_HPP

#include "Commands.hpp"

class PrintSymbComm : virtual public Commands
{
	public:
		PrintSymbComm(void);
		PrintSymbComm(PrintSymbComm const & obj);
		PrintSymbComm& operator= (PrintSymbComm const & obj);
		virtual ~PrintSymbComm();

		void	execute(Mindopen& comm_cont);
};

#endif