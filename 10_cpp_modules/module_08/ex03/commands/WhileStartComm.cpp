
#include "WhileStartComm.hpp"

WhileStartComm::WhileStartComm(Mindopen& comm_cont)
{
	_brace_start = comm_cont.getVectorSize();
	_handled = false;
	return;
}

WhileStartComm::~WhileStartComm()
{
	return;
}

WhileStartComm::WhileStartComm(WhileStartComm const & obj)
{
	this->operator=(obj);
	return;
}

WhileStartComm& WhileStartComm::operator= (WhileStartComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void WhileStartComm::execute(Mindopen& comm_cont)
{
	int brace_count = 1;
	if (_handled == false)
	{
		_arr_pos = comm_cont.getCurrPos(); // save position of counter
		_handled = true;
	}
	if (comm_cont.getValue(_arr_pos) == 0) // cycle is end. skip all comms befotre closing brace
	{
		for (unsigned int i = _brace_start + 1; i < comm_cont.getVectorSize(); i++)
		{
			if (dynamic_cast<WhileStartComm *>(comm_cont.getComm(i)))
				brace_count += 1;
			if (dynamic_cast<WhileEndComm *>(comm_cont.getComm(i)))
			{
				brace_count -= 1;
				if (brace_count == 0) // found closing brace
				{
					comm_cont.setCurrCommNumber(i + 1);
					return;
				}
			}
		}
	}
	else
		comm_cont.setCurrCommNumber(comm_cont.getCurrCommNumber() + 1);
}
