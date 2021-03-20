
#include "CentralBureaucracy.hpp"

CentralBureaucracy::CentralBureaucracy(void)
{
	std::cout << MAGENTA << "CentralBureaucracy " << RESET << " has been created" << std::endl;
	_main_queue = NULL;
	return;
}

CentralBureaucracy::~CentralBureaucracy(void)
{
	std::cout << "CentralBureaucracy Destructor called" << std::endl;
	//clean_queue();
	return;
}

CentralBureaucracy::CentralBureaucracy(const CentralBureaucracy& obj)
{
	obj.forSakeOfCoplien();
	return;
}

CentralBureaucracy& CentralBureaucracy::operator= (const CentralBureaucracy& obj)
{
	obj.forSakeOfCoplien();
	return *this;
}

void	CentralBureaucracy::forSakeOfCoplien(void) const
{
	//do nothing
	return;
}

void	CentralBureaucracy::feedBureacurat(Bureaucrat* bure)
{
	std::cout << "\\\\\\\\\\\\\\\\" << std::endl;
	for (int i = 0; i < BUREAUCRACY_SIZE; i++)
	{
		if (!_block[i].getBurSigning(false))
		{
			std::cout << "Feed bureaucrat to block #" << i << ": " << std::endl;
			_block[i].setBurSigning(bure);
			if (!_block[i].getIntern(false))
				_block[i].setIntern(new Intern());
			return;
		}
		if (!_block[i].getBurExecuting(false))
		{
			std::cout << "Feed bureaucrat to block #" << i << ": " << std::endl;
			_block[i].setBurExecuting(bure);
			if (!_block[i].getIntern(false))
				_block[i].setIntern(new Intern());
			return;
		}
	}
	std::cout << "All bureaus are full. You better come back later" << std::endl;
}

QUEUE*	CentralBureaucracy::queueUp(std::string form_target)
{
	QUEUE* temp;
	if (_main_queue)
	{
		temp = _main_queue;
		_main_queue = _main_queue->next;
		_main_queue = new QUEUE;
		temp->next = _main_queue;
		_main_queue->form_target = form_target;
		_main_queue->prev = temp;
		_main_queue->next = NULL;
	}
	else
	{
		_main_queue = new QUEUE;
		_main_queue->form_target = form_target;
		_main_queue->next = NULL;
		_main_queue->prev = NULL;
	}
	return _main_queue;
}

QUEUE*	CentralBureaucracy::get_first(void)
{
	if (_main_queue)
	{
		while (_main_queue->prev)	
			_main_queue = _main_queue->prev;
	}
	return _main_queue;
}

void	CentralBureaucracy::clean_queue(void)
{
	QUEUE* temp;
	_main_queue = get_first();
	while(_main_queue)
	{
		temp = _main_queue;
		delete _main_queue;
		_main_queue = temp->next;
	}
	_main_queue = NULL;
	std::cout << "line is clean" << std::endl;
}

int		CentralBureaucracy::queue_length(void)
{
	QUEUE* temp;
	temp = get_first();
	int i = 0;
	while (temp)
	{
		i += 1;
		temp = temp->next;
	}
	return (i);
}

bool	CentralBureaucracy::check_fullness(int i)
{
	if (_block[i].getBurExecuting(false) && _block[i].getBurSigning(false) && _block[i].getIntern(false))
			return true;
	return false;
}

void	CentralBureaucracy::doBureaucracy(void)
{
	QUEUE* temp;
	std::string const formNames[3] = {"presidental pardon" ,"robotomy request", "shrubbery creation"};
	temp = get_first();
	int i = 0;
	for (int i = 0; i < BUREAUCRACY_SIZE; i++)
	{
		if (check_fullness(i))
			break;
		if (i == BUREAUCRACY_SIZE)
			std::cout << "Sorry, there is no full bureau. Come back later." << std::endl;
		return;
	}
	while (temp)
	{
		if (check_fullness(i % BUREAUCRACY_SIZE))
		{
			_block[i % BUREAUCRACY_SIZE].doBureaucracy(formNames[std::rand() % 3], temp->form_target);
			std::cout << "Was serviced by bureau #" << i % BUREAUCRACY_SIZE << std::endl << std::endl;
		}
		else
		{
			i += 1;
			continue;
		}
		//delete temp;
		temp = temp->next;
		i += 1;
	}
	clean_queue();
}

void	CentralBureaucracy::fireExecBureaucrat(int block)
{
	if (block < BUREAUCRACY_SIZE)
	{
		_block[block].setBurExecuting(NULL);
		std::cout << "Executing bureaucrat from office #" << block << " has been fired" << std::endl;
	}
	else
		std::cout << "Wrong block number" << std::endl;
}

void	CentralBureaucracy::showQueue(void)
{
	QUEUE* temp;
	temp = get_first();
	while (temp)
	{
		std::cout << "Name: " << temp->form_target << std::endl;
		temp = temp->next;
	}
}

void	CentralBureaucracy::showBureauInfo(int number)
{
	std::cout << "	\\\\\\\\\\\\\\\\" << std::endl;
	std::cout << "	| Bureau # " << number << " |" << std::endl;
	std::cout << "	________" << std::endl;
	std::cout << "	| "; _block[number].getIntern(true);
	std::cout << "	________" << std::endl;
	std::cout << "	| "; 
	_block[number].getBurSigning(true);
	std::cout << "	________" << std::endl;
	std::cout << "	| ";
	_block[number].getBurExecuting(true);
	std::cout << "	________" << std::endl;
}
