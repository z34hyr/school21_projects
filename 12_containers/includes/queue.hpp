
//#pragma once
#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"

namespace ft
{
	template <typename T, typename Container = list<T> >
	class queue
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type	cont;

		public:
			explicit queue(const container_type &ctnr = container_type()) : cont(ctnr) {};
			~queue() {};

			bool empty() const { return cont.empty(); };
			size_type size() const { return cont.size(); };
			value_type& front() { return cont.front(); };
			const value_type& front() const { return cont.front(); };
			value_type& back() { return cont.back(); };
			const value_type& back() const { return cont.back(); };
			void push(const value_type& val) { cont.push_back(val); };
			void pop() { cont.pop_front(); };
	};

	template <class T, class Container>
		bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.cont == rhs.cont);
	};
	template <class T, class Container>
		bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.cont != rhs.cont);
	};
	template <class T, class Container>
		bool operator< (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.cont < rhs.cont);
	};
	template <class T, class Container>
		bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.cont <= rhs.cont);
	};
	template <class T, class Container>
		bool operator> (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.cont > rhs.cont);
	};
	template <class T, class Container>
		bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
	{
		return (lhs.cont >= rhs.cont);
	};
}

#endif