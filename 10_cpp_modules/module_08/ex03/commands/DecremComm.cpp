
#include "DecremComm.hpp"

DecremComm::DecremComm()
{
	return;
}

DecremComm::~DecremComm()
{
	return;
}

DecremComm::DecremComm(DecremComm const & obj)
{
	this->operator=(obj);
	return;
}

DecremComm& DecremComm::operator= (DecremComm const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void DecremComm::execute(Mindopen& comm_cont)
{
	comm_cont.decVal();
	comm_cont.setCurrCommNumber(comm_cont.getCurrCommNumber() + 1);
}
