
#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <limits>
#include <stdexcept>
#include <cstdlib>
#include <sstream>

#include "is_integer.hpp"
#include "list_structure.hpp"

namespace ft
{
	template <class T>
	class list
	{
		public:
			typedef T								value_type;
			typedef s_list<value_type>				list_struct;
			typedef const s_list<value_type>		list_const_struct;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef ptrdiff_t						difference_type;
			typedef size_t							size_type;
			typedef list_iterator<value_type>		iterator;
			typedef list_const_iterator<value_type>	const_iterator;
			typedef list_reverse_iterator<value_type>		reverse_iterator;
			typedef list_const_reverse_iterator<value_type>		const_reverse_iterator;

		private:
			size_type		_size;
			list_struct		*list_start;
			list_struct		list_end;

		public:
			explicit list () : list_start(NULL)
			{
				_size = 0;
				list_end.prev = NULL;
				list_end.next = NULL;
			};//default
			explicit list (size_type n, const value_type& val = value_type()) : list_start(NULL)
			{
				_size = 0;
				init_int(n, val);
				list_end.prev = getLastElem();
				list_end.next = NULL;
			};//fill
			template <class InputIterator>
         		list (InputIterator first, InputIterator last) : list_start(NULL)
			{
				_size = 0;
				typedef typename is_integer<InputIterator>::__type _Integral;
	 			my_initialize_dispatch(first, last, _Integral());
			};
			list (const list& x) : list_start(NULL)
			{
				this->operator=(x);
			};
			list& operator= (const list& x)
			{
				if (list_start)
					this->clear();
				list_struct *x_str = x.getFirstElem();
				while (x_str && x_str->next)
				{
					this->push_back(x_str->val);
					x_str = x_str->next;
				}
				return *this;
			};
			~list()
			{
				while (list_start && list_start != &list_end)
				{
					delete list_start;
					list_start = list_start->next;
				}
			};
			iterator begin()
			{
				if (!list_start)
					return end();
				return iterator(list_start, &list_end);
			};
			const_iterator begin() const
			{
				if (!list_start)
					return end();
				return const_iterator(list_start, &list_end);
			};
			iterator end() { return iterator(&list_end, &list_end); };
			const_iterator end() const { return const_iterator(&list_end, &list_end); };
			reverse_iterator rbegin() { return reverse_iterator(&list_end, &list_end); };
			const_reverse_iterator rbegin() const { return const_reverse_iterator(&list_end, &list_end); };
			reverse_iterator rend()
			{
				if (!list_start)
					return rbegin();
				return reverse_iterator(list_start, &list_end);
			};
			const_reverse_iterator rend() const
			{
				if (!list_start)
					return rbegin();
				return const_reverse_iterator(list_start, &list_end);
			}

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
			reference		back() { return *(--end()); };
			const_reference	back() const { return *(--end()); };
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
				list_struct *new_elem = new list_struct;
				new_elem->val = val;
				if (list_end.prev)
				{
					new_elem->next = list_start;
					list_start->prev = new_elem;
					list_start = new_elem;
				}
				else
				{
					list_start = new_elem;
					list_end.prev = list_start;
					new_elem->next = &list_end;
				}
				_size += 1;
			};
			void		pop_front()
			{
				if (list_end.prev)
				{
					delete list_start;
					list_start->next->prev = NULL;
					list_start = list_start->next;
					_size -= 1;
				}
			};
			void 		push_back (const value_type& val)
			{
				if (!list_start)
				{
					list_start = new list_struct;
					list_start->val = val;
					list_start->prev = NULL;
					list_start->next = &list_end;
					list_end.prev = list_start;
				}
				else
				{
					list_struct *new_elem = new list_struct;
					new_elem->val = val;
					new_elem->next = &list_end;
					list_struct *temp = list_end.prev;
					list_end.prev = new_elem;
					temp->next = new_elem;
					new_elem->prev = temp;
				}
				_size += 1;
			};
			void		pop_back()
			{
				if (list_end.prev)
				{
					if (list_end.prev->prev)
					{
						list_struct *new_prelast = list_end.prev->prev;
						delete new_prelast->next;
						new_prelast->next = &list_end;
						list_end.prev = new_prelast;
					}
					else
					{
						delete list_start;
						list_end.prev = NULL;
						list_start = NULL;
					}
					_size -= 1;
				}
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
				iterator temp = position;
				if (position == this->end())
					return position;
				list_struct *needed = getElem(position);
				if (needed && needed->prev)
				{
					needed->prev->next = needed->next;
					needed->next->prev = needed->prev;
				}
				else // change list_Start
				{
					needed->next->prev = NULL;
					list_start = (needed->next == &list_end ? NULL : needed->next);
				}
				delete needed;
				_size -= 1;
				return ++temp;;
			};
			iterator	erase (iterator first, iterator last)
			{
				while (first != last)
					first = erase(first);
				return first;
			};
			void		swap (list& x)
			{
				list_struct *temp_start = list_start;
				list_struct *temp_end_prev = list_end.prev;
				list_struct *x_end = x.getEnd();
				list_struct *temp_x_prev = x.getLastElem();
				
				list_start = x.getFirstElem();
				list_end.prev = temp_x_prev;
				temp_x_prev->next = &list_end;

				x.setFirstElem(temp_start);
				temp_end_prev->next = x_end;
				x_end->prev = temp_end_prev;
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
					list_end.prev->next = &list_end;
					x.resetList();
				}
				else
				{
					list_struct *temp = this->list_start;
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
						list_struct *x_last = x.getFirstElem();
							while (x_last->next && x_last->next->next)
								x_last = x_last->next;
						if (i_b == i_e)// case "after last elem"
						{
							temp->next = x.getFirstElem();
							temp->next->prev = temp;
							_size += x.size();
							list_end.prev = x.getLastElem();
							list_end.prev->next = &list_end;
							x.resetList();
							return;
						}
						list_struct *list_prev = temp->prev;
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
				iterator i_b = this->begin();
				iterator i_e = this->end();
				const value_type vzz = val;
				while (i_b != i_e)
				{
					if (*i_b == vzz)
						i_b = erase(i_b);
					else
						++i_b;
				}
			};
			template <class Predicate>
  				void remove_if (Predicate pred)
			{
				iterator i_b = this->begin();
				iterator i_e = this->end();
				while (i_b != i_e)
				{
					if (pred(*i_b))
					{
						erase(i_b);
						remove_if(pred);
						break;
					}
					else
						++i_b;
				}
			};
			void unique()
			{
				if (_size > 0)
				{
					list<value_type> new_list;
					while (_size > 0)
					{
						new_list.push_back(*this->begin());
						const value_type& val = *this->begin();
						this->remove(val);
					}
					this->splice(this->begin(), new_list);
				}
			};
			template <class BinaryPredicate>
				void unique (BinaryPredicate binary_pred)
			{
				iterator i_b = this->begin();
				if (i_b == this->end())
					return ;
				iterator next = i_b;
				++next;
				while (next != this->end())
				{
					if (binary_pred(*next, *i_b))
						next = erase(next);
					else
					{
						i_b = next;
						++next;
					}
				}
				
			};
			void merge (list& x)
			{
				if (&x != this)
				{
					this->splice(this->end(), x);
					this->sort();
				}
			};
			template <class Compare>
				void merge (list& x, Compare comp)
			{
				if (&x != this)
				{
					this->splice(this->end(), x);
					this->sort(comp);
				}
			};
			void sort()
			{
				list_struct *temp = this->getFirstElem();
				while (temp && temp->next && temp->next->next)
				{
					if (temp->val > temp->next->val)
					{
						value_type temp_val = temp->val;
						temp->val = temp->next->val;
						temp->next->val = temp_val;
						this->sort();
						break;
					}
					else
						temp = temp->next;
				}
			};
			template <class Compare>
				void sort (Compare comp)
			{
				list_struct *temp = this->getFirstElem();
				while (temp && temp->next && temp->next->next)
				{
					if (!comp(temp->next->val, temp->val))
						temp = temp->next;
					else
					{
						value_type temp_val = temp->val;
						temp->val = temp->next->val;
						temp->next->val = temp_val;
						this->sort(comp);
						break;
					}
				}
			};
			void reverse()
			{
				iterator i_b = this->begin();
				iterator i_e = this->end();
				
				while (i_b != i_e)
				{
					value_type temp = *--i_e;
					*i_e = *i_b;
					*i_b = temp;
					if (i_b != i_e)
						++i_b;
				}
			};

