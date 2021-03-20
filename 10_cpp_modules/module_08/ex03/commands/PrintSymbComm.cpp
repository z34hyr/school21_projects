
#include "PrintSymbComm.hpp"

PrintSymbComm::PrintSymbComm()
{
	return;
}

PrintSymbComm::~PrintSymbComm()
{
	return;
}

PrintSymbComm::PrintSymbComm(PrintSymbComm const & obj)
{
	this->operator=(obj);
	return;
}

PrintSymbComm& PrintSymbComm::operator= (PrintSymbComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void PrintSymbComm::execute(Mindopen& comm_cont)
{
	std::cout << comm_cont.getValue(comm_cont.getCurrPos());
	comm_cont.setCurrCommNumber(comm_cont.getCurrCommNumber() + 1);
}
