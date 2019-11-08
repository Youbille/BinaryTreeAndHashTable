
#include "BTNode.h"
#include <string>
#include <iostream>
#include "BSTree.h"
#include "MechPart.h"
#include "HTable.h"

int main()
{
	HTable<MechPart> testTable;
	BSTree<MechPart> testTree;
	MechPart testPart;
	testPart.set_code("VKTN-PE4M-74QL-JFQR");
	testPart.set_quantity(3);
	testTable.add(testPart);
	cout << testTable;
	testTree.add(testPart);
	testPart.set_code("code2");
	testTable.add(testPart);
	cout << testTable;
	testTable.remove(testPart);
	cout << testTable;

	//testPart.set_quantity(9);
	//testTree.add(testPart);
	//testPart.set_code("code3");
	//testPart.set_quantity(7);
	//testTree.add(testPart);
	//cout << "number of parts" << testTree.calculateParts() << "total number" << testTree.calculateInventory();
	//cout << testTree;
	//testTree.remove(testPart);
	//cout << "number of parts" << testTree.calculateParts() << "total number" << testTree.calculateInventory();
	//cout << testTree;
		
		return 0;
	
}
