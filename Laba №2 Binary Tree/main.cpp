#include "Binary Tree.h"

#include <vector>

void main()
{
	
	BinaryTree::Node* root3 = new BinaryTree::Node(-21, nullptr, nullptr);
	BinaryTree::Node* root2 = new BinaryTree::Node(43342, nullptr, root3);
	BinaryTree::Node* root = new BinaryTree::Node(23, nullptr, root2);
	BinaryTree::Node* right = new BinaryTree::Node(1, nullptr, nullptr);
	BinaryTree::Node* left = new BinaryTree::Node(45, right, root);

	BinaryTree BT(left);

	//std::vector<int> keys, ki;

	bool min = BT.searchNode(123213);

	BT.printTree(0, 100);
	//BT.clear(BT.root());
	// ki = BT.getVectorKeys(BT.root(), keys);
	BT.printTree(0, 100);
	/*BT.printTree(0, 25);
	std::cout << BT.isEmpty() << std::endl;
	BT.clear(BT.root());
	
	BT.printTree(25, 80);
	std::cout << BT.isEmpty();
	
	std::vector<int> key;

	BT.addNode(root2, 451);
	BT.printTree(25, 80);
	
	BT.lrnPrint(left);

	puts("");

	key = BT.getVectorKeys(BT.root(), key);

	
	for (int i = 0; i < ki.size(); i++)
	{
		std::cout << ki[i] << " ";
	}*/

	std::cout << min << " ";
}