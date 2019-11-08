//Hash table template class
//Created by Gauthier FALISE_C3338389

#ifndef HTABLE_GF
#define HTABLE_GF
#include <cstddef>

template <typename value_type>
class HTable
{
public:
	HTable()
	{
		size = sizeof(array)/sizeof(value_type);
	}
	~HTable()
	{
	}
	value_type* get_array()
	{
		return array;
	}
	int get_size()
	{
		return size;
	}
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
	void add(value_type item)
	{
		int hashCode = hashFUnction((item));
		array[hashCode] = item;
	}
	value_type remove(value_type item)
	{
		int hashCode = hashFUnction((item));
		value_type returnedItem = array[hashCode];
		array[hashCode].set_code("");
		array[hashCode].set_quantity(0); //This will only work with the MechPart, so it's not re
		return returnedItem;
	}

private:
	value_type array[5000];
	int size;
};
template <typename value_type>
std::ostream& operator <<(std::ostream& os, HTable<value_type>& table)
{
	for (int i = 0; i < table.get_size(); i++)
	{
		if (!table.get_array()[i].get_code().empty() /*&& table.get_array()[i].get_quantity() != 0*/)
		{
			os << table.get_array()[i];
		}
		
	}
	return os;
}
#endif

