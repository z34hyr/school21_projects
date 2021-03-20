
#include "Mindopen.hpp"

Mindopen::Mindopen(const std::string filename, const std::string args) : _filename(filename), _args(args)
{
	_cur_pos_args = 0;
	_cur_pos_arr = 0;
	_cur_comm = 0;
	_braces_count = 0;
	for (unsigned int i = 0; i < ARR_SIZE; i++)
		_array[i] = 0;
	return;
}

Mindopen::~Mindopen()
{
	for (unsigned int i = 0; i < _comm_arr.size(); i++)
		delete _comm_arr[i];
	return;
}

void	Mindopen::readFile()
{
	char symb;
	try
	{
		//check file for braces sequence
		_check_braces();
		//trying to open file
		std::fstream fin(_filename, std::fstream::in);
		if (fin.fail())
			throw FileErrorException();
		//add all commands to STL vector
		while (fin >> std::noskipws >> symb) 
		{
			if (symb == '>')
			{
				_comm_arr.push_back(new NextPositionComm());
				continue;
			}
			if (symb == '<')
			{
				_comm_arr.push_back(new PrevPositionComm());
				continue;
			}
			if (symb == '+')
			{
				_comm_arr.push_back(new IncremComm());
				continue;
			}
			if (symb == '-')
			{
				_comm_arr.push_back(new DecremComm());
				continue;
			}
			if (symb == '.')
			{
				_comm_arr.push_back(new PrintSymbComm());
				continue;
			}
			if (symb == ',')
			{
				_comm_arr.push_back(new PutSymbComm());
				continue;
			}
			if (symb == '[')
			{
				_comm_arr.push_back(new WhileStartComm(*this));
				continue;
			}
			if (symb == ']')
			{
				_comm_arr.push_back(new WhileEndComm());
				continue;
			}
			//throw WrongCharacterException();
		}
		fin.close();
		execute();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return;
}

unsigned int	Mindopen::getCurrCommNumber(void)
{
	return _cur_comm;
}

void	Mindopen::setCurrCommNumber(unsigned int new_number)
{
	_cur_comm = new_number;
}

void	Mindopen::execute()
{
	while (Commands* pip = getComm(_cur_comm))
	{
		pip->execute(*this);
	}
}

char*	Mindopen::getArray()
{
	return _array;
}

unsigned int	Mindopen::getCurrPos()
{
	return _cur_pos_arr;
}

char		Mindopen::getArgsSymb()
{
	if (_args[_cur_pos_args])
	{
		_cur_pos_args += 1;
		return _args[_cur_pos_args - 1];
	}
	return 0;
}

unsigned int*	Mindopen::getArgsCurrPos()
{
	return &_cur_pos_args;
}

char			Mindopen::getValue(unsigned int pos)
{
	return _array[pos];
}

void			Mindopen::setValue(int value)
{
	_array[_cur_pos_arr] = value;
}

void			Mindopen::incPos()
{
	if (_cur_pos_arr + 1 == ARR_SIZE)
		throw OutOfRangeException();
	_cur_pos_arr += 1;
}

void			Mindopen::decPos()
{
	if (_cur_pos_arr == 0)
		throw OutOfRangeException();
	_cur_pos_arr -= 1;
}

void			Mindopen::incVal()
{
	_array[_cur_pos_arr] += 1;
}

void			Mindopen::decVal()
{
	_array[_cur_pos_arr] -= 1;
}

void			Mindopen::setVal(char symb)
{
	_array[_cur_pos_arr] = symb;
}

void			Mindopen::_check_braces(void)
{
	char symb;
	std::fstream fin(_filename, std::fstream::in);
	if (fin.fail())
		throw FileErrorException();
	while (fin >> std::noskipws >> symb)
	{
		if (symb == '[')
			_braces_count += 1;
		if (symb == ']')
			_braces_count -= 1;
		if (_braces_count < 0)
		{
			fin.close();
			throw WrongBracesSequenceException();
		}
	}
	fin.close();
	if (_braces_count != 0)
		throw WrongBracesCountException();
}

unsigned int	Mindopen::getVectorSize()
{
	return _comm_arr.size();
}

Commands*	Mindopen::getComm(unsigned int ind)
{
	if (ind < _comm_arr.size())
		return _comm_arr[ind];
	return NULL;
}
