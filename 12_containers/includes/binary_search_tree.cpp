
#include <iostream>
#include <string>

#include "is_integer.hpp"

template <typename ValType>
	struct bst_node
{
	typedef	bst_node*	bst_ptr;
	bst_ptr				left;
	bst_ptr				right;
	bst_ptr				parent;
	ValType				value;

	bst_node() : left(NULL), right(NULL), parent(NULL) {};
	bst_node(ValType value, bst_ptr parent) : left(NULL), right(NULL), parent(parent), value(value) {};

	bst_ptr	min(bst_ptr current)
	{
		while (current && current->right != 0)
			current = current->right;
		return current;
	}
	bst_ptr	max(bst_ptr current)
	{
		while (current && current->left != 0)
			current = current->left;
		return current;
	}
	bool	is_right_child()
	{
		if (this->parent && this->parent->right == this)
			return true;
		return false;
	}
};

template <typename Value>
	struct bst_iterator
{
	public:
		typedef bst_node<Value>* node_ptr;
		typedef Value&	reference;
		typedef Value*	pointer;
	private:
		node_ptr	m_node;
		bst_iterator() {};

	public:
		bst_iterator(node_ptr ptr) : m_node(ptr) {};
		~bst_iterator() {};

		node_ptr get_node() { return this->m_node; };

		Value& operator*() { return m_node->value; };
		Value* operator->() { return &m_node->value; };
		bool operator==(bst_iterator & iter) { return this->m_node == iter.m_node; };
		bool operator!=(bst_iterator & iter) { return !this->operator==(iter); };
		bst_iterator&	operator++()
		{
			if (m_node->left)
				this->m_node = m_node->min(m_node->left);
			else
			{
				while (m_node->parent && m_node == m_node->parent->left)
					m_node = m_node->parent;
				m_node = m_node->parent;
			}
			return *this;
		}
		bst_iterator&	operator++(int)
		{
			bst_iterator temp = *this;
			this->operator++();
			return temp;
		}
		bst_iterator&	operator--()
		{
			if (m_node->right)
				m_node = m_node->max(m_node->right);
			else
			{
				while (m_node->parent && m_node == m_node->parent->right)
					m_node = m_node->parent;
				m_node = m_node->parent;
			}
			return *this;
		}
		bst_iterator&	operator--(int)
		{
			bst_iterator temp = *this;
			this->operator--();
			return temp;
		}
};

template <class Key, class T, class Compare = std::less<Key> >
	class bst
{
	public:
		typedef Key									key_type;
		typedef T									mapped_type;
		typedef std::pair<key_type, mapped_type>	value_type;
		typedef Compare								key_compare;
		typedef value_type&							reference;
		typedef value_type*							pointer;
		typedef bst_node<value_type>				node;
		typedef bst_iterator<value_type>			iterator;
		typedef size_t								size_type;

	private:
		node*	root_ptr;
		node	end_ptr;
		size_type	_size;
		Compare	compare;

	public:
		~bst() { this->clear(); };
		bst(const key_compare &comp = key_compare()) : compare(comp)
		//bst()
		{
			root_ptr = NULL;
			_size = 0;
		};

