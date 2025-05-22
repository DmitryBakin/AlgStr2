#include "Binary Tree.h"

#include <vector>

void main()
{
	
	BinaryTree::Node* root3 = new BinaryTree::Node(2, nullptr, nullptr);
	BinaryTree::Node* root4 = new BinaryTree::Node(4, nullptr, nullptr);
	BinaryTree::Node* root2 = new BinaryTree::Node(1, nullptr, nullptr);
	BinaryTree::Node* root = new BinaryTree::Node(0, nullptr, root2);
	BinaryTree::Node* right = new BinaryTree::Node(3, root3, root4);
	BinaryTree::Node* left = new BinaryTree::Node(20, nullptr, root);
	BinaryTree::Node* now = new BinaryTree::Node(0, left, right);

	BinaryTree BT(root4);
	BT.printTreeHorizontal(0, 15);
	//BinaryTree BT1 = BT;
	//BinaryTree BT1(now);
	//BT.addKey(12);
	BT.addKey(3);
	std::cout << "\n" << BT.nodeHeightIndex(1);
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