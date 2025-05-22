#pragma once

#include "iostream"
#include <vector>
#include <list>
#include <algorithm>

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
	BinaryTree(Node* root);
	BinaryTree(const BinaryTree& other);
	BinaryTree(BinaryTree&& other);
	virtual ~BinaryTree();

	Node* root() const;

	
	void clear();
	void removeSubtrees();
	
	bool isEmpty() const;

	int height() const;
	virtual int nodeHeightIndex(int key) const;
	int indexNode(int key) const;

	int countOfRoots() const;

	virtual int maxKey() const;
	virtual int minKey() const;

	virtual Node* addKey(int key);
	Node* nlrSearch(int key) const;

	virtual bool removeKey(int key);
	Node* searchParent(Node* root, Node* node) const;
	
	bool contains(int key) const;
	virtual std::vector<int> getVectorKeys() const;

	void levelPrint() const;
	void printTreeHorizontal(int marginLeft, int levelSpacing) const;

	bool isBalanced() const;

	BinaryTree& operator=(const BinaryTree& other);
	BinaryTree& operator=(BinaryTree&& other);
	
	void setRoot(Node* root);

private:
	Node* m_root = nullptr;

private:
	

	Node* copyTree(Node* root);

	void clear(Node* node);
	void removeSubtrees(Node* node);

	int height(Node* root) const;
	virtual int nodeHeightIndex(Node* root, int key, int level) const;
	int indexNode(Node* root, int key) const;

	int countOfRoots(Node* node) const;

	virtual int maxKey(Node* node) const;
	virtual int minKey(Node* node) const;

	virtual Node* addKey(Node* root, int key);
	Node* nlrSearch(Node* root, int key) const;

	virtual bool removeKey(Node* root, int key);

	bool contains(Node* root, int key) const;
	virtual std::vector<int> getVectorKeys(Node* root, std::vector<int>& keys) const;

	void levelPrint(Node* root) const;
	void printHorizontal(Node* root, int marginLeft, int levelSpacing) const;

	bool isBalanced(Node* root) const;
};






















/*
* ����������� ������ ������ Node (�� ������ "�����������������" ������ ����� ����� ����������� � ���� ��������� � ������� �������� ����-������):
- ������������ (�� ��������� � � �����������); +
- ���������/��������� ����� ���� (����� �����); +
- ���������/��������� �������� ����; +

����������� ������ ������ BinaryTree:
- ������������ (�� ��������� +, ����������� +, ����������� +);
- ����������; +
- ��������� ����� ������; +
- ������� ������ (�������� ���� �����); +
- �������� ����������� ����; +
- isEmpty (���������� true, ���� ������ �����); +
- ��������� ������ ������; +
- ��������� ���������� ����� ������; +
- ��������� ������������/������������� ����� ������; +
- ���������� ���� � ������ (������� ���������� ������ ���������); +
- �������� ���� �� ������ �� ����� (���������� true, ���� ���� ��� �����); +
- ����� ���� ������ �� �����; +
- �������� ������ �� ������������������ (���������� true, ���� ������ �������� ����������������: ������ ������� � ������ ����������� ���������� �� �����, ��� �� �������, � ���� ���������� ����� �������� �����������������); +
- ��������� ������ ������� �� ����� (���������� ������ ������ ��� -1, ���� ������� �� �������); +
- ��������� ������� (std::vector<int>), ����������� ��� ����� ������ �� ����������� (����� ������ ����������� ����� ��������); +
- ����� � ������� ������ � �������������� ���� (����� ������ ������� ��������� �� ������ ������, ����� ����� - �� ������); +
- ����� � ������� ������ �� ������� � �������; +
- �������� ������������; +
- �������� �����������. +
*/