		iterator	begin()
		{
			return iterator(root_ptr ? root_ptr->min(root_ptr) : &end_ptr);
		}
		iterator	end()
		{
			return iterator(&end_ptr);
		}
		iterator	find(key_type find_key)
		{
			iterator	i_b = this->begin();
			iterator	i_e = this->end();
			while (i_b != i_e)
			{
				if ((*i_b).first == find_key)
					return i_b;
				++i_b;
			}
			return i_e;
		}
		mapped_type& operator[] (const key_type& k)
		{
			iterator i_by_key = find(k);
			iterator i_e = end();
			if (i_by_key == i_e)
			{
				std::pair<const key_type, mapped_type> new_val(k, 0);
				insert(new_val);
			}
			return this->find(k)->second;
		};
		size_type	get_size() const
		{
			return _size;
		}
		void	clear()
		{
			iterator	i_b = this->begin();
			iterator	i_e = this->end();
			while (i_b != i_e)
			{
				remove((*i_b).first);
				i_b = this->begin();
			}
			root_ptr = NULL;
		}
		void	remove(key_type const & rem_key)
		{
			iterator	to_rem = this->find(rem_key);
			iterator	i_e = this->end();
			if (to_rem != i_e)
			{
				node*	rem_node = to_rem.get_node();
				if (rem_node->right && rem_node->left)
				{
					node* temp = rem_node->min(rem_node->left);
					temp->right = rem_node->right;
					rem_node->right->parent = temp;
					rem_node->right = NULL;
				}
				node*	temp_ass = (rem_node->right ? rem_node->right : rem_node->left);
				if (rem_node->parent)
				{
					if (rem_node->is_right_child())
						rem_node->parent->right = temp_ass;
					else
						rem_node->parent->left = temp_ass;
					if (temp_ass)
						temp_ass->parent = rem_node->parent;
				}
				else
				{
					root_ptr = temp_ass;
					if (temp_ass)
						temp_ass->parent = NULL;
				}
				_size -= 1;
				delete rem_node;				
			}
		}
		void	insert(value_type new_value)
		{
			if (!root_ptr)
			{
				root_ptr = new node();
				root_ptr->value = new_value;
				root_ptr->left = &end_ptr;
				end_ptr.parent = root_ptr;
			}
			else
			{
				node* temp = root_ptr;
				node* temp_last = temp;

				while (temp && temp->left != &end_ptr)
				{
					if (new_value.first > temp->value.first)
						temp = temp->left;
					else if (new_value.first < temp->value.first)
						temp = temp->right;
					else
					{
						// change value
						temp->value.second = new_value.second;
						return ;
					}
					if (temp)
						temp_last = temp;
				}
				node* new_node = new node(new_value, temp_last);
				if (temp_last->left == &end_ptr && new_value.first > temp_last->value.first)
				{
					temp_last->left = new_node;
					new_node->left = &end_ptr;
					end_ptr.parent = new_node;
				}
				else
					new_value.first > temp_last->value.first ? temp_last->left = new_node : temp_last->right = new_node;
			}
			_size += 1;
		};
};


// #include <map>
// int main()
// {
// 	std::map<int,int> lol;
// 	std::map<int,int>::iterator i_b = lol.begin();
// 	std::map<int,int>::iterator i_e = lol.end();
// 	while (i_b != i_e)
// 	{
// 		std::cout << i_b->second << std::endl;
// 		++i_b;
// 	}
// 	bst<int, int> tree;
// 	//tree.insert(std::pair<int,int>);
// 	tree.insert(std::pair<int, int>(4,2));
// 	tree.insert(std::pair<int, int>(8,2));
// 	tree.insert(std::pair<int, int>(10,2));
// 	tree.insert(std::pair<int, int>(1,2));
// 	tree.insert(std::pair<int, int>(7,2));
// 	tree.insert(std::pair<int, int>(6,2));
// 	tree.insert(std::pair<int, int>(12,2));
// 	tree.insert(std::pair<int, int>(2,1222));
// 	tree[169] = 200;
	
// 	bst<int, int>::iterator my_i_b = tree.begin();
// 	bst<int, int>::iterator my_i_e = tree.end();
// 	while (my_i_b != my_i_e)
// 	{
// 		std::cout << "key: " << my_i_b->first << " val: " << my_i_b->second << std::endl;
// 		++my_i_b;
// 	}
// 	tree.insert(std::pair<int, int>(1,22));
// 	my_i_b = tree.begin();
// 	std::cout << "key: " << my_i_b->first << " val: " << my_i_b->second << std::endl;
// 	//int i = 10;
// 	--my_i_e;
// 	while (my_i_e != my_i_b)
// 	{
// 		std::cout << "rev key: " << my_i_e->first << std::endl;
// 		--my_i_e;
// 	}
// 	std::cout << "rev key: " << my_i_e->first << std::endl;
	
// 	tree.remove(10);
//  my_i_b = tree.begin();
//  my_i_e = tree.end();

// 	//delete my_i_b.get_node();
// 	while (my_i_b != my_i_e)
// 	{
// 		std::cout << "key: " << my_i_b->first << std::endl;
// 		++my_i_b;
// 	}
// 	bst<float, float> tree_float;

// 	std::cout << "before val: " << tree[2] << std::endl;
// 	tree[2] = 111;
// 	std::cout << "before val: " << tree[2] << std::endl;
// 	tree[169] = 200;
// }
