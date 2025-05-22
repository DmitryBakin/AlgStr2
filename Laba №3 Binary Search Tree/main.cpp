#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree::Node* load = new BinarySearchTree::Node(12, nullptr, nullptr);

	BinarySearchTree BT(load);

	BT.minKey();
	BT.addKey(-90);
	BT.addKey(-1000);
	BT.addKey(-999);
	BT.addKey(-1);
	BT.addKey(95);
	//BT.addKey(15);
	//.addKey(13);


	BT.printTreeHorizontal(0, 15);
	puts("\n\n\n\n\n\n\n");
	std::cout << "\n" <<  BT.nodeHeightIndex(5342);
	//BT.printTreeHorizontal(0, 15);

	//std::cout << BT.findKey(-100) << "\n" << BT.root()->leftChild() << "\n";
	//std::cout << BT.findKey(-99) << "\n" << BT.root()->leftChild()->rightChild() << "\n";
	//std::cout << BT.findKey(0);


	/*
	std::cout << "\n" << BT.maxKey();

	std::vector<int> keys = BT.getVectorKeys();

	puts("");
	for (int i = 0; i < keys.size(); i++)
	{
		std::cout << keys[i] << " ";
	}
	*/
	return 0;
}