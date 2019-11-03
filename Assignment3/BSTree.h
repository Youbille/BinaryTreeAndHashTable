//template class for the BSTree
//created by Gauthier FALISE - C3338389
#ifndef BSTREE_GF
#define BSTREE_GF

#include "BTNode.h"

template <typename value_type>
class BSTree
{
public:
	BSTree()
	{
		root = nullptr;
		size = 0;
	}
	~BSTree()
	{
		destruction(root);
	}
	void destruction(BTNode<value_type>* node)
	{
		if(node != nullptr)
		{
			destruction(node->get_right());
			destruction(node->get_left());
			delete(node);
		}
	}
	void add (value_type item)
	{
		if (root == nullptr)
		{
			root = new BTNode<value_type>(new value_type(item));
		}
		else
		{
			insertion(root,item);
		}
		size++;
	}
	void insertion(BTNode<value_type>* node_atm, value_type item)
	{
		if (item == node_atm->get_data())
		{
			node_atm->set_data(item); //This is the way to handle duplicates, we replace if the value already exists
		}
		else if (item > node_atm->get_data())//We chack if the right child is empty or not
		{
			if (node_atm->get_right() == nullptr)
			{
				node_atm->set_right(new BTNode<value_type>(new value_type(item)));
			}
			else
			{
				insertion(node_atm->get_right(), item);
			}
		}
		else //Then we do the same for the left child
		{
			if(node_atm->get_left() == nullptr)
			{
				node_atm->set_left(new BTNode<value_type>(new value_type(item)));
			}
			else
			{
				insertion(node_atm->get_left(), item);
			}
		}
	}
private:
	int size;
	BTNode<value_type>* root;
};
#endif
