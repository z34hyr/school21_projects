
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
	template < class T, class Alloc = std::allocator<T> >
	class vector
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

			explicit vector (const allocator_type& alloc = allocator_type()){ buffer_size = 0; real_size = 0; vect = NULL; };
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			{
				init_int(n, val);
			};
			template <class InputIterator>
         		vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
			{
				typedef typename is_integer<InputIterator>::__type _Integral;
	 			my_initialize_dispatch(first, last, _Integral());
			};
			vector (const vector& x)
			{
				buffer_size = 0;
				real_size = 0;
				vect = NULL;
				*this = x;
			};
			vector& operator= (const vector& x)
			{
				if (real_size)
				{
					std::cout << real_size << std::endl;
					for (size_type i = 0; i < real_size; i++)
						allo.destroy(&vect[i]);
					allo.deallocate(vect, buffer_size);
					buffer_size = 0;
					real_size = 0;
				}
				if ((vect = allo.allocate(x.size())))
				{
					buffer_size = x.capacity();
					real_size = x.size();
					for (size_type i = 0; i < real_size; i++)
					{
						allo.construct(&vect[i], x[i]);
					}
				}
				//this->assign(x.erase(x.begin(), x.begin()), x.erase(x.end(), x.end()));
				return *this;
			};
			~vector()
			{
				size_type i = 0;
				while (i < real_size)
				{
					allo.destroy(&vect[i]);
					i += 1;
				}
				allo.deallocate(vect, buffer_size);
			};
			
			//ITERATORS
			class iterator
			{
				public:
					typedef std::random_access_iterator_tag iterator_category;
					typedef typename Alloc::difference_type	difference_type;
					typedef typename Alloc::value_type		value_type;
					typedef typename Alloc::pointer			pointer;  // or also value_type*
					typedef typename Alloc::reference		reference;
					typedef typename Alloc::const_reference		const_reference;

					iterator() { m_ptr = NULL; };
					iterator(pointer value) : m_ptr(value) {};
					~iterator() {};
					// input iterator requirements
					iterator(iterator const & obj) { *this = obj; } ; // copy constructor
					iterator& operator= (iterator const & obj) { this->m_ptr = obj.m_ptr; return *this; }; //assignatiom overloading
					bool operator== (iterator const & obj) { return (m_ptr == obj.m_ptr); };
					bool operator!= (iterator const & obj) { return (m_ptr != obj.m_ptr); };
					bool operator< (iterator const & obj) const { return (m_ptr < obj.m_ptr); };
					bool operator> (iterator const & obj) const { return (m_ptr > obj.m_ptr); };
					bool operator<= (iterator const & obj) const { return (m_ptr <= obj.m_ptr); };
					bool operator>= (iterator const & obj) const { return (m_ptr >= obj.m_ptr); };
					pointer operator-> () const { return m_ptr; };
					//forward iterator requirements
					iterator& operator++() { m_ptr++; return *this; };
					iterator operator++(int) {iterator some = *this; ++(*this); return some; };
					//bidirectional iterator requirements
					iterator& operator--() { m_ptr--; return *this; };
					iterator operator--(int) { iterator some = *this; --(*this); return some; };
					//random iterator requirements
					iterator& operator+=(size_type n) { m_ptr = m_ptr + n; return *this; };
					iterator operator+(size_type n) const { iterator some = *this; some.m_ptr = some.m_ptr + n; return some; };
					iterator& operator-=(size_type n) { m_ptr = m_ptr - n; return *this; };            
					iterator operator-(size_type n) const { iterator some = *this; some.m_ptr = some.m_ptr - n; return some; };
					difference_type operator-(iterator it) const { return (this->m_ptr - it.m_ptr); };
					reference operator*() const { return *m_ptr; };
					reference operator[] (size_type n) const { return *(m_ptr + n); };
				private:
					pointer m_ptr;
			};
			class const_iterator
			{
				public:
					typedef std::random_access_iterator_tag iterator_category;
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
					const_iterator& operator+=(size_type n) { m_ptr = m_ptr + n; return *this; };
					const_iterator operator+(size_type n) const { const_iterator some = *this; some.m_ptr = some.m_ptr + n; return some; };
					const_iterator& operator-=(size_type n) { m_ptr = m_ptr - n; return *this; };            
					const_iterator operator-(size_type n) const { const_iterator some = *this; some.m_ptr = some.m_ptr - n; return some; };
					difference_type operator-(const_iterator it) const { return (this->m_ptr - it.m_ptr); };
					reference operator*() const { return *m_ptr; };
					reference operator[] (size_type n) const { return *(m_ptr + n); };
				private:
					pointer m_ptr;
			};
			class reverse_iterator
			{
				public:
					typedef std::random_access_iterator_tag iterator_category;
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
					reverse_iterator& operator+=(difference_type n) { m_ptr = m_ptr - n; return *this; };
					reverse_iterator operator+(difference_type n) const { iterator some = *this; some.m_ptr = some.m_ptr - n; return some; };
					reverse_iterator& operator-=(difference_type n) { m_ptr = m_ptr + n; return *this; };            
					reverse_iterator operator-(difference_type n) const { iterator some = *this; some.m_ptr = some.m_ptr + n; return some; };
					difference_type operator-(iterator it) const { return (this->m_ptr + it.m_ptr); };
					reference operator*() const
					{
						iterator temp = m_ptr;
						return *--temp;
					};
					reference operator[] (difference_type n) const { return *(m_ptr + n); };
				private:
					pointer m_ptr;
			};
			class const_reverse_iterator
			{
				public:
					typedef std::random_access_iterator_tag iterator_category;
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
					//random iterator requirements
					const_reverse_iterator& operator+=(difference_type n) { m_ptr = m_ptr - n; return *this; };
					const_reverse_iterator operator+(difference_type n) const { const_reverse_iterator some = *this; some.m_ptr = some.m_ptr - n; return some; };
					const_reverse_iterator& operator-=(difference_type n) { m_ptr = m_ptr + n; return *this; };            
					const_reverse_iterator operator-(difference_type n) const { iterator some = *this; some.m_ptr = some.m_ptr + n; return some; };
					difference_type operator-(iterator it) const { return (this->m_ptr + it.m_ptr); };
					reference operator*() const
					{
						iterator temp = m_ptr;
						return *--temp;
					};
					reference operator[] (difference_type n) const { return *(m_ptr + n); };
				private:
					pointer m_ptr;
			};
			iterator begin() { return (real_size > 0 ? iterator(&vect[0]) : NULL); };
			const_iterator begin() const { return (real_size > 0 ? iterator(&vect[0]) : NULL); };
			iterator end() { return (real_size > 0 ? iterator(&vect[real_size]) : NULL); };
			const_iterator end() const { return const_iterator(&vect[real_size]); };
			reverse_iterator rbegin() { return (real_size > 0 ? reverse_iterator(&vect[real_size]) : NULL); };
			const_reverse_iterator rbegin() const { return (real_size > 0 ? const_reverse_iterator(&vect[real_size]) : NULL); };
			reverse_iterator rend() { return (real_size > 0 ? reverse_iterator(&vect[0]) : NULL); };
			const_reverse_iterator rend() const { return (real_size > 0 ? const_reverse_iterator(&vect[0]) : NULL); };

			// CAPACITY
			size_type	size() const { return real_size; };
			size_type	max_size() const { return std::numeric_limits<size_type>::max() / sizeof(value_type); };
			void		resize(size_type n, value_type val = value_type())
			{
				if (n < real_size) // clean elements between n and real_size
				{
					while (real_size > n)
					{
						allo.destroy(&vect[real_size - 1]);
						real_size -= 1;
					}
				}
				else if (n > real_size && n < buffer_size) // fill elements with val after real_size to n
				{
					while (real_size < n)
					{
						allo.construct(&vect[real_size], val);
						real_size += 1;
					}
				}
				else if (n > buffer_size)
				{
					this->reserve(n);
					while (real_size < buffer_size)
					{
						allo.construct(&vect[real_size++], val);
					}
				}
			};
			size_type	capacity() const { return buffer_size; };
			bool		empty() const { return (!real_size ? true : false); };
			void		reserve (size_type n)
			{
				if (n > buffer_size) //realloc
				{
					size_type i = 0;
					value_type* temp = vect;
					if ((vect = allo.allocate(n)))
					{
						while (i < real_size)
						{
							vect[i] = temp[i];
							i += 1;
						}
						allo.deallocate(temp, buffer_size);
						buffer_size = n;
					}
				}
			};

			///////////////////////////////////////////////////////////////////////
			///				ELEMENTS ACCESS. return ref or const ref		///////
			///////////////////////////////////////////////////////////////////////
			reference		operator[] (size_type n) { return vect[n]; };
			const_reference	operator[] (size_type n) const { return vect[n]; };
			reference		at (size_type n)
			{
				if (n < real_size) 
					return vect[n]; 
				else
				{
					std::stringstream ss1, ss2;
					ss1 << n; ss2 << real_size;
					std::string err = "vector.at(n): range check error: n (which is " + (std::string)ss1.str() + ") >= this->size() (which is " + (std::string)ss2.str() + ")";
					throw std::out_of_range(err);
				}
			};
			const_reference	at (size_type n) const
			{
				if (n < real_size) 
					return vect[n]; 
				else
				{
					std::stringstream ss1, ss2;
					ss1 << n;
					ss2 << real_size;
					std::string err = "vector.at(n): range check error: n (which is " + (std::string)ss1.str() + ") >= this->size() (which is " + (std::string)ss2.str() + ")";
					throw std::out_of_range(err);
				}
			};
			reference		front() { return vect[0]; };
			const_reference	front() const { return vect[0]; };
			reference		back() { return vect[real_size - 1]; };
			const_reference	back() const { return vect[real_size - 1]; };

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
			void 		push_back (const value_type& val)
			{
				if (real_size == buffer_size) //realloc
				{
					value_type* temp = vect;
					size_type	temp_size = buffer_size;
					buffer_size = (buffer_size > 0 ? buffer_size << 1 : 1);
					if ((vect = allo.allocate(buffer_size)))
					{
						size_type i = 0;
						while (i < real_size)
						{
							vect[i] = temp[i];
							i += 1;
						}
						allo.construct(&vect[i], val);
						allo.deallocate(temp, temp_size);
					}
				}
				else //just put in array
					allo.construct(&vect[real_size], val);
				real_size += 1;
			};
			void		pop_back()
			{
				if (real_size > 0)
				{
					real_size -= 1;
					allo.destroy(&vect[real_size]);
				}
			};
			iterator	insert (iterator position, const value_type& val)
			{
				iterator to_return = NULL;
				if (position >= this->begin() && position <= this->end())
				{
					size_type 	i = 0;
					if (real_size == buffer_size) // realloc
					{
						value_type* temp = vect;
						iterator old_b = &temp[0];
						iterator old_e = &temp[real_size];
						buffer_size <<= 1;
						if ((vect = allo.allocate(buffer_size)))
						{
							while (old_b < position) // copy before 'position'
							{
								vect[i] = *old_b;
								to_return = (iterator)&vect[i];
								allo.destroy(&temp[i]);
								i += 1;
								++old_b;
							}
							allo.construct(&vect[i++], val); // new elem on 'position'
							while (position < old_e) // copy after 'position'
							{
								vect[i] = *position;
								allo.destroy(&temp[i - 1]);
								i += 1;
								++position;
							}
							real_size += 1;
							allo.deallocate(temp, (buffer_size >> 1));
							return to_return;
						}
					}
					else
					{
						iterator i_b = &vect[0];
						iterator i_e = &vect[real_size];
						while (position < i_e)
						{
							*i_e = *(i_e - 1);
							--i_e;
						}
						*i_e = val;
						real_size += 1;
						return position;
					}
				}
				return to_return;
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
				iterator to_return = NULL;
				iterator i_e = this->end();
				iterator i_b = this->begin();
				if (position >= i_b && position <= i_e)
				{
					size_type pos = (size_type)(position - i_b);
					allo.destroy(&vect[pos]);
					to_return = position;
					while (position < i_e - 1)
					{
						*position = *(position + 1);
						++position;
					}
					real_size -= 1;
				}
				return to_return;
			};
			iterator	erase (iterator first, iterator last)
			{
				iterator to_return = NULL;
				iterator i_e = this->end();
				iterator i_b = this->begin();

				if (first >= i_b && first <= i_e && last >= i_b && last <= i_e)
				{
					to_return = last;
					if (first < last)
					{
						size_type pos = (size_type)(first - i_b);
						size_type len = (size_type)(last - first);
						for (size_type i = 0; i < len; i++)
							allo.destroy(&vect[i + pos]);
						while (last < i_e)
						{
							*first = *last;
							++first;
							++last;
						}
						real_size -= len;
					}
				}
				return to_return;
			};
			void		swap (vector& x)
			{
				vector temp(*this);
				//temp = *this;
				*this = x;
				x = temp;
			};
			void		clear()
			{
				size_type	i = 0;

				while (i < real_size)
					allo.destroy(&vect[i++]);
				real_size = 0;
			};
		private:
			size_type	buffer_size;
			size_type	real_size;
			value_type* vect;
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
				vect = NULL;
				buffer_size = 0;
				real_size = 0;
				if ((vect = allo.allocate(last - first)))
				{
					buffer_size = (size_type)(last - first);
					real_size = buffer_size;
					for (size_type i = 0; i < real_size; i++)
					{
						allo.construct(&vect[i], *first);
						++first;
					}
				}
			}
			void	init_int(size_type n, value_type const & val)
			{
				vect = NULL;
				buffer_size = 0;
				real_size = 0;
				if ((vect = allo.allocate(n)))
				{
					buffer_size = n;
					real_size = buffer_size;
					for (size_type i = 0; i < real_size; i++)
						allo.construct(&vect[i], val);
				}
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
				if (position >= this->begin() && position <= this->end())
				{
					size_type 	i = 0;
					if (real_size + n >= buffer_size) // realloc
					{
						value_type* temp = vect;
						value_type	old_buffer_size = buffer_size;
						iterator old_b = &temp[0];
						iterator old_e = &temp[real_size];
						buffer_size = real_size + n;
						if ((vect = allo.allocate(buffer_size)))
						{
							while (old_b < position) // copy before 'position'
							{
								vect[i] = *old_b;
								allo.destroy(&temp[i]);
								i += 1;
								++old_b;
							}
							real_size += n;			
							while (n > 0) // past new elems since 'position'
							{
								allo.construct(&vect[i++], val);
								n -= 1;
							}
							while (position < old_e) // copy elems after 'position'
							{
								vect[i] = *position;
								allo.destroy(&temp[i - 1]);
								i += 1;
								++position;
							}
							allo.deallocate(temp, old_buffer_size);
						}
					}
					else
					{
						iterator i_b = &vect[0];
						iterator i_e = &vect[real_size - 1];
						while (position < i_e + 1)
						{
							*(i_e + n) = *(i_e);
							--i_e;
						}
						real_size += n;
						while (n > 0)
						{
							*position = val;
							++position;
							n -= 1;
						}
					}
				}
			}
			void	insert_iter(iterator position, size_type n, iterator first)
			{
				if (position >= this->begin() && position <= this->end())
				{
					size_type 	i = 0;
					if (real_size + n >= buffer_size) // realloc
					{
						value_type* temp = vect;
						value_type	old_buffer_size = buffer_size;
						iterator old_b = &temp[0];
						iterator old_e = &temp[real_size];
						buffer_size = real_size + n;
						if ((vect = allo.allocate(buffer_size)))
						{
							while (old_b < position) // copy before 'position'
							{
								vect[i] = *old_b;
								allo.destroy(&temp[i]);
								i += 1;
								++old_b;
							}
							real_size += n;			
							while (n > 0) // past new elems since 'position'
							{
								allo.construct(&vect[i++], *first);
								++first;
								n -= 1;
							}
							while (position < old_e) // copy elems after 'position'
							{
								vect[i] = *position;
								allo.destroy(&temp[i - 1]);
								i += 1;
								++position;
							}
							allo.deallocate(temp, old_buffer_size);
						}
					}
					else
					{
						iterator i_b = &vect[0];
						iterator i_e = &vect[real_size - 1];
						while (position < i_e + 1)
						{
							*(i_e + n) = *(i_e);
							--i_e;
						}
						real_size += n;
						while (n > 0)
						{
							*position = *first;
							++position;
							++first;
							n -= 1;
						}
					}
				}
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
				if (buffer_size)
				{
					while (real_size)
						allo.destroy(&vect[real_size-- - 1]);
					allo.deallocate(vect, buffer_size);
				}
				if ((vect = allo.allocate(n)))
				{
					buffer_size = n;
					real_size = n;
					for (size_type i = 0; i < n; i++)
						allo.construct(&vect[i], val);
				}
			}
			void	assign_iter(size_type n, iterator first)
			{
				if (buffer_size)
				{
					while (real_size)
						allo.destroy(&vect[real_size-- - 1]);
					allo.deallocate(vect, buffer_size + 1);
				}
				if ((vect = allo.allocate(n)))
				{
					buffer_size = n;
					real_size = n;
					for (size_type i = 0; i < n; i++)
					{
						allo.construct(&vect[i], *(first));
						++first;
					}
				}
			}

	};

	// Non-member function overloads
	template <typename T, class Alloc>
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		typename ft::vector<T, Alloc> temp;
		temp = x;
		x = y;
		y = temp;
	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename ft::vector<T,Alloc>::const_iterator li_b = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator li_e = lhs.end();
		typename ft::vector<T,Alloc>::const_iterator ri_b = rhs.begin();
		typename ft::vector<T,Alloc>::const_iterator ri_e = rhs.end();

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
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !ft::operator==(lhs, rhs);
	};
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename ft::vector<T,Alloc>::const_iterator li_b = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator li_e = lhs.end();
		typename ft::vector<T,Alloc>::const_iterator ri_b = rhs.begin();
		typename ft::vector<T,Alloc>::const_iterator ri_e = rhs.end();

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
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		typename ft::vector<T,Alloc>::const_iterator li_b = lhs.begin();
		typename ft::vector<T,Alloc>::const_iterator li_e = lhs.end();
		typename ft::vector<T,Alloc>::const_iterator ri_b = rhs.begin();
		typename ft::vector<T,Alloc>::const_iterator ri_e = rhs.end();
		
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
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !ft::operator>(lhs, rhs);
	};
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return !ft::operator<(lhs, rhs);
	};

}
