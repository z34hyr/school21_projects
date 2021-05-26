
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
#include "binary_search_tree.hpp"

namespace ft
{
	template <	class Key,                                    		// map::key_type
    			class T,                                       		// map::mapped_type
    			class Compare = std::less<Key> >                     // map::key_compare
	class map
	{
		public:
			typedef bst<Key, T, Compare>					bst_struct;
			typedef	typename bst_struct::key_type			key_type;
			typedef typename bst_struct::mapped_type		mapped_type;
			typedef	Compare									key_compare;
			typedef	std::pair<const key_type,mapped_type>	value_type;
			typedef bst_node<value_type>*					node_ptr;
			typedef value_type&								reference;
			typedef value_type const &						const_reference;
			typedef value_type*								pointer;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;
			typedef typename bst_struct::iterator			iterator;
			typedef typename bst_struct::const_iterator	const_iterator;
			typedef typename bst_struct::reverse_iterator	reverse_iterator;
			typedef typename bst_struct::const_reverse_iterator	const_reverse_iterator;

			// special for value_type comparator
			template<typename arg1, typename arg2, typename result>
			struct binary_res_function
			{
					typedef arg1 arg1_argument_type;
					typedef arg2 arg2_argument_type;
					typedef result result_type;
			};
			class value_compare :
				public binary_res_function<value_type, value_type, bool>
			{
				private:
					key_compare compare;

				protected:
					value_compare(key_compare comparator) : compare(comparator) {}

				public:
					bool operator()(const value_type &x, const value_type &y) const
					{
						return (compare(x.first, y.first));
					}
			};
			

		private:
			size_type	_size;
			bst_struct	holder;

		public:
			explicit map (const key_compare& comp = key_compare()) : holder(comp)
			{
				_size = 0;
			};//empty
			template <class InputIterator>
				map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare()) : holder(comp)
			{
				_size = 0;
				this->insert(first, last);
			};//range
			map (const map& x)
			{
				_size = 0;
				this->operator=(x);
			};//copy constructor
			map& operator= (const map& x)
			{
				if (this != &x)
				{
					this->clear();
					this->insert(x.begin(), x.end());
				}
				return *this;
			};// assignment operator overload
			~map() {};
			iterator begin() { return holder.begin(); };
			const_iterator begin() const { return holder.begin(); };
			iterator end() { return holder.end(); };
			const_iterator end() const { return holder.end(); };
			reverse_iterator rbegin() { return holder.rbegin(); };
			const_reverse_iterator rbegin() const { return holder.end(); };
			reverse_iterator rend() { return holder.rend(); };
			const_reverse_iterator rend() const { return holder.rend(); };

			// CAPACITY
			size_type	size() const { return holder.get_size(); };
			size_type	max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); };

			bool		empty() const { return (!holder.get_size() ? true : false); };

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
				return holder.remove(k);
			};// single element by key
			void erase (iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			};// range by iterators diapasone
			void		swap (map& x)
			{
				holder.swap(x.holder);
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
				return holder.key_comp();
			};
			value_compare value_comp() const
			{
				return value_compare();
			};

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
			const_iterator lower_bound (const key_type& k) const
			{
				return holder.lower_bound_const(k);
			};
			iterator lower_bound (const key_type& k)
			{
				return holder.lower_bound(k);
			};
			
			iterator upper_bound (const key_type& k)
			{
				return holder.upper_bound(k);
			};
			const_iterator upper_bound (const key_type& k) const
			{
				return holder.upper_bound(k);
			};
			std::pair<iterator, iterator>             equal_range (const key_type& k)
			{
				iterator lb = lower_bound(k);
				return std::pair<iterator, iterator>(lb, lb);
			};
			std::pair<const_iterator, const_iterator> equal_range (const key_type& k) const
			{
				const_iterator lb = lower_bound(k);
				return std::pair<const_iterator, const_iterator>(lb, lb);
			};
	};
}
