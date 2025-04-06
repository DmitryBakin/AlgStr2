#pragma once

#include "iostream"

class BinaryTree 
{
public:
	class Node {
	public:
		Node();
		Node(int key = 0, Node* leftChild = nullptr, Node* rightChild = nullptr);
		~Node() = default;

		int key() const;
		void setKey(const int key);

		Node* leftChild() const;
		Node* rightChild() const;

		void setLeftChild(Node* leftChild);
		void setRightChild(Node* rightChild);

	private:
		int m_key = 0;
		Node* m_leftChild = nullptr;
		Node* m_rightChild = nullptr;
	};

	BinaryTree() = default;
	~BinaryTree();

	void print(Node* root, int leftBorderPos, int rightBorderPos, int yPos) const;
	void printHorizontal(Node* root, int marginLeft, int levelSpacing) const;

private:
	Node* m_root = nullptr;
};




