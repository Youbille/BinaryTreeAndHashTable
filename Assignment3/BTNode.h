//BTNode class used for the binary tree
//Created by Gauthier FALISE - C3338389
#ifndef BTNODE_GF
#define BTNODE_GF
template <typename value_type>
class BTNode
{
public:
	//Constructor and Destructor
	BTNode(value_type* value)
	{
		data = value;
		right = nullptr;
		left = nullptr;
	}
	~BTNode()
	{
		if (data != nullptr)
		{
			delete(data);
		}
		right = nullptr;
		left = nullptr;
	}

	//Getters :
	BTNode* get_right()
	{
		return right;
	}
	BTNode* get_left()
	{
		return left;
	}

	value_type get_data()
	{
		return *data;
	}
	//setters :
	void set_right(BTNode* new_right)
	{
		right = new_right;
	}
	void set_left(BTNode* new_left)
	{
		left = new_left;
	}
	void set_data(value_type new_data)
	{
		data = new value_type(new_data);
	}
private:
	value_type* data;
	BTNode* right;
	BTNode* left;
};
#endif
