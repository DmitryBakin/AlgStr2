#include "Binary Tree.h"

#include <vector>

void main()
{
	
	BinaryTree::Node* root3 = new BinaryTree::Node(2, nullptr, nullptr);
	BinaryTree::Node* root4 = new BinaryTree::Node(4, nullptr, nullptr);
	BinaryTree::Node* root2 = new BinaryTree::Node(1, nullptr, root3);
	BinaryTree::Node* root = new BinaryTree::Node(0, nullptr, root2);
	BinaryTree::Node* right = new BinaryTree::Node(3, nullptr, root4);
	BinaryTree::Node* left = new BinaryTree::Node(20, nullptr, root);
	BinaryTree::Node* now = new BinaryTree::Node(0, nullptr, nullptr);

	BinaryTree BT(left);
	//BinaryTree BT1 = BT;
	//BinaryTree BT1(now);

	std::vector<int> keys;

	//bool min = BT.searchNode(123213);

	//BT.printTreeHorizontal(0, 10);

	//BT.addKey(32);
	//BT.removeKey(45);
	//keys = BT.getVectorKeys();

	BT.printTreeHorizontal(0, 10);

	//BT.bfsPrint(BT.root());
	//BT.removeSubtrees();

	//BT1.printTreeHorizontal(0, 10);

	//for (int i = 0; i < keys.size(); i++)
		//std::cout << keys[i] << " ";

	//std::cout << "\n" << BT.nlrSearch(-21) << "\n";
	//BT.clear();
	/*BT.addKey(1);
	BT.addKey(5);
	BT.addKey(7);
	BT.addKey(8);
	BT.addKey(3);
	BT.addKey(2);
	BT.addKey(4);
	BT.addKey(6); */
	//puts("\n\n\n\n\n");
	//BT.printTreeHorizontal(0, 10);
	//puts("\n\n\n\n\n");
	BT.removeKey(0);
	puts("\n\n\n\n\n");
	BT.printTreeHorizontal(0, 10);
	puts("\n\n\n\n\n");
	//BT.removeKey(123);
	BT.printTreeHorizontal(0, 10);
	puts("\n\n\n\n\n");
	/*BT.removeKey(123);
	BT.printTreeHorizontal(0, 10);
	puts("\n\n\n\n\n");
	BT.removeKey(123);
	BT.printTreeHorizontal(0, 10);
	puts("\n\n\n\n\n");
	BT.removeKey(123);
	BT.printTreeHorizontal(0, 10);
	puts("\n\n\n\n\n");
	BT.removeKey(123);
	//std::cout << BT.heightNode(BT.root(), 1);
	BT.printTreeHorizontal(0, 10); */
}
















































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