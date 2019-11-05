
#include "BTNode.h"
#include <string>
#include <iostream>
#include "BSTree.h"
#include "MechPart.h"

int main()
{
	BSTree<MechPart> testTree;
	MechPart testPart;
	testPart.set_code("code1");
	testPart.set_quantity(3);
	testTree.add(testPart);
	testPart.set_code("code2");
	testPart.set_quantity(9);
	testTree.add(testPart);
	cout << "number of parts" << testTree.calculateParts() << "total number" << testTree.calculateInventory();
		//testTree.add(20);
		//testTree.add(10);
		//testTree.add(30);
		//testTree.add(22);
		//testTree.add(27);
		//std::cout << testTree; //so apparently the function gets called a second time after the return ?

		//testTree.remove(20);
		return 0;
	
}
