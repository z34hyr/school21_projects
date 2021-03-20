
#include "PutSymbComm.hpp"

PutSymbComm::PutSymbComm()
{
	return;
}

PutSymbComm::~PutSymbComm()
{
	return;
}

PutSymbComm::PutSymbComm(PutSymbComm const & obj)
{
	this->operator=(obj);
	return;
}

PutSymbComm& PutSymbComm::operator= (PutSymbComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void PutSymbComm::execute(Mindopen& comm_cont)
{
	comm_cont.setVal(comm_cont.getArgsSymb());
	comm_cont.setCurrCommNumber(comm_cont.getCurrCommNumber() + 1);
}
