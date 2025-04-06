#include "Binary Tree.h"

void main()
{
	BinaryTree BT;
	BinaryTree::Node* root3 = new BinaryTree::Node(-21, nullptr, nullptr);
	BinaryTree::Node* root2 = new BinaryTree::Node(43342, root3, nullptr);
	BinaryTree::Node* root = new BinaryTree::Node(23, nullptr, root2);
	BinaryTree::Node* left = new BinaryTree::Node(45, nullptr, root);
	BT.print(left, 0, 25, 0);
}