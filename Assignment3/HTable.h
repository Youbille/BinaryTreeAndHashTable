//Hash table template class
//Created by Gauthier FALISE_C3338389

#ifndef HTABLE_GF
#define HTABLE_GF
#include <cstddef>

template <typename value_type>
class HTable
{
public:
	//Constructor
	HTable()
	{
		size = sizeof(array)/sizeof(value_type);
	}
	//Destructor
	~HTable()
	{
	}
	//Getters 
	value_type* get_array() //In C++, you return an array by using a pointer to its first object
	{
		return array;
	}
	int get_size()
	{
		return size;
	}
	//Postcon : Gives the hashCode for a MechPart object
	int hashFUnction(const value_type& value)
	{
		int position = 0;
		string temp = value.get_code();
		for (int i = 0; i < (int)temp.length(); i++)
		{
			position += (i + 1) * (i + 1) * temp.at(i);
		}
		return position % size;
	}
	//Precon : the hashtable has been initialised
	//postcon : the item has benn added at the position corresponding to its hashcode
	void add(value_type item)
	{
		int hashCode = hashFUnction((item));
		array[hashCode] = item;
	}
	
	//precon : The hashtable exists
	//postcon :THe position at the hashcode is now empty (0 and "") and the item is returned
	value_type remove(value_type item)
	{
		int hashCode = hashFUnction((item));
		value_type returnedItem = array[hashCode];
		array[hashCode].set_code("");
		array[hashCode].set_quantity(0); //This will only work with the MechPart, so it's not re
		return returnedItem;
	}

	//precon : the hashtable has been initialised with some of MechParts
	//postcon : the total number of MechParts is returned
	int calculateInventory()
	{
		int inventory = 0;
		for (int i = 0; i < size; i++)//We got through the array, and when we find a non empty object, when add its quantity to the total
		{
			if (!array[i].get_code().empty())
			{
				inventory += array[i].get_quantity();
			}
		}
		return inventory;
	}
	//precon : the hashtable has been initialised with some of MechParts
	//postcon : the number of different mechParts is returned
	int calculateParts()
	{
		int parts = 0;
		for (int i = 0; i < size; i++)
		{
			if (!array[i].get_code().empty())
			{
				parts++;
			}
		}
		return parts;
	}
private:
	value_type array[5000];
	int size;
};
template <typename value_type>
std::ostream& operator <<(std::ostream& os, HTable<value_type>& table)
{
	for (int i = 0; i < table.get_size(); i++)//We go through the array and add an item when it's not empty
	{
		if (!table.get_array()[i].get_code().empty())
		{
			os << table.get_array()[i];
		}
	}
	return os;
}
#endif

