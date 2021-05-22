
#pragma once

#include <iostream>
#include <cstddef>
#include <string>
#include <memory>
#include <limits>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <functional>
#include <utility>

#include "is_integer.hpp"
#include "binary_search_tree.cpp" // OFC must change to hpp

namespace ft
{
	template <	class Key,                                    		// map::key_type
    			class T,                                       		// map::mapped_type
    			class Compare = std::less<Key> >                     // map::key_compare
	class map
	{
		public:
			typedef bst<Key, T, Compare> bst_struct;
			typedef	typename bst_struct::key_type			key_type;
			typedef typename bst_struct::mapped_type		mapped_type;
			typedef	Compare									key_compare;
			typedef	std::pair<const key_type,mapped_type>	value_type;
			typedef value_type&								reference;
			typedef value_type const &						const_reference;
			typedef value_type*								pointer;
			typedef value_type const *						const_pointer;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;
			typedef typename bst_struct::iterator			iterator;
			typedef typename bst_struct::const_iterator	const_iterator;

		private:
			size_type	_size;
			bst_struct	holder;

		public:
			explicit map (const key_compare& comp = key_compare())
			{
				std::cout << "Empty constructor\n";
			};//empty
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare())
			{
				std::cout << "Iterator constructor\n";
			};//range
			map (const map& x)
			{
				
			};
			map& operator= (const map& x)
			{

			};
			~map()
			{

			};
			iterator begin() { return holder.begin(); };
			const_iterator begin() const { return holder.begin(); };
			iterator end() { return holder.end(); };
			const_iterator end() const { return holder.end(); };
		//	reverse_iterator rbegin() { return (real_size > 0 ? reverse_iterator(&vect[real_size]) : NULL); };
		//	const_reverse_iterator rbegin() const { return (real_size > 0 ? const_reverse_iterator(&vect[real_size]) : NULL); };
		//	reverse_iterator rend() { return (real_size > 0 ? reverse_iterator(&vect[0]) : NULL); };
		//	const_reverse_iterator rend() const { return (real_size > 0 ? const_reverse_iterator(&vect[0]) : NULL); };

			// CAPACITY
			size_type	size() const { return holder.get_size(); };
			size_type	max_size() const
			{

			};
			bool		empty() const { return (holder.get_size() ? true : false); };

			///////////////////////////////////////////////////////////////////////
			///				ELEMENTS ACCESS.								///////
			///////////////////////////////////////////////////////////////////////
			mapped_type& operator[] (const key_type& k)
			{
				return holder.operator[](k);
			};

			///////////////////////////////////////////////////////////////////////
			///				MODIFIERS										///////
			///////////////////////////////////////////////////////////////////////
			std::pair<iterator,bool> insert (const value_type& val)
			{
				return holder.insert(val);
			};// single element
			iterator insert (iterator position, const value_type& val)
			{
				return holder.insert(position, val);
			};// with hint
			template <class InputIterator>
				void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					std::pair<key_type, mapped_type> new_val(first->first, first->second);
					holder.insert(new_val);
					++first;
				}
			};// range
			void erase (iterator position)
			{
				holder.remove(position->first);
			};// single element by iterator
			size_type erase (const key_type& k)
			{
				holder.remove(k);
				return holder.get_size();
			};// single element by key
			void erase (iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			};// range by iteratorors diapasone
			void		swap (map& x)
			{

			};
			void		clear()
			{
				holder.clear();
			};

			///////////////////////////////////////////////////////////////////////
			///				OBSERVERS										///////
			///////////////////////////////////////////////////////////////////////
			key_compare key_comp() const
			{

			};
			// value_compare value_comp() const
			// {

			// };

			///////////////////////////////////////////////////////////////////////
			///				OPERATIONS										///////
			///////////////////////////////////////////////////////////////////////
			iterator find (const key_type& k)
			{
				return holder.find(k);
			};
			const_iterator find (const key_type& k) const
			{
				return holder.find(k);
			};
			size_type count (const key_type& k) const
			{
				const_iterator i_e = this->end();
				const_iterator to_find = this->find(k);
				if (to_find != i_e)
					return 1;
				return 0;
			};
			iterator lower_bound (const key_type& k)
			{

			};
			// const_iterator lower_bound (const key_type& k) const
			// {

			// };
			iterator upper_bound (const key_type& k)
			{

			};
			// const_iterator upper_bound (const key_type& k) const
			// {

			// };
			// std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			// {

			// };
			std::pair<iterator,iterator>             equal_range (const key_type& k)
			{

			};

		private:
			template<typename InputIterator>
			void
			my_initialize_dispatch(InputIterator first, InputIterator last,
				false_type)
			{

			}
			template<typename Integer>
			void
			my_initialize_dispatch(Integer n,
			   Integer val, true_type)
			{

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

			}
			template<typename Integer>
			void
			my_insert_dispatch(iterator position, Integer n,
			   Integer val, true_type)
			{

			}
			void	insert_int(iterator position, size_type n, const value_type& val)
			{

			}
			void	insert_iter(iterator position, size_type n, iterator first)
			{

			}
	};

}
