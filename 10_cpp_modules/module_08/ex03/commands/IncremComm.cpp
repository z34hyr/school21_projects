
#include "IncremComm.hpp"

IncremComm::IncremComm()
{
	return;
}

IncremComm::~IncremComm()
{
	return;
}

IncremComm::IncremComm(IncremComm const & obj)
{
	this->operator=(obj);
	return;
}

IncremComm& IncremComm::operator= (IncremComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void IncremComm::execute(Mindopen& comm_cont)
{
	comm_cont.incVal();
	comm_cont.setCurrCommNumber(comm_cont.getCurrCommNumber() + 1);
}
