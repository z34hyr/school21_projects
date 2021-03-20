
#include "PrevPositionComm.hpp"

PrevPositionComm::PrevPositionComm()
{
	return;
}

PrevPositionComm::~PrevPositionComm()
{
	return;
}

PrevPositionComm::PrevPositionComm(PrevPositionComm const & obj)
{
	this->operator=(obj);
	return;
}

PrevPositionComm& PrevPositionComm::operator= (PrevPositionComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void PrevPositionComm::execute(Mindopen& comm_cont)
{
	comm_cont.decPos();
	comm_cont.setCurrCommNumber(comm_cont.getCurrCommNumber() + 1);
}
