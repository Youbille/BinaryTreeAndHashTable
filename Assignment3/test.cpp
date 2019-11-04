
#include "BTNode.h"
#include <string>
#include <iostream>
#include "BSTree.h"

int main()
{
	BSTree<int> testTree;
	testTree.add(5);
	testTree.add(2);
	testTree.add(20);
	testTree.add(10);
	testTree.add(30);
	testTree.add(22);
	testTree.add(27);
	testTree.remove(20);
	//testTree.add(8);
	//testTree.add(12);
	//testTree.add(52);
	//testTree.add(9);
	return 0;
}
