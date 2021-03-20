
#ifndef WHILESTART_COMM_HPP
# define WHILESTART_COMM_HPP

#include "Commands.hpp"

class WhileStartComm : virtual public Commands
{
	public:
		WhileStartComm(Mindopen& comm_cont);
		WhileStartComm(WhileStartComm const & obj);
		WhileStartComm& operator= (WhileStartComm const & obj);
		virtual ~WhileStartComm();

		void	execute(Mindopen& comm_cont);

	private:
		bool			_handled;
		unsigned int	_arr_pos;
		unsigned int	_brace_start; // object with [ number in vector
		unsigned int	_brace_end; // object with closing brace in vector
		int				_brace_count;
		void			_find_end_brace();
};

#endif