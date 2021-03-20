
#include "NextPositionComm.hpp"

NextPositionComm::NextPositionComm()
{
	return;
}

NextPositionComm::~NextPositionComm()
{
	return;
}

NextPositionComm::NextPositionComm(NextPositionComm const & obj)
{
	this->operator=(obj);
	return;
}

NextPositionComm& NextPositionComm::operator= (NextPositionComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void NextPositionComm::execute(Mindopen& comm_cont)
{
	comm_cont.incPos();
	comm_cont.setCurrCommNumber(comm_cont.getCurrCommNumber() + 1);
}
