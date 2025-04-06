#include "Binary Tree.h"

BinaryTree::Node::Node()
{}

BinaryTree::Node::Node(int key, Node* leftChild, Node* rightChild)
	:m_key(key)
	,m_leftChild(leftChild)
	,m_rightChild(rightChild)
{}

int BinaryTree::Node::key() const
{
	return m_key;
}

void BinaryTree::Node::setKey(const int key)
{
	m_key = key;
}

BinaryTree::Node* BinaryTree::Node::leftChild() const
{
	return m_leftChild;
}

BinaryTree::Node* BinaryTree::Node::rightChild() const
{
	return m_rightChild;
}

void BinaryTree::Node::setLeftChild(Node* leftChild)
{
	m_leftChild = leftChild;
}

void BinaryTree::Node::setRightChild(Node* rightChild)
{
	m_rightChild = rightChild;
}

BinaryTree::~BinaryTree()
{
	delete[] m_root;
}

void BinaryTree::print(Node* root, int leftBorderPos, int rightBorderPos, int yPos) const
{
	if (root == nullptr) {
		return;
	}
	int xPos = (leftBorderPos + rightBorderPos) / 2;
	std::cout << std::string(xPos, ' ') << root->key() << std::endl;
	print(root->leftChild(), leftBorderPos, xPos, yPos + 15);
	print(root->rightChild(), xPos, rightBorderPos, yPos + 15);
}


void BinaryTree::printHorizontal(Node* root, int marginLeft, int levelSpacing) const
{
	if (root == nullptr) {
		return;
	}
	printHorizontal(root->rightChild(), marginLeft + levelSpacing, levelSpacing);
	std::cout << std::string(marginLeft,
		' ') << root->key() << std::endl;
	printHorizontal(root->leftChild(), marginLeft + levelSpacing, levelSpacing);
}


