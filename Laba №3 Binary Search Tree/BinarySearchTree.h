#pragma once

#include "../Laba ¹2 Binary Tree/Binary Tree.h"


class BinarySearchTree : public BinaryTree
{
public:
	BinarySearchTree() = default;
	BinarySearchTree(Node* node);
	BinarySearchTree(const BinarySearchTree& other) = default;
	BinarySearchTree(BinarySearchTree&& other) = default;

	~BinarySearchTree() = default;

	Node* addKey(int key) override;

	bool removeKey(int key) override;

	Node* findKey(int key) const;

	int minKey() const override;
	int maxKey() const override;

	int nodeHeightIndex(int key) const override;

	std::vector<int> getVectorKeys() const override;

	BinarySearchTree& operator=(const BinarySearchTree& other) = default;
	BinarySearchTree& operator=(BinarySearchTree&& other) = default;

private:
	Node* addKey(Node* root, int key) override;

	bool removeKey(Node* root, int key) override;
	
	Node* findKey(Node* root, int key) const;

	int minKey(Node* root) const override;
	int maxKey(Node* root) const override;

	int nodeHeightIndex(Node* node, int key, int level) const override;

	std::vector<int> getVectorKeys(Node* root, std::vector<int>& keys) const override;
};







