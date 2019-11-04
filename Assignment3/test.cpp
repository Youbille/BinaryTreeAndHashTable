
#include "BTNode.h"
#include <string>
#include <iostream>
#include "BSTree.h"

int main()
{
	BSTree<int> testTree;
	testTree.add(5);
	testTree.add(1);
	testTree.remove(1);
	//testTree.add(8);
	//testTree.add(12);
	//testTree.add(52);
	//testTree.add(9);
	return 0;
}
