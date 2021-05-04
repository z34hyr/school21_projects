
#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <stdexcept>
#include <cstdlib>
#include <sstream>

#include "is_integer.hpp"

namespace ft
{
	template <class T>
	struct s_list
			{
				typedef T	value_type;
				value_type	val;
				s_list*		prev;
				s_list*		next;
			};

	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef T								value_type;
			typedef Alloc							allocator_type;
			typedef typename Alloc::reference		reference;
			typedef typename Alloc::const_reference	const_reference;
			typedef typename Alloc::pointer			pointer;
			typedef typename Alloc::const_pointer	const_pointer;
			typedef typename Alloc::difference_type	difference_type;
			typedef typename Alloc::size_type		size_type;

			explicit list (const allocator_type& alloc = allocator_type()) { list_start = NULL; _size = 0; };
			explicit list (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			{
				init_int(n, val);
			};
			template <class InputIterator>
         		list (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			{
				typedef typename is_integer<InputIterator>::__type _Integral;
	 			my_initialize_dispatch(first, last, _Integral());
			};
			list (const list& x)
			{

			};
			list& operator= (const list& x)
			{

			};
			~list()
			{

			};
			
			//ITERATORS
			class iterator
			{
				public:
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef typename Alloc::difference_type	difference_type;
					typedef typename Alloc::value_type		value_type;
					typedef typename Alloc::pointer			pointer;  // or also value_type*
					typedef typename Alloc::reference		reference;
					typedef typename Alloc::const_reference		const_reference;
					

					iterator() { m_ptr = NULL; lss = NULL; };
					//iterator(pointer value) : m_ptr(value) {};
					iterator(s_list<value_type> *val) {lss = val; m_ptr = &lss->val; };
					~iterator() {};
					// input iterator requirements
					iterator(iterator const & obj) { *this = obj; } ; // copy constructor
					iterator& operator= (iterator const & obj) { this->m_ptr = obj.m_ptr; this->lss = obj.lss; return *this; }; //assignatiom overloading
					bool operator== (iterator const & obj) { return (m_ptr == obj.m_ptr); };
					bool operator!= (iterator const & obj) { return (m_ptr != obj.m_ptr); };
					pointer operator-> () const { return m_ptr; };
					//forward iterator requirements
					iterator& operator++() { m_ptr = &lss->next->val; lss = lss->next; return *this; };
					//iterator operator++(int) {iterator some = *this; ++(*this); return some; };
					//bidirectional iterator requirements
					iterator& operator--() { m_ptr = &lss->prev->val; lss = lss->prev; return *this; };
					//iterator operator--(int) { iterator some = *this; --(*this); return some; };
					reference operator*() const { return *m_ptr; };
				private:
					pointer m_ptr;
					s_list<value_type> *lss;
			};
			class const_iterator
			{
				public:
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef typename Alloc::difference_type	difference_type;
					typedef typename Alloc::value_type		value_type;
					typedef typename Alloc::pointer			pointer;  // or also value_type*
					typedef typename Alloc::reference		reference;
					typedef typename Alloc::const_reference	const_reference;

					const_iterator() { m_ptr = NULL; };
					const_iterator(pointer value) : m_ptr(value) {};
					~const_iterator() {};
					// input iterator requirements
					const_iterator(const_iterator const & obj) { *this = obj; }; // copy constructor
					const_iterator(iterator const & obj) { *this = obj; };
					const_iterator& operator= (const_iterator const & obj) { this->m_ptr = obj.m_ptr; return *this; }; //assignatiom overloading
					bool operator== (const_iterator const & obj) const { return (m_ptr == obj.m_ptr); };
					bool operator!= (const_iterator const & obj) const { return (m_ptr != obj.m_ptr); };
					bool operator< (const_iterator const & obj) const { return (m_ptr < obj.m_ptr); };
					bool operator> (const_iterator const & obj) const { return (m_ptr > obj.m_ptr); };
					bool operator<= (const_iterator const & obj) const { return (m_ptr <= obj.m_ptr); };
					bool operator>= (const_iterator const & obj) const { return (m_ptr >= obj.m_ptr); };
					pointer operator-> () const { return m_ptr; };
					//forward iterator requirements
					const_iterator& operator++() { m_ptr++; return *this; };
					const_iterator operator++(int) {const_iterator some = *this; ++(*this); return some; };
					//bidirectional iterator requirements
					const_iterator& operator--() { m_ptr--; return *this; };
					const_iterator operator--(int) { const_iterator some = *this; --(*this); return some; };
					//random iterator requirements
					// const_iterator& operator+=(size_type n) { m_ptr = m_ptr + n; return *this; };
					// const_iterator operator+(size_type n) const { const_iterator some = *this; some.m_ptr = some.m_ptr + n; return some; };
					// const_iterator& operator-=(size_type n) { m_ptr = m_ptr - n; return *this; };            
					// const_iterator operator-(size_type n) const { const_iterator some = *this; some.m_ptr = some.m_ptr - n; return some; };
					// difference_type operator-(const_iterator it) const { return (this->m_ptr - it.m_ptr); };
					reference operator*() const { return *m_ptr; };
					// reference operator[] (size_type n) const { return *(m_ptr + n); };
				private:
					pointer m_ptr;
			};
			class reverse_iterator
			{
				public:
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef typename Alloc::difference_type	difference_type;
					typedef typename Alloc::value_type		value_type;
					typedef typename Alloc::pointer			pointer;  // or also value_type*
					typedef typename Alloc::reference		reference;
					typedef typename Alloc::const_reference	const_reference;

					reverse_iterator() { m_ptr = NULL; };
					reverse_iterator(pointer value) : m_ptr(value) {};
					~reverse_iterator() {};
					// input iterator requirements
					reverse_iterator(reverse_iterator const & obj) { *this = obj; } ; // copy constructor
					reverse_iterator& operator= (reverse_iterator const & obj) { this->m_ptr = obj.m_ptr; return *this; }; //assignatiom overloading
					bool operator== (reverse_iterator const & obj) { return (m_ptr == obj.m_ptr); };
					bool operator!= (reverse_iterator const & obj) { return (m_ptr != obj.m_ptr); };
					bool operator< (reverse_iterator const & obj) const { return (m_ptr > obj.m_ptr); };
					bool operator> (reverse_iterator const & obj) const { return (m_ptr < obj.m_ptr); };
					bool operator<= (reverse_iterator const & obj) const { return (m_ptr >= obj.m_ptr); };
					bool operator>= (reverse_iterator const & obj) const { return (m_ptr <= obj.m_ptr); };
					pointer operator-> () const { return m_ptr; };
					//forward iterator requirements
					reverse_iterator& operator++() { m_ptr--; return *this; };
					reverse_iterator operator++(int) {iterator some = *this; --(*this); return some; };
					//bidirectional iterator requirements
					reverse_iterator& operator--() { m_ptr++; return *this; };
					reverse_iterator operator--(int) { iterator some = *this; ++(*this); return some; };
					//random iterator requirements
					// reverse_iterator& operator+=(difference_type n) { m_ptr = m_ptr - n; return *this; };
					// reverse_iterator operator+(difference_type n) const { iterator some = *this; some.m_ptr = some.m_ptr - n; return some; };
					// reverse_iterator& operator-=(difference_type n) { m_ptr = m_ptr + n; return *this; };            
					// reverse_iterator operator-(difference_type n) const { iterator some = *this; some.m_ptr = some.m_ptr + n; return some; };
					// difference_type operator-(iterator it) const { return (this->m_ptr + it.m_ptr); };
					reference operator*() const
					{
						iterator temp = m_ptr;
						return *--temp;
					};
					// reference operator[] (difference_type n) const { return *(m_ptr + n); };
				private:
					pointer m_ptr;
			};
			class const_reverse_iterator
			{
				public:
					typedef std::bidirectional_iterator_tag iterator_category;
					typedef typename Alloc::difference_type	difference_type;
					typedef typename Alloc::value_type		value_type;
					typedef typename Alloc::pointer			pointer;  // or also value_type*
					typedef typename Alloc::reference		reference;
					typedef typename Alloc::const_reference	const_reference;

					const_reverse_iterator() { m_ptr = NULL; };
					const_reverse_iterator(pointer value) : m_ptr(value) {};
					~const_reverse_iterator() {};
					// input iterator requirements
					const_reverse_iterator(const_reverse_iterator const & obj) { *this = obj; } ; // copy constructor
					const_reverse_iterator& operator= (const_reverse_iterator const & obj) { this->m_ptr = obj.m_ptr; return *this; }; //assignatiom overloading
					bool operator== (const_reverse_iterator const & obj) const { return (m_ptr == obj.m_ptr); };
					bool operator!= (const_reverse_iterator const & obj) const { return (m_ptr != obj.m_ptr); };
					bool operator< (const_reverse_iterator const & obj) const { return (m_ptr > obj.m_ptr); };
					bool operator> (const_reverse_iterator const & obj) const { return (m_ptr < obj.m_ptr); };
					bool operator<= (const_reverse_iterator const & obj) const { return (m_ptr >= obj.m_ptr); };
					bool operator>= (reverse_iterator const & obj) const { return (m_ptr <= obj.m_ptr); };
					pointer operator-> () const { return m_ptr; };
					//forward iterator requirements
					const_reverse_iterator& operator++() { m_ptr--; return *this; };
					const_reverse_iterator operator++(int) {iterator some = *this; --(*this); return some; };
					//bidirectional iterator requirements
					const_reverse_iterator& operator--() { m_ptr++; return *this; };
					const_reverse_iterator operator--(int) { iterator some = *this; ++(*this); return some; };
					reference operator*() const
					{
						iterator temp = m_ptr;
						return *--temp;
					};
				private:
					pointer m_ptr;
			};
			iterator begin() { return iterator(list_start); };
			const_iterator begin() const { return const_iterator(list_start); };
			iterator end() { return iterator(NULL); };
			const_iterator end() const { return const_iterator(NULL); };
			// reverse_iterator rbegin() { return (_size > 0 ? reverse_iterator(&list_begin[_size]) : NULL); };
			// const_reverse_iterator rbegin() const { return (_size > 0 ? const_reverse_iterator(&list_begin[_size]) : NULL); };
			// reverse_iterator rend() { return (_size > 0 ? reverse_iterator(&list_begin[0]) : NULL); };
			// const_reverse_iterator rend() const { return (_size > 0 ? const_reverse_iterator(&list_begin[0]) : NULL); };

			///////////////////////////////////////////////////////////////////////
			///				CAPACITY										///////
			///////////////////////////////////////////////////////////////////////
			size_type	size() const { return _size; };
			size_type	max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); };
			bool		empty() const { return (!_size ? true : false); };

			///////////////////////////////////////////////////////////////////////
			///				ELEMENTS ACCESS. return ref or const ref		///////
			///////////////////////////////////////////////////////////////////////
			reference		front() { return *(begin()); };
			const_reference	front() const { return *(begin()); };
			reference		back()
			{
				s_list<value_type> *temp = list_start;
				while (temp->next)
					temp = temp->next;
				return temp->val;
			 };
			const_reference	back() const
			{
				s_list<value_type> *temp = list_start;
				while (temp->next)
					temp = temp->next;
				return temp->val;
			};

			///////////////////////////////////////////////////////////////////////
			///				MODIFIERS										///////
			///////////////////////////////////////////////////////////////////////
			template <class InputIterator>
  				void 	assign (InputIterator first, InputIterator last)
			{
				// Check whether it's an integral type.  If so, it's not an iterator.
	  			typedef typename is_integer<InputIterator>::__type _Integral;
				my_assign_dispatch(first, last, _Integral());
			};// range
			void 		assign (size_type n, const value_type& val)
			{
				assign_int(n, val);
			};// fill
			void 		push_front (const value_type& val)
			{
				if (!list_start)
				{
					list_start = new s_list<value_type>;
					allo.construct(&list_start->val, val);
					//list_start->val = val;
					list_start->prev = NULL;
					list_start->next = NULL;
				}
				else
				{
					list_start->prev = new s_list<value_type>;
					allo.construct(&list_start->prev->val, val);
					list_start->prev->next = list_start;
					list_start->prev->prev = NULL;
					list_start = list_start->prev;
				}
				_size += 1;
			};
			void		pop_front()
			{
				allo.destroy(&list_start->val);
				delete list_start;
				list_start = list_start->next;
				list_start->prev = NULL;
				_size -= 1;
			};
			void 		push_back (const value_type& val)
			{
				if (!list_start)
				{
					list_start = new s_list<value_type>;
					allo.construct(&list_start->val, val);
					//list_start->val = val;
					list_start->prev = NULL;
					list_start->next = NULL;
				}
				else
				{
					s_list<value_type> *temp = list_start;
					while (temp->next)
						temp = temp->next;
					temp->next = new s_list<value_type>;
					allo.construct(&temp->next->val, val);
					//temp->next->val = val;
					temp->next->next = NULL;
					temp->next->prev = temp;
				}
				_size += 1;
			};
			void		pop_back()
			{
				s_list<value_type> *temp = list_start;
				while (temp->next)
					temp = temp->next;
				temp->prev->next = NULL;
				allo.destroy(&temp->val);
				delete temp;
				_size -= 1;
			};
			iterator	insert (iterator position, const value_type& val)
			{

			};//(1)single element
			void		insert (iterator position, size_type n, const value_type& val)
			{
				insert_int(position, n, val);
			};//(2)fill
			template <class InputIterator>
				void	insert (iterator position, InputIterator first, InputIterator last)
			{
				// Check whether it's an integral type.  If so, it's not an iterator.
	  			typedef typename is_integer<InputIterator>::__type _Integral;
	 			my_insert_dispatch(position, first, last, _Integral());
			};//(3)range
			iterator	erase (iterator position)
			{

			};
			iterator	erase (iterator first, iterator last)
			{

			};
			void		swap (list& x)
			{

			};
			void		resize(size_type n, value_type val = value_type())
			{

			};
			void		clear()
			{

			};

