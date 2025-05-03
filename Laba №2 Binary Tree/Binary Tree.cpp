#include "Binary Tree.h"

BinaryTree::Node::Node()
{}

BinaryTree::Node::Node(int key, Node* leftChild, Node* rightChild)
	:m_key(key)
	, m_leftChild(leftChild)
	, m_rightChild(rightChild)
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
	:m_root(root)
{}

BinaryTree::BinaryTree(const BinaryTree& other)
{
	m_root = copyTree(other.root());
}

BinaryTree::BinaryTree(BinaryTree&& other)
{
	m_root = other.root();
	other.setRoot(nullptr);
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

int BinaryTree::height() const
{
	return height(m_root);
}

int BinaryTree::heightNode(int key) const
{
	return heightNode(m_root, key, 1);
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
		return key[key.size() - 1];
	return 0;
}

int BinaryTree::minKey() const
{
	std::vector<int> key;
	getVectorKeys(m_root, key);

	if (key.size() != 0)
		return key[0];
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

void BinaryTree::levelPrint() const
{
	levelPrint(m_root);
}

void BinaryTree::printTreeHorizontal(int marginLeft, int levelSpacing) const
{
	printHorizontal(m_root, marginLeft, levelSpacing);
}

bool BinaryTree::treeBalance() const
{
	return treeBalance(m_root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other)
{
	clear();

	m_root = copyTree(other.root());
	return *this;
}

BinaryTree& BinaryTree::operator=(BinaryTree&& other)
{
	clear();

	m_root = other.root();
	other.setRoot(nullptr);

	return *this;
}

void BinaryTree::setRoot(Node* root)
{
	m_root = root;
}

BinaryTree::Node* BinaryTree::copyTree(Node* root)
{
	if (root == nullptr)
		return nullptr;

	Node* newNode = new Node(0, nullptr, nullptr);
	newNode->setKey(root->key());

	newNode->setLeftChild(copyTree(root->leftChild()));
	newNode->setRightChild(copyTree(root->rightChild()));

	return newNode;
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
	clear(node->leftChild());
	clear(node->rightChild());
}

int BinaryTree::height(Node* root) const
{
	if (root == nullptr)
		return 0;

	int left = height(root->leftChild());
	int right = height(root->rightChild());

	return 1 + std::max(left, right);
}

int BinaryTree::heightNode(Node* root, int key, int level) const
{
	if (root == nullptr) 
		return -1;

	if (root->key() == key)
		return level;

	int left = heightNode(root->leftChild(), key, level + 1);
	if (left != -1)
		return left;

	int right = heightNode(root->rightChild(), key, level + 1);
	if (right != -1)
		return right;
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

bool BinaryTree::removeKey(Node* root, int key)
{
    Node* node = nlrSearch(key);
    Node* nodeParent = searchParent(root, node);
    Node* replacementNode;

    if (node == nullptr)
        return false;

    if (node->leftChild() == nullptr && node->rightChild() == nullptr)
    {
        replacementNode = nullptr;

        if (nodeParent != nullptr)
        {
            if (nodeParent->leftChild() == node)
                nodeParent->setLeftChild(nullptr);
            else
                nodeParent->setRightChild(nullptr);
            delete node;
            node = nullptr;
        }
        else
        {
            delete node;
            m_root = nullptr;
        }
        return true;
    }
    else if (node->leftChild() != nullptr && node->rightChild() == nullptr)
    {
        Node* replacementNodeParent = node;
        replacementNode = node;
        if (nodeParent != nullptr)
        {

            if (nodeParent->leftChild() == node)
            {
                nodeParent->setLeftChild(node->leftChild());
                delete node;
            }
            else
            {
                nodeParent->setRightChild(node->leftChild());
                delete node;
            }
        }
        else
        {
            m_root = node->leftChild();
            delete node;
        }
        return true;
    }
    else if (node->leftChild() == nullptr && node->rightChild() != nullptr)
    {
        Node* replacementNodeParent = node;
        replacementNode = node;

		if (nodeParent != nullptr)
		{

			if (nodeParent->leftChild() == node)
			{
				nodeParent->setLeftChild(node->rightChild());
				delete node;
			}
			else
			{
				nodeParent->setRightChild(node->rightChild());
				delete node;
			}

		}
        else
        {
			m_root = node->rightChild();
			delete node;

        }
        return true;
    }
    else if (node == root)
    {
        Node* replacementNodeParent = node;
        replacementNode = node;

        while (replacementNode->rightChild() != nullptr)
        {
            replacementNodeParent = replacementNode;
            replacementNode = replacementNode->rightChild();
        }

        if (node == replacementNodeParent)
        {
            m_root = replacementNode;
            m_root->setRightChild(replacementNode->leftChild());
            m_root->setLeftChild(node->leftChild());
            delete node;
        }
        else
        {
            replacementNodeParent->setRightChild(replacementNode->leftChild());
            replacementNode->setLeftChild(node->leftChild());
            replacementNode->setRightChild(node->rightChild());

            m_root = replacementNode;

            delete node;
            
        }
        return true;
    }
    else if (node->leftChild() != nullptr && node->rightChild() != nullptr)
    {
        Node* replacementNodeParent = node;
        replacementNode = node;

        while (replacementNode->rightChild() != nullptr)
        {
            replacementNodeParent = replacementNode;
            replacementNode = replacementNode->rightChild();
        }

        if (node == replacementNodeParent)
        {
            replacementNode->setRightChild(replacementNode->leftChild());
            replacementNode->setLeftChild(node->leftChild());
            if (nodeParent->rightChild() == node)
            {
                nodeParent->setRightChild(replacementNode);
                delete node;
            }
            else
            {
                nodeParent->setLeftChild(replacementNode);
                delete node;
            }
        }
        else
        {

            replacementNodeParent->setRightChild(replacementNode->leftChild());
            replacementNode->setLeftChild(nullptr);
            replacementNode->setLeftChild(node->leftChild());
            replacementNode->setRightChild(node->rightChild());
            if (nodeParent->rightChild() == node)
            {
                nodeParent->setRightChild(replacementNode);
                delete node;
            }
            else
            {
                nodeParent->setLeftChild(replacementNode);
                delete node;
            }
        }
        return true;
    }
}

BinaryTree::Node* BinaryTree::searchParent(Node* root, Node *node) const
{
	if (root == nullptr)
		return nullptr;
	if(root->rightChild() == node || root->leftChild() == node)
			return root;
	Node* subTreeSearchParentResult = searchParent(root->leftChild(), node);
	if (!subTreeSearchParentResult)
	{
		subTreeSearchParentResult = searchParent(root->rightChild(), node);
	}
	return subTreeSearchParentResult;
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

void BinaryTree::levelPrint(Node* root) const
{
	if (root == nullptr)
		return;
	std::list<Node*> unprocessedNodes(1, root);

	while (!unprocessedNodes.empty()) {
		int level = unprocessedNodes.size();

		while (level != 0)
		{
			Node* node = unprocessedNodes.front();
			unprocessedNodes.pop_front();

			std::cout << node->key() << " ";

			if (node->leftChild())
				unprocessedNodes.push_back(node->leftChild());
			if (node->rightChild())
				unprocessedNodes.push_back(node->rightChild());

			level--;
		}
		std::cout << "\n";
	}
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

bool BinaryTree::treeBalance(Node* root) const
{
	if (root == nullptr)
		return true;

	int leftHeight = height(root->leftChild());
	int rightHeight = height(root->rightChild());

	return std::abs(leftHeight - rightHeight) <= 1 && treeBalance(root->leftChild()) && treeBalance(root->rightChild());
}