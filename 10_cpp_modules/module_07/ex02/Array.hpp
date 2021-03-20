
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T = float>

class Array
{
	public:
		Array(void)
		{
			_array = NULL;
			_size = 0;
		};
		Array(unsigned int n)
		{
			_array = new T[n]();
			_size = n;
		};
		Array(const Array & obj)
		{
			this->operator=(obj);
			return;
		};
		Array& operator= (const Array & obj)
		{
			if (this == &obj)
				return *this;
			if (_size > 0)
			{
				delete[] _array;
				_array = NULL;
			}
			_size = obj.size();
			if (_size > 0)
			{
				_array = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = obj._array[i];
			}
			else
				_array = NULL;
			return *this;
		};
		~Array(void)
		{
			_size = 0;
			delete[] _array;
		}
		T& operator[](unsigned int idx)
		{
			if (idx >= _size)
				throw Array::OutOfLimitsException();
			else
				return _array[idx];
		};
		unsigned int	size(void) const {return _size;};
		
	private:
		T*				_array;
		unsigned int	_size;
		class OutOfLimitsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "OutOfLimitsException";
				};
		};
};

#endif