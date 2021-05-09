
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

			explicit list (const allocator_type& alloc = allocator_type())
			{
				list_start = NULL;
				_size = 0;
				list_end.prev = NULL;
				list_end.next = NULL;
			};
			explicit list (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			{
				list_start = NULL;
				_size = 0;
				init_int(n, val);
				list_end.prev = getLastElem();
				list_end.next = NULL;
				
			};
			template <class InputIterator>
         		list (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			{
				list_start = NULL;
				_size = 0;
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
				while (list_start)
				{
					allo.destroy(&list_start->val);
					delete list_start;
					list_start = list_start->next;
				}
				//allo.destroy(&list_end.val);
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
					
					iterator() { m_ptr = NULL; list_start = NULL; list_end = NULL; };
					//iterator(pointer value) : m_ptr(value) {};
					iterator(s_list<value_type> *val, s_list<value_type> *struct_end)
					{
						if (val == struct_end)
						{
							list_start = struct_end;
							m_ptr = NULL;
							val = NULL;
						}
						else
						{
							list_start = val;
							m_ptr = &list_start->val;
						}
						list_end = struct_end;
					};
					~iterator() {};
					// input iterator requirements
					iterator(iterator const & obj) { *this = obj; } ; // copy constructor
					iterator& operator= (iterator const & obj) { this->m_ptr = obj.m_ptr; this->list_start = obj.list_start; this->list_end = obj.list_end; return *this; }; //assignatiom overloading
					bool operator== (iterator const & obj) { return (m_ptr == obj.m_ptr); };
					bool operator!= (iterator const & obj) { return (m_ptr != obj.m_ptr); };
					pointer operator-> () const { return m_ptr; };
					//forward iterator requirements
					iterator& operator++()
					{
						if (!list_start)
						{
							m_ptr = NULL;
							list_start = list_end;
							return *this;
						}
						m_ptr = list_start->next ? &list_start->next->val : NULL;
						list_start = list_start->next ? list_start->next : list_end;
						return *this;
					};
					//iterator operator++(int) {iterator some = *this; ++(*this); return some; };
					//bidirectional iterator requirements
					iterator& operator--()
					{
						m_ptr = (list_start == list_end ? &list_end->prev->val : &list_start->prev->val);
						
						list_start = (list_start == list_end ? list_end->prev : list_start->prev);
						return *this;
					};
					//iterator operator--(int) { iterator some = *this; --(*this); return some; };
					reference operator*() const { return *m_ptr; };
				private:
					pointer m_ptr;
					s_list<value_type> *list_start;
					s_list<value_type> *list_end;
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
					const_iterator& operator= (const_iterator const & obj) { this->m_ptr = obj.m_ptr; this->list_start = obj.list_start; return *this; }; //assignatiom overloading
					bool operator== (const_iterator const & obj) const { return (m_ptr == obj.m_ptr); };
					bool operator!= (const_iterator const & obj) const { return (m_ptr != obj.m_ptr); };
					pointer operator-> () const { return m_ptr; };
					//forward iterator requirements
					const_iterator& operator++() { m_ptr = &list_start->next ? &list_start->next->val : NULL; list_start = list_start->next ? list_start->next : NULL; return *this; };
					//const_iterator operator++(int) {const_iterator some = *this; ++(*this); return some; };
					//bidirectional iterator requirements
					const_iterator& operator--() { m_ptr = &list_start->prev->val; list_start = list_start->prev; return *this; };
					//const_iterator operator--(int) { const_iterator some = *this; --(*this); return some; };
					reference operator*() const { return *m_ptr; };
					// reference operator[] (size_type n) const { return *(m_ptr + n); };
				private:
					pointer m_ptr;
					s_list<value_type> const *list_start;
					s_list<value_type> const *list_end;
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
			iterator begin() { return iterator(list_start, &list_end); };
			const_iterator begin() const { return const_iterator(list_start); };
			iterator end() { return iterator(&list_end, &list_end); };
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
	
				return *(--end());
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
					list_end.prev = list_start;
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
				if (list_start)
					list_start->prev = NULL;
				else
					list_start = NULL;
				_size -= 1;
				if (!_size)
					list_end.prev = NULL;
			};
			void 		push_back (const value_type& val)
			{
				if (!list_start)
				{
					list_start = new s_list<value_type>;
					allo.construct(&list_start->val, val);
					list_start->prev = NULL;
					list_start->next = NULL;
					list_end.prev = list_start;
				}
				else
				{
					s_list<value_type> *temp = list_start;
					while (temp->next)
						temp = temp->next;
					temp->next = new s_list<value_type>;
					allo.construct(&temp->next->val, val);
					list_end.prev = temp->next;
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
				if (temp->prev)
					temp->prev->next = NULL;
				else
					list_start = NULL;
				allo.destroy(&temp->val);
				delete temp;
				_size -= 1;
				if (!_size)
					list_end.prev = NULL;
				else
					list_end.prev = this->getLastElem();
			};
			iterator	insert (iterator position, const value_type& val)
			{
				list<value_type> temp_list(1, val);
				typename ft::list<value_type>::iterator ret_val = temp_list.begin();
				this->splice(position, temp_list);
				return ret_val;
			};//(1)single element
			iterator		insert (iterator position, size_type n, const value_type& val)
			{
				return insert_int(position, n, val);
			};//(2)fill
			template <class InputIterator>
				iterator	insert (iterator position, InputIterator first, InputIterator last)
			{
				// Check whether it's an integral type.  If so, it's not an iterator.
	  			typedef typename is_integer<InputIterator>::__type _Integral;
	 			return my_insert_dispatch(position, first, last, _Integral());
			};//(3)range
			iterator	erase (iterator position)
			{
				if (position == this->end())
					return position;
				s_list<value_type> *needed = getElem(position);
				//iterator to_return;
				if (needed == list_start)
					this->pop_front();
				else if (list_end.prev && needed == list_end.prev)
					this->pop_back();
				else if (needed)
				{
					needed->prev->next = needed->next;
					allo.destroy(&needed->val);
					needed->next->prev = needed->prev;
					delete needed;
					_size -= 1;
					return ++position;
				}
				return iterator();
			};
			iterator	erase (iterator first, iterator last)
			{
				std::cout << _size << " - size before erase" << std::endl;
				iterator to_return = last;
				if (first == this->begin())
				{
					while (first != last)
					{
						this->pop_front();
						++first;
					}
					return last;
				}
				else if (last == this->end())
				{
					while (first != last)
					{
						this->pop_back();
						--last;
					}
					this->pop_back();
					return to_return;
				}
				else
				{
					s_list<value_type> *needed = getElem(first);
					if (needed)
					{
						while (first != last)
						{
							needed->prev->next = needed->next;
							needed->next->prev = needed->prev;
							allo.destroy(&needed->val);
							delete needed;
							needed = needed->next;
							++first;
							_size -= 1;
						}
						return to_return;
					}
				}
				return iterator();
			};
			void		swap (list& x)
			{
				s_list<value_type> *temp = list_start;
				list_start = x.getFirstElem();
				x.setFirstElem(temp);
			};
			void		resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
				{
					while (_size > n)
						this->pop_back();
				}
				else if (n > _size)
				{
					list<value_type> new_list(n - _size, val);
					this->splice(this->end(), new_list);
				}
			};
			void		clear()
			{
				this->erase(this->begin(), this->end());
			};

			///////////////////////////////////////////////////////////////////////
			///				OPERATIONS										///////
			///////////////////////////////////////////////////////////////////////
			void splice (iterator position, list& x)
			{
				//transfer from x to this, remove (but not dealloc) from x
				if (!list_start && (position == this->begin()))
				{
					list_start = x.getFirstElem();
					_size += x.size();
					list_end.prev = x.getLastElem();
					x.resetList();
				}
				else
				{
					s_list<value_type> *temp = this->list_start;
					iterator i_b = this->begin();
					iterator i_e = this->end();
					while (i_b != i_e)
					{
						if (i_b == position)
							break;
						++i_b;
						if (i_b != i_e)
							temp = temp->next;
					}
					if (i_b == position)
					{
						//std::cout << "value: " << temp->prev->val << std::endl;
						s_list<value_type> *x_last = x.getFirstElem();
							while (x_last->next)
								x_last = x_last->next;
						if (i_b == i_e)// case "after last elem"
						{
							temp->next = x.getFirstElem();
							temp->next->prev = temp;
							_size += x.size();
							list_end.prev = x.getLastElem();
							x.resetList();
							return;
						}
						s_list<value_type> *list_prev = temp->prev;
						if (list_prev)
						{
							list_prev->next = x.getFirstElem();
							x.getFirstElem()->prev = list_prev;
						}
						else
							list_start = x.getFirstElem();
						temp->prev = x_last;
						x_last->next = temp;
						_size += x.size();
						list_end.prev = x.getLastElem();
						x.resetList();
					}
				}
			};//entire list
			void splice (iterator position, list& x, iterator i)
			{
				list<value_type> temp;
				temp.assign(1, *i);
				x.erase(i);
				this->splice(position, temp);
			};//single element
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				list<value_type> temp;
				temp.assign(first, last);
				x.erase(first, last);
				this->splice(position, temp);
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
			s_list<value_type>		list_end;
			std::allocator<value_type> allo;
			
			s_list<value_type> *getFirstElem() { return list_start; };
			s_list<value_type> *getLastElem()
			{
				s_list<value_type> *temp = list_start;
				while (temp->next)
					temp = temp->next;
				return temp;
			};
			size_type			getSize() { return _size; };
			void				setFirstElem(s_list<value_type> *elem) { list_start = elem; };
			s_list<value_type>	*getElem(iterator position)
			{
				iterator i_b = this->begin();
				iterator i_e = this->end();
				s_list<value_type> *temp = list_start;
				while (i_b != i_e)
				{
					if (i_b == position)
						break;//return temp;
					//if (temp->next)
						temp = temp->next;
					++i_b;
				}
				if (i_b == position)//also includes NULL if request is iter.end()
					return temp;
				return NULL;
			};
			void	resetList() { _size = 0; list_start = NULL; };
			template<typename InputIterator>
			void
			my_initialize_dispatch(InputIterator first, InputIterator last,
				false_type)
			{
				init_iter(first, last);
				list_end.prev = getLastElem();
				list_end.next = NULL;
			}
			template<typename Integer>
			void
			my_initialize_dispatch(Integer n,
			   Integer val, true_type)
			{
				init_int(n, val);
				list_end.prev = getLastElem();
				list_end.next = NULL;
			}
			void	init_iter(iterator first, iterator last)
			{
				while (first != last)
				{
					this->push_back(*first);
					++first;
				}
			}
			void	init_int(size_type n, value_type const & val)
			{
				while (n > 0)
				{
					this->push_back(val);
					n -= 1;
				}
			}
			template<typename InputIterator>
			iterator
			my_insert_dispatch(iterator position, InputIterator __first,
			   InputIterator __last, false_type)
			{
				return insert_iter(position, __first, __last);
			}
			template<typename Integer>
			iterator
			my_insert_dispatch(iterator position, Integer n,
			   Integer val, true_type)
			{
				return insert_int(position, n, val);
			}
			iterator	insert_int(iterator position, size_type n, const value_type& val)
			{
				list<value_type> temp_list(n, val);
				typename ft::list<value_type>::iterator ret_val = temp_list.begin();
				this->splice(position, temp_list);
				return ret_val;
			}
			iterator	insert_iter(iterator position, iterator first, iterator last)
			{
				list<value_type> temp_list(first, last);
				typename ft::list<value_type>::iterator ret_val = temp_list.begin();
				this->splice(position, temp_list);
				return ret_val;
			}
			template<typename InputIterator>
			void
			my_assign_dispatch(InputIterator __first,
			   InputIterator __last, false_type)
			{
				assign_iter(__first, __last);
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
				this->clear();
				while (n > 0)
				{
					this->push_back(val);
					n -= 1;
				}
			}
			void	assign_iter(iterator first, iterator last)
			{
				this->clear();
				while (first != last)
				{
					this->push_back(*first);
					++first;
				}
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
