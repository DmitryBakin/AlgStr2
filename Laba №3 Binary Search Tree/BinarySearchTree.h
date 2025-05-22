#pragma once

#include "../Laba ¹2 Binary Tree/Binary Tree.h"


class BinarySearchTree : public BinaryTree
{
public:
	BinarySearchTree() = default;
	BinarySearchTree(Node* node);
	BinarySearchTree(const BinarySearchTree& other) = default;
	BinarySearchTree(BinarySearchTree&& other) = default;

	~BinarySearchTree() override = default;

	using BinaryTree::addKey;
	using BinaryTree::removeKey;
	using BinaryTree::minKey;
	using BinaryTree::maxKey;
	using BinaryTree::nodeHeightIndex;
	using BinaryTree::getVectorKeys;

	Node* findKey(int key) const;

	BinarySearchTree& operator=(const BinarySearchTree& other) = default;
	BinarySearchTree& operator=(BinarySearchTree&& other) = default;

protected:
	Node* addKey(Node* root, int key) override;

	bool removeKey(Node* root, int key) override;

	int minKey(Node* root) const override;
	int maxKey(Node* root) const override;

	int nodeHeightIndex(Node* node, int key, int level) const override;

	std::vector<int> getVectorKeys(Node* root, std::vector<int>& keys) const override;

private:
	Node* findKey(Node* root, int key) const;
};