		private:
			
			list_struct *getFirstElem() const { return list_start; };
			list_struct *getLastElem() const { return list_end.prev; };
			list_struct *getEnd() { return &list_end; };
			void				setFirstElem(list_struct *elem) { list_start = elem; };
			void				setSize(size_type size) { _size = size; };
			void				setEndPrev(list_struct *elem) { list_end.prev = elem; };
			//void				
			//list_struct	*getEndPrev() { return list_end.prev; };
			list_struct	*getElem(iterator position)
			{
				iterator i_b = this->begin();
				iterator i_e = this->end();
				list_struct *temp = list_start;
				while (i_b != i_e)
				{
					if (i_b == position)
						break;
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
				list_end.next = NULL;
				init_iter(first, last);
			}
			template<typename Integer>
			void
			my_initialize_dispatch(Integer n,
			   Integer val, true_type)
			{
				list_end.next = NULL;
				init_int(n, val);
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
	template <typename T>
		void swap (list<T>& x, list<T>& y)
	{
		x.swap(y);
	};
	
	template <class T>
		bool operator== (const list<T>& lhs, const list<T>& rhs)
	{
		typename ft::list<T>::const_iterator li_b = lhs.begin();
		typename ft::list<T>::const_iterator li_e = lhs.end();
		typename ft::list<T>::const_iterator ri_b = rhs.begin();
		typename ft::list<T>::const_iterator ri_e = rhs.end();
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
	template <class T>
		bool operator!= (const list<T>& lhs, const list<T>& rhs)
	{
		return !ft::operator==(lhs, rhs);
	};
	template <class T>
		bool operator<  (const list<T>& lhs, const list<T>& rhs)
	{
		typename ft::list<T>::const_iterator li_b = lhs.begin();
		typename ft::list<T>::const_iterator li_e = lhs.end();
		typename ft::list<T>::const_iterator ri_b = rhs.begin();
		typename ft::list<T>::const_iterator ri_e = rhs.end();

		while (li_b != li_e && ri_b != ri_e)
		{
			if (*li_b < *ri_b)
				return true;
			++li_b;
			++ri_b;
		}
		return (ri_b == ri_e ? false : true); 
	};
	template <class T>
		bool operator>  (const list<T>& lhs, const list<T>& rhs)
	{
		typename ft::list<T>::const_iterator li_b = lhs.begin();
		typename ft::list<T>::const_iterator li_e = lhs.end();
		typename ft::list<T>::const_iterator ri_b = rhs.begin();
		typename ft::list<T>::const_iterator ri_e = rhs.end();
		
		while (li_b != li_e && ri_b != ri_e)
		{
			if (*li_b > *ri_b)
				return true;
			++li_b;
			++ri_b;
		}
		return (li_b == li_e ? false : true); 
	};
	template <class T>
		bool operator<= (const list<T>& lhs, const list<T>& rhs)
	{
		return !ft::operator>(lhs, rhs);
	};
	template <class T>
		bool operator>= (const list<T>& lhs, const list<T>& rhs)
	{
		return !ft::operator<(lhs, rhs);
	};
}
