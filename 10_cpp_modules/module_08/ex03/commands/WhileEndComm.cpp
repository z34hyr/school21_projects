
#include "WhileEndComm.hpp"

WhileEndComm::WhileEndComm()
{
	return;
}

WhileEndComm::~WhileEndComm()
{
	return;
}

WhileEndComm::WhileEndComm(WhileEndComm const & obj)
{
	this->operator=(obj);
	return;
}

WhileEndComm& WhileEndComm::operator= (WhileEndComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void WhileEndComm::execute(Mindopen& comm_cont)
{
	int brace_count = 1;
	for (unsigned int i = comm_cont.getCurrCommNumber() - 1; i > 0; i--)
	{
		if (dynamic_cast<WhileStartComm *>(comm_cont.getComm(i)))
		{
			brace_count -= 1;
			if (brace_count == 0)
			{
				comm_cont.setCurrCommNumber(i);
				return;
			}
		}
		if (dynamic_cast<WhileEndComm *>(comm_cont.getComm(i)))
			brace_count += 1;
	}
	comm_cont.setCurrCommNumber(0);
	return;
}

void	WhileEndComm::setStart(unsigned int objPos)
{
	_start_pos = objPos;
}