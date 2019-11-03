
#include "BTNode.h"
#include <string>
#include <iostream>

int main()
{
	BTNode<int>* test = new BTNode<int>(0);
	test->set_data(5);
	std::cout << *test->get_data();
	delete test;
	return 0;
}
