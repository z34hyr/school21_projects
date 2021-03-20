
#ifndef WHILEEND_COMM_HPP
# define WHILEEND_COMM_HPP

#include "Commands.hpp"

class WhileEndComm : virtual public Commands
{
	public:
		WhileEndComm(void);
		WhileEndComm(WhileEndComm const & obj);
		WhileEndComm& operator= (WhileEndComm const & obj);
		virtual ~WhileEndComm();

		void	execute(Mindopen& comm_cont);
		void	setStart(unsigned int objPos);
	private:
		unsigned int _start_pos;
};

#endif