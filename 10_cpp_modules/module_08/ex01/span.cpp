
#include "span.hpp"

Span::Span(unsigned int N)
{
	_size = N;
	return; 
}

Span::Span(Span const & obj)
{
	this->operator=(obj);
	return;
}

Span& Span::operator= (Span const & obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

Span::~Span()
{
	return;
}

unsigned int Span::getSize()
{
	return _vect_set.size();
}

std::vector<int>	Span::getVect() const
{
	return _vect_set;
}

void	Span::addNumber(int num)
{
	if (_vect_set.size() == _size)
		throw Span::ClassIsFullException();
	_vect_set.push_back(num);
}

void	Span::addNumber(int* num_arr, unsigned int size)
{
	if (size > _size)
		throw Span::OutOfRangeException();
	for (unsigned int i = 0; i < size; i++)
		_vect_set.push_back(num_arr[i]);
}

int		Span::longestSpan()
{
	if (_vect_set.size() == 0)
		throw Span::ClassIsEmptyException();
	if (_vect_set.size() == 1)
		throw Span::OnlyOneNumberException();
	return *std::max_element(_vect_set.begin(), _vect_set.end()) - *std::min_element(_vect_set.begin(), _vect_set.end());
}

int		Span::shortestSpan()
{
	unsigned int size = _vect_set.size();
	
	if (size == 0)
		throw Span::ClassIsEmptyException();
	if (size == 1)
		throw Span::OnlyOneNumberException();
	std::sort(_vect_set.begin(), _vect_set.end());
	int	min_span = _vect_set[1] - _vect_set[0];
	for (unsigned int i = 1; i < size - 1; i++)
	{
		if (_vect_set[i + 1] - _vect_set[i] < min_span)
			min_span = _vect_set[i + 1] - _vect_set[i];	
	}
	return (min_span);
}
