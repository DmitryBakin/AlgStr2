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

BinaryTree::BinaryTree(Node* root)
{
	m_root = root;
}

BinaryTree::~BinaryTree()
{
	clear(m_root);
}

BinaryTree::Node* BinaryTree::root() const
{
	return m_root;
}

void BinaryTree::clear(Node* removeRoot)
{
	if (isEmpty())
	{
		return;
	}

	if (removeRoot->leftChild())
		clear(removeRoot->leftChild());

	if (removeRoot->rightChild())
		clear(removeRoot->rightChild());

	removeRoot->setLeftChild(nullptr);
	removeRoot->setRightChild(nullptr);

	delete removeRoot;

	m_root = nullptr;
}

void BinaryTree::removeSubtrees(Node* root)
{
	if (isEmpty())
	{
		return;
	}

	if (root->leftChild())
		removeSubtrees(root->leftChild());

	if (root->rightChild())
		removeSubtrees(root->rightChild());

	root->setLeftChild(nullptr);
	root->setRightChild(nullptr);

	root = nullptr;

	delete root;
}

bool BinaryTree::isEmpty() const
{
	return (m_root == nullptr);
}

/*int BinaryTree::height(Node* root, int height) const
{
	if (isEmpty())
		return 0;
	std::vector<int> heights;

}*/

int BinaryTree::countOfRoots() const
{
	std::vector<int> key;
	return getVectorKeys(m_root, key).size();
}

int BinaryTree::maxKey() const
{
	std::vector<int> key;
	getVectorKeys(m_root, key);

	if (key.size() != 0)
	{
		int max = key[0];
		for (int i = 1; i < key.size(); i++)
		{
			if (max < key[i])
				max = key[i];
		}
		return max;
	}

	return 0;
}

int BinaryTree::minKey() const
{
	std::vector<int> key;
	getVectorKeys(m_root, key);

	if (key.size() != 0)
	{
		int min = key[0];
		for (int i = 1; i < key.size(); i++)
		{
			if (min > key[i])
				min = key[i];
		}
		return min;
	}

	return 0;
}

BinaryTree::Node* BinaryTree::addNode(Node* root, int key)
{
	if (!root) {
		root = new Node(key);
	}
	else if (rand() % 2) {
		root->setLeftChild(addNode(root->leftChild(), key));
	}
	else {
		root->setRightChild(addNode(root->rightChild(), key));
	}
	return root;
}

bool BinaryTree::searchNode(int key)
{
	std::vector<int> keys;
	getVectorKeys(m_root, keys);
	for (int i = 0; i < keys.size(); i++)
	{
		if(keys[i] == key)
			return true;
	}
	return false;
}

void BinaryTree::lrnPrint(Node* root) const
{
	if (root == nullptr) 
	{
		return;
	}
	lrnPrint(root->leftChild());
	lrnPrint(root->rightChild());
	std::cout << root->key() << ' ';
}

std::vector<int> BinaryTree::getVectorKeys(Node* root, std::vector<int> &keys) const
{
	if(root->leftChild())
		getVectorKeys(root->leftChild(), keys);

	if (root->rightChild())
		getVectorKeys(root->rightChild(), keys);

	keys.push_back(root->key());


	return keys;
}

void BinaryTree::printTree(int leftBorderPos, int rightBorderPos) const
{
	m_print(m_root, leftBorderPos, rightBorderPos, 0);
}

void BinaryTree::printTreeHorizontal(int marginLeft, int levelSpacing) const
{
	m_printHorizontal(m_root, marginLeft, levelSpacing);
}

void BinaryTree::m_print(Node* root, int leftBorderPos, int rightBorderPos, int yPos) const
{
	if (root == nullptr) {
		return;
	}
	int xPos = (leftBorderPos + rightBorderPos) / 2;
	std::cout << std::string(xPos, ' ') << root->key() << std::endl;
	m_print(root->leftChild(), leftBorderPos, xPos, yPos + 15);
	m_print(root->rightChild(), xPos, rightBorderPos, yPos );
}

void BinaryTree::m_printHorizontal(Node* root, int marginLeft, int levelSpacing) const
{
	if (root == nullptr) {
		return;
	}
	m_printHorizontal(root->rightChild(), marginLeft + levelSpacing, levelSpacing);
	std::cout << std::string(marginLeft,
		' ') << root->key() << std::endl;
	m_printHorizontal(root->leftChild(), marginLeft + levelSpacing, levelSpacing);
}