			///////////////////////////////////////////////////////////////////////
			///				OPERATIONS										///////
			///////////////////////////////////////////////////////////////////////
			void splice (iterator position, list& x)
			{

			};//entire list
			void splice (iterator position, list& x, iterator i)
			{

			};//single element
			void splice (iterator position, list& x, iterator first, iterator last)
			{

			};//element range
			void remove (const value_type& val)
			{

			};
			template <class Predicate>
  				void remove_if (Predicate pred)
			{

			};
			void unique()
			{

			};
			template <class BinaryPredicate>
				void unique (BinaryPredicate binary_pred)
			{

			};
			void merge (list& x)
			{

			};
			template <class Compare>
				void merge (list& x, Compare comp)
			{

			};
			void sort()
			{

			};
			template <class Compare>
				void sort (Compare comp)
			{

			};
			void reverse()
			{

			};



		private:
			
			size_type	_size;
			s_list<value_type>		*list_start;
			std::allocator<value_type> allo;
			
			template<typename InputIterator>
			void
			my_initialize_dispatch(InputIterator first, InputIterator last,
				false_type)
			{
				init_iter(first, last);
			}
			template<typename Integer>
			void
			my_initialize_dispatch(Integer n,
			   Integer val, true_type)
			{
				init_int(n, val);
			}
			void	init_iter(iterator first, iterator last)
			{

			}
			void	init_int(size_type n, value_type const & val)
			{

			}
			template<typename InputIterator>
			void
			my_insert_dispatch(iterator position, InputIterator __first,
			   InputIterator __last, false_type)
			{
				insert_iter(position, (size_type)(__last - __first), __first);
			}
			template<typename Integer>
			void
			my_insert_dispatch(iterator position, Integer n,
			   Integer val, true_type)
			{
				insert_int(position, n, val);
			}
			void	insert_int(iterator position, size_type n, const value_type& val)
			{

			}
			void	insert_iter(iterator position, size_type n, iterator first)
			{

			}
			template<typename InputIterator>
			void
			my_assign_dispatch(InputIterator __first,
			   InputIterator __last, false_type)
			{
				assign_iter((size_type)(__last - __first), __first);
			}
			template<typename Integer>
			void
			my_assign_dispatch(Integer n,
			   Integer val, true_type)
			{
				assign_int(n, val);
			}
			void	assign_int(size_type n, const value_type& val)
			{

			}
			void	assign_iter(size_type n, iterator first)
			{

			}
	};

	///////////////////////////////////////////////////////////////////////
	///				Non-member function overloads					///////
	/////////////////////////////////////////////////////////////////////// 
	template <typename T, class Alloc>
		void swap (list<T,Alloc>& x, list<T,Alloc>& y)
	{
		typename ft::list<T, Alloc> temp;
		temp = x;
		x = y;
		y = temp;
	};
	
	template <class T, class Alloc>
		bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		typename ft::list<T,Alloc>::const_iterator li_b = lhs.begin();
		typename ft::list<T,Alloc>::const_iterator li_e = lhs.end();
		typename ft::list<T,Alloc>::const_iterator ri_b = rhs.begin();
		typename ft::list<T,Alloc>::const_iterator ri_e = rhs.end();

		if (lhs.size() == rhs.size())
		{
			while (li_b != li_e && ri_b != ri_e)
			{
				if (*li_b != *ri_b)
					return false;
				++li_b;
				++ri_b;
			}
			return (ri_b == ri_e && li_b == li_e ? true : false);
		}
		else
			return false;
	};
	template <class T, class Alloc>
		bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !ft::operator==(lhs, rhs);
	};
	template <class T, class Alloc>
		bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		typename ft::list<T,Alloc>::const_iterator li_b = lhs.begin();
		typename ft::list<T,Alloc>::const_iterator li_e = lhs.end();
		typename ft::list<T,Alloc>::const_iterator ri_b = rhs.begin();
		typename ft::list<T,Alloc>::const_iterator ri_e = rhs.end();

		while (li_b != li_e && ri_b != ri_e)
		{
			if (*li_b < *ri_b)
				return true;
			++li_b;
			++ri_b;
		}
		return (ri_b == ri_e ? false : true); 
	};
	template <class T, class Alloc>
		bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		typename ft::list<T,Alloc>::const_iterator li_b = lhs.begin();
		typename ft::list<T,Alloc>::const_iterator li_e = lhs.end();
		typename ft::list<T,Alloc>::const_iterator ri_b = rhs.begin();
		typename ft::list<T,Alloc>::const_iterator ri_e = rhs.end();
		
		while (li_b != li_e && ri_b != ri_e)
		{
			if (*li_b > *ri_b)
				return true;
			++li_b;
			++ri_b;
		}
		return (li_b == li_e ? false : true); 
	};
	template <class T, class Alloc>
		bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !ft::operator>(lhs, rhs);
	};
	template <class T, class Alloc>
		bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
	{
		return !ft::operator<(lhs, rhs);
	};
}
