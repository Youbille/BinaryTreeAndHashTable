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
	BTNode<value_type>* get_root()
	{
		return root;
	}
	void destruction(BTNode<value_type>* node)
	{
		if (node != nullptr)
		{
			 destruction(node->get_right());
		 destruction(node->get_left());
			delete(node);
			size--;
		}
	}
	void add(value_type item)
	{
		if (root == nullptr)
		{
			root = new BTNode<value_type>(new value_type(item));
		}
		else
		{
			insertion(root, item);
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
			if (node_atm->get_left() == nullptr)
			{
				node_atm->set_left(new BTNode<value_type>(new value_type(item)));
			}
			else
			{
				insertion(node_atm->get_left(), item);
			}
		}
	}
	void remove(value_type item)
	{
		erase(root, item);
		size--;
	}
	void erase(BTNode<value_type>* node, value_type item)
	{
		if (node->get_right()!= nullptr && node->get_right()->get_data() == item && isALeafNode(node->get_right())) //Here two tests if the next node if the wanted value
		{
			delete node->get_right();
			node->set_right(nullptr);
		}
		if (node->get_left()!=nullptr && node->get_left()->get_data() == item && isALeafNode(node->get_left()))
		{
			delete node->get_left();
			node->set_left(nullptr);
		}
		else if (node->get_data() == item)
		{
			destroy(node);
		}
		else if (item > node->get_data() && node->get_right() != nullptr)
		{
			erase(node->get_right(), item);
		}
		else if (item < node->get_data() && node->get_left() != nullptr)
		{
			erase(node->get_left(), item);
		}
	}

	bool isALeafNode(BTNode<value_type>* node)
	{
		return node->get_right() == nullptr && node->get_left() == nullptr;
	}

	void destroy(BTNode<value_type>* node) //maybe return a value-type so we return the item from the destroyed node
	{
		BTNode<value_type>* temp;
		 if (node->get_right() == nullptr && node->get_left() != nullptr)//If there is only a left child
		{
			
			if (isALeafNode(node->get_left()))
			{
				node->set_data(node->get_left()->get_data());
				node->set_left(nullptr);
				delete(node->get_left());
			}
			else 
			{
				node->set_data(node->get_left()->get_data());
				temp = node->get_left();
				if (node->get_left()->get_left() != nullptr)
				{
					node->set_left(temp->get_left()); //I'm not sure if this is the correct way to do it, but it should work. We go and get the grandchild to attach it to the current node
				}
				else
				{
					node->set_left(nullptr);
				}
				if (temp->get_right() != nullptr)
				{
					node->set_right(temp->get_right());
				}
				delete temp;
			}
		}
		 else if (node->get_right() != nullptr)
		 {
			 temp = findMin(node->get_right());
			 node->set_data(temp->get_data()); //We put the minimum that we found into the node that we want to remove
			 if (temp->get_right()!=nullptr)
			 {
				 temp->set_data(temp->get_right()->get_data());
				 delete temp->get_right();
				 temp->set_right(nullptr);
			 }
			 else
			 {
				 node->set_right(temp->get_right());
				 delete temp;
			 }
		 }
	}
	BTNode<value_type>* findMin(BTNode<value_type>* node)
	{
		BTNode<value_type>* minimum = node;
		while(minimum->get_left() != nullptr)
		{
			minimum = minimum->get_left();
		}
		return minimum;
	}
	std::ostream& ToOstream(BTNode<value_type>* node, std::ostream& os)
	{
		if (node==nullptr)
		{
			return os;
		}
		ToOstream(node->get_left(), os);
		os << node->get_data();
		ToOstream(node->get_right(), os);
	}
	int calculateInventory ()
	{
		return computeInventory(root, 0);
	}
	int computeInventory(BTNode<value_type>* node, int inv)
	{
		if (node == nullptr)
		{
			return inv;
		}
		computeInventory(node->get_left(), inv);
		inv += node->get_data().get_quantity(); //This will of course only work with MechParts 
		computeInventory(node->get_right(), inv);
	}
	int calculateParts()
	{
		return computeTypesOfParts(root, 0);
	}
	int computeTypesOfParts(BTNode<value_type>* node, int typesOfParts)
	{
		if (node == nullptr)
		{
			return typesOfParts;
		}
		computeTypesOfParts(node->get_left(), typesOfParts);
		typesOfParts++; //This will of course only be relevant with MechParts
		computeTypesOfParts(node->get_right(), typesOfParts);
	}
private:
	int size;
	BTNode<value_type>* root;
};
template <typename value_type>
std::ostream& operator <<(std::ostream& os ,BSTree<value_type> BStree)
{
	return BStree.ToOstream(BStree.get_root(),os);

}
#endif
