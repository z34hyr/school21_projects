
#pragma once

#include <cstddef>
#include <iostream>
#include <string>

template <class T>
	struct s_list
	{
		typedef	s_list*	s_list_ptr;
		typedef const s_list* s_list_const_ptr;
		typedef T	value_type;
		value_type	val;
		s_list*		prev;
		s_list*		next;
		
		s_list() : prev(NULL), next(NULL) {};
		s_list(s_list& obj) : val(obj.val), prev(obj.prev), next(obj.next) {};
	};

//ITERATORS

template <typename Value>
	class list_const_iterator;

template <typename Value>
	class list_iterator
{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef Value							value_type;
		typedef s_list<value_type>*				node_ptr;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef list_const_iterator<value_type>	list_const_iterator;
		
	private:
		node_ptr	m_node;
		node_ptr	list_end;

	public:
		list_iterator() : m_node(), list_end() { };

		list_iterator(node_ptr node, node_ptr end_ptr) : m_node(node), list_end(end_ptr) {};
		operator list_const_iterator()
		{
			return list_const_iterator(this->m_node, this->list_end);
		};
		// input iterator requirements
		list_iterator(list_iterator const & obj) { this->operator=(obj); } ; // copy constructor
		
		~list_iterator() {};
		list_iterator& operator= (list_iterator const & obj)
		{
			if (&obj != this)
			{
				this->m_node = obj.m_node;
				this->list_end = obj.list_end;
			}
			return *this;
		}; //assignatiom overloading
		bool operator== (list_iterator const & obj) { return (m_node == obj.m_node); };
		bool operator!= (list_iterator const & obj) { return (m_node != obj.m_node); };
		pointer operator-> () { return m_node->val; };
		//forward iterator requirements
		list_iterator& operator++()
		{
			m_node = m_node->next;
			return *this;
		};
		list_iterator operator++(int) {list_iterator some = *this; ++(*this); return some; };
		//bidirectional iterator requirements
		list_iterator& operator--()
		{
			m_node = m_node->prev;
			return *this;
		};
		list_iterator operator--(int) { list_iterator some = *this; --(*this); return some; };
		reference operator*() { return m_node->val; };
};

template <typename Value>
	class list_const_iterator
{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef Value							value_type;
		typedef const s_list<value_type>*		node_const_ptr;
		typedef value_type*						pointer;
		typedef const value_type&				reference;
		typedef const value_type&				const_reference;
		//typedef list_const_iterator<value_type>	list_const_iterator;
		
	private:
		node_const_ptr	m_node;
		node_const_ptr	list_end;

	public:
		list_const_iterator() : m_node(), list_end() { };

		list_const_iterator(node_const_ptr node, node_const_ptr end_ptr) : m_node(node), list_end(end_ptr) {};
		// input iterator requirements
		list_const_iterator(list_const_iterator const & obj) { this->operator=(obj); } ; // copy constructor
		~list_const_iterator() {};
		list_const_iterator& operator= (list_const_iterator const & obj)
		{
			if (&obj != this)
			{
				this->m_node = obj.m_node;
				this->list_end = obj.list_end;
			}
			return *this;
		}; //assignatiom overloading
		bool operator== (list_const_iterator const & obj) { return (m_node == obj.m_node); };
		bool operator!= (list_const_iterator const & obj) { return (m_node != obj.m_node); };
		pointer operator-> () const { return m_node->val; };
		//forward iterator requirements
		list_const_iterator& operator++()
		{
			m_node = m_node->next;
			return *this;
		};
		list_const_iterator operator++(int) {list_const_iterator some = *this; ++(*this); return some; };
		//bidirectional iterator requirements
		list_const_iterator& operator--()
		{
			m_node = m_node->prev;
			return *this;
		};
		list_const_iterator operator--(int) { list_const_iterator some = *this; --(*this); return some; };
		reference operator*() const { return m_node->val; };
};

template <typename Value>
	class list_const_reverse_iterator;

template <typename Value>
	class list_reverse_iterator
{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef Value							value_type;
		typedef s_list<value_type>*				node_ptr;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef const value_type&				const_reference;
		typedef list_const_reverse_iterator<value_type>	list_const_reverse_iterator;
		
	private:
		node_ptr	m_node;
		node_ptr	list_end;

	public:
		list_reverse_iterator() : m_node(), list_end() { };

		list_reverse_iterator(node_ptr node, node_ptr end_ptr) : m_node(node), list_end(end_ptr) {};
		operator list_const_reverse_iterator()
		{
			return list_const_reverse_iterator(this->m_node, this->list_end);
		};
		// input iterator requirements
		list_reverse_iterator(list_reverse_iterator const & obj) { this->operator=(obj); } ; // copy constructor
		
		~list_reverse_iterator() {};
		list_reverse_iterator& operator= (list_reverse_iterator const & obj)
		{
			if (&obj != this)
			{
				this->m_node = obj.m_node;
				this->list_end = obj.list_end;
			}
			return *this;
		}; //assignatiom overloading
		bool operator== (list_reverse_iterator const & obj) { return (m_node == obj.m_node); };
		bool operator!= (list_reverse_iterator const & obj) { return (m_node != obj.m_node); };
		pointer operator-> () const { return m_node->val; };
		//forward iterator requirements
		list_reverse_iterator& operator++()
		{
			m_node = m_node->prev;
			return *this;
		};
		list_reverse_iterator operator++(int) {list_reverse_iterator some = *this; ++(*this); return some; };
		//bidirectional iterator requirements
		list_reverse_iterator& operator--()
		{
			m_node = m_node->next;
			return *this;
		};
		list_reverse_iterator operator--(int) { list_reverse_iterator some = *this; --(*this); return some; };
		reference operator*() const { return m_node->prev->val; };
};

template <typename Value>
	class list_const_reverse_iterator
{
	public:
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t						difference_type;
		typedef Value							value_type;
		typedef const s_list<value_type>*		node_ptr;
		typedef value_type*						pointer;
		typedef const value_type&				reference;
		typedef const value_type&				const_reference;
		
	private:
		node_ptr	m_node;
		node_ptr	list_end;

	public:
		list_const_reverse_iterator() : m_node(), list_end() { };

		list_const_reverse_iterator(node_ptr node, node_ptr end_ptr) : m_node(node), list_end(end_ptr) {};
		// input iterator requirements
		list_const_reverse_iterator(list_const_reverse_iterator const & obj) { this->operator=(obj); } ; // copy constructor
		
		~list_const_reverse_iterator() {};
		list_const_reverse_iterator& operator= (list_const_reverse_iterator const & obj)
		{
			if (&obj != this)
			{
				this->m_node = obj.m_node;
				this->list_end = obj.list_end;
			}
			return *this;
		}; //assignatiom overloading
		bool operator== (list_const_reverse_iterator const & obj) { return (m_node == obj.m_node); };
		bool operator!= (list_const_reverse_iterator const & obj) { return (m_node != obj.m_node); };
		pointer operator-> () const { return m_node->val; };
		//forward iterator requirements
		list_const_reverse_iterator& operator++()
		{
			m_node = m_node->prev;
			return *this;
		};
		list_const_reverse_iterator operator++(int) {list_const_reverse_iterator some = *this; ++(*this); return some; };
		//bidirectional iterator requirements
		list_const_reverse_iterator& operator--()
		{
			m_node = m_node->next;
			return *this;
		};
		list_const_reverse_iterator operator--(int) { list_const_reverse_iterator some = *this; --(*this); return some; };
		reference operator*() const { return m_node->prev->val; };
};