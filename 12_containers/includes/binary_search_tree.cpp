
#include <iostream>
#include <string>

template <typename Key>
	struct bst_node
{
	typedef	bst_node*	bst_ptr;
	bst_ptr				left;
	bst_ptr				right;
	bst_ptr				parent;
	Key					key;

	bst_node() : left(NULL), right(NULL), parent(NULL) {};
	bst_node(Key key_val, bst_ptr parent) : left(NULL), right(NULL), parent(parent), key(key_val) {};

	bst_ptr	min(bst_ptr current)
	{
		while (current && current->right != 0)
		{
			current = current->right;
			//std::cout << std::endl;
		}
		//std::cout
		return current;
	}
	bst_ptr	max(bst_ptr current)
	{
		while (current && current->left != 0)
			current = current->left;
		return current;
	}
	bool	is_right_leaf()
	{
		if (this->parent && this->parent->right == this)
			return true;
		return false;
	}
};

template <typename Key>
	struct bst_iterator
{
	public:
		typedef bst_node<Key>* node_ptr;
		//typedef T	value_type;
		typedef Key&	reference;
		typedef Key*	pointer;

		bst_iterator(node_ptr ptr) : m_node(ptr) {};

		Key& operator*() { return m_node->key; };
		bool operator==(bst_iterator & iter) { return m_node == iter.m_node; };
		bool operator!=(bst_iterator & iter) { return !this->operator==(iter); };
		bst_iterator&	operator++()
		{
			if (m_node->left)
				m_node = m_node->min(m_node->left);
			else if (m_node->parent && m_node->parent->key > m_node->key)
				m_node = m_node->parent;
			else if (m_node->parent && m_node->parent->key < m_node->key)
			{
				while (m_node->parent->key < m_node->key)
					m_node = m_node->parent;
				m_node = m_node->parent;
			}
			return *this;
		}
		bst_iterator&	operator--()
		{
			if (m_node->right)
				m_node = m_node->max(m_node->right);
			else if (!m_node->is_right_leaf())
				m_node = m_node->parent;
			else if (m_node->is_right_leaf())
			{
				while (m_node->parent->key > m_node->key)
					m_node = m_node->parent;
				m_node = m_node->parent;
			}
			return *this;
		}
	private:
		node_ptr m_node;
};

template <typename Key>
	class bst
{
	public:
		typedef bst_node<Key> node;
		typedef bst_iterator<Key> iterator;

	private:
		node*	root_ptr;
		node	end_ptr;

	public:
		// ~bst() {};
		bst()
		{
			root_ptr = NULL;
		};

		iterator	begin()
		{
			return iterator(root_ptr ? root_ptr->min(root_ptr) : &end_ptr);
		}
		iterator	end()
		{
			return iterator(&end_ptr);
		}
		void	insert(Key new_key)
		{
			if (!root_ptr)
			{
				root_ptr = new node();
				root_ptr->key = new_key;
				root_ptr->left = &end_ptr;
				end_ptr.parent = root_ptr;
			}
			else
			{
				node* temp = root_ptr;
				node* temp_last = temp;
				while (temp && temp->left != &end_ptr)
				{
					if (new_key > temp->key)
						temp = temp->left;
					else if (new_key < temp->key)
						temp = temp->right;
					else
					{
						// change value
						return ;
					}
					if (temp)
						temp_last = temp;
				}
				node* new_node = new node(new_key, temp_last);
				if (temp_last->left == &end_ptr && new_key > temp_last->key)
				{
					temp_last->left = new_node;
					new_node->left = &end_ptr;
					end_ptr.parent = new_node;
				}
				else
					new_key > temp_last->key ? temp_last->left = new_node : temp_last->right = new_node;
			}
		};
};
#include <map>
int main()
{
	std::map<int,int> lol;
	std::map<int,int>::iterator i_b = lol.begin();
	std::map<int,int>::iterator i_e = lol.end();
	while (i_b != i_e)
	{
		std::cout << i_b->second << std::endl;
		++i_b;
	}
	bst<int> tree;
	tree.insert(4);
	tree.insert(8);
	tree.insert(10);
	tree.insert(1);
	tree.insert(7);
	tree.insert(6);
	tree.insert(12);
	tree.insert(2);
	bst<int>::iterator my_i_b = tree.begin();
	bst<int>::iterator my_i_e = tree.end();
	while (my_i_b != my_i_e)
	{
		std::cout << "val: " << *my_i_b << std::endl;
		++my_i_b;
	}
	my_i_b = tree.begin();
	int i = 10;
	--my_i_e;
	while (my_i_e != my_i_b && i > 0)
	{
		std::cout << "rev val: " << *my_i_e << std::endl;
		--my_i_e;
		--i;
	}
	std::cout << *my_i_e << std::endl;
}
