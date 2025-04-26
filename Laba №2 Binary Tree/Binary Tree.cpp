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

void BinaryTree::clear()
{
	clear(m_root);
	m_root = nullptr;
}

void BinaryTree::removeSubtrees()
{
	removeSubtrees(m_root);
	m_root->setLeftChild(nullptr);
	m_root->setRightChild(nullptr);
}

bool BinaryTree::isEmpty() const
{
	return (m_root == nullptr);
}

int BinaryTree::height(Node* root) const
{
	if (root == nullptr)
		return 0;
	int heightTree = 1;

	int left = height(root->leftChild());
	int right = height(root->rightChild());

	return 1 + std::max(left, right);
}

int BinaryTree::heightNode(Node* root, Node* node) const
{
	return 0;
}

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

BinaryTree::Node* BinaryTree::addKey(int key)
{
	return addKey(m_root, key);
}

BinaryTree::Node* BinaryTree::nlrSearch(int key) const
{
	return nlrSearch(m_root, key);
}

bool BinaryTree::removeKey(int key)
{
	return removeKey(m_root, key);
}

bool BinaryTree::contains(int key) const
{
	return contains(m_root, key);
}

std::vector<int> BinaryTree::getVectorKeys() const
{
	std::vector<int> keys;
	getVectorKeys(m_root, keys);
	return keys;
}

void BinaryTree::bfsPrint(Node* root) const
{
	if (root == nullptr)
		return;
	std::list<Node*> unprocessedNodes(1, root);
	while (!unprocessedNodes.empty()) {
		Node* node = unprocessedNodes.front();
		std::cout << node->key() << ' ';
		if (node->leftChild()) {
			unprocessedNodes.push_back(node->leftChild());
		}
		if (node->rightChild()) {
			unprocessedNodes.push_back(node->rightChild());
		}
		unprocessedNodes.pop_front();
		
	}
}

void BinaryTree::printTreeHorizontal(int marginLeft, int levelSpacing) const
{
	printHorizontal(m_root, marginLeft, levelSpacing);
}

bool BinaryTree::contains(Node* root, int key) const
{
	std::vector<int> keys;
	getVectorKeys(root, keys);
	for (int i = 0; i < keys.size(); i++)
	{
		if (keys[i] == key)
			return true;
	}
	return false;
}

bool BinaryTree::removeKey(Node* root, int key)
{
	Node* node = nlrSearch(key);
	Node* nodeParent, *replacementNode;

	if (node == nullptr)
		return false;

	if (node->leftChild() == nullptr && node->rightChild() == nullptr)
	{
		replacementNode = nullptr;
		nodeParent = searchParent(root, node);
		if(nodeParent->leftChild() == node)
			nodeParent->setLeftChild(nullptr);
		else
			nodeParent->setRightChild(nullptr);

		delete node;
	}
	else if (node->leftChild() != nullptr && node->rightChild() == nullptr)
	{
		replacementNode = node->leftChild();
		nodeParent = searchParent(root, node);
		nodeParent->setLeftChild(nullptr);
		delete node;
		nodeParent->setLeftChild(replacementNode);
	}
	else if (node->leftChild() == nullptr && node->rightChild() != nullptr)
	{
		replacementNode = node->rightChild();
		nodeParent = searchParent(root, node);
		nodeParent->setRightChild(nullptr);
		delete node;
		nodeParent->setRightChild(replacementNode);
	}
	else if (node == root)
	{
		replacementNode = node;

		while (replacementNode->rightChild() != nullptr)
		{
			replacementNode = replacementNode->rightChild();
		}

		replacementNode->setLeftChild(node->leftChild());
		replacementNode->setRightChild(node->rightChild());

		searchParent(root, replacementNode)->setRightChild(nullptr);

		m_root = replacementNode;

		delete node;
	}

	else
	{
		replacementNode = node;

		while (replacementNode->rightChild() != nullptr)
		{
			replacementNode = replacementNode->rightChild();
		}

		nodeParent = searchParent(root, node);
		
		searchParent(root, replacementNode)->setRightChild(nullptr);

		nodeParent->setRightChild(replacementNode);

		replacementNode->setLeftChild(node->leftChild());
		replacementNode->setRightChild(node->rightChild());
		delete node;
		nodeParent->setRightChild(replacementNode);

	}
	return true;
}

BinaryTree::Node* BinaryTree::searchParent(Node* root, Node* node) const
{
	if (root == nullptr)
		return nullptr;
	if ((root != nullptr) && (root->rightChild() == node || root->leftChild() == node))
		return root;
	Node* subTreeSearchParentResult = searchParent(root->leftChild(), node);
	if (!subTreeSearchParentResult)
	{
		subTreeSearchParentResult = searchParent(root->rightChild(), node);
	}
	return subTreeSearchParentResult;
}

BinaryTree::Node* BinaryTree::addKey(Node* root, int key)
{
	if (!root) {
		root = new Node(key);
	}
	else if (rand() % 2) {
		root->setLeftChild(addKey(root->leftChild(), key));
	}
	else {
		root->setRightChild(addKey(root->rightChild(), key));
	}
	return root;
}

BinaryTree::Node* BinaryTree::nlrSearch(Node* root, int key) const
{
	if (!root || root->key() == key) {
		return root;
	}
	Node* subTreeSearchResult = nlrSearch(root->leftChild(), key);
	if (!subTreeSearchResult) {
		subTreeSearchResult = nlrSearch(root->rightChild(), key);
	}
	return subTreeSearchResult;
}

void BinaryTree::clear(Node* node)
{
	if (node == nullptr)
		return;

	clear(node->leftChild());
	clear(node->rightChild());

	delete node;
	node = nullptr;
}

void BinaryTree::removeSubtrees(Node* node)
{
	if (node == nullptr)
		return;

	removeSubtrees(node->leftChild());
	removeSubtrees(node->rightChild());

	node = nullptr;
	delete node;
}

void BinaryTree::printHorizontal(Node* root, int marginLeft, int levelSpacing) const
{
	if (root == nullptr)
	{
		return;
	}
	printHorizontal(root->rightChild(), marginLeft + levelSpacing, levelSpacing);
	std::cout << std::string(marginLeft,
		' ') << root->key() << std::endl;
	printHorizontal(root->leftChild(), marginLeft + levelSpacing, levelSpacing);
}


std::vector<int> BinaryTree::getVectorKeys(Node* root, std::vector<int>& keys) const
{

	if (root->leftChild())
		getVectorKeys(root->leftChild(), keys);

	if (root->rightChild())
		getVectorKeys(root->rightChild(), keys);

	keys.push_back(root->key());

	std::sort(keys.begin(), keys.end());

	return keys;
}


