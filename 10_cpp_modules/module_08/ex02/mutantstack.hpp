
#include <iterator>
#include <stack>

template <class T>
//stack is LIFO type
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator iterator_const;

		MutantStack() : std::stack<T>() {};
		MutantStack(MutantStack const &obj) : std::stack<T>(obj) {};
		MutantStack& operator= (MutantStack const &obj)
		{
			if (this == &obj)
				return *this;
			return *this;
		};
		virtual ~MutantStack(){};

		iterator begin()
		{
			return std::stack<T>::c.begin();//this->c.begin();
		}
		iterator end()
		{
			return std::stack<T>::c.end();//this->c.end();
		}
		iterator_const begin() const
		{
			return this->c.begin();
		}
		iterator_const end() const
		{
			return this->c.end();
		}
};
