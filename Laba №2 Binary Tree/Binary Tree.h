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
	//BinaryTree(const BinaryTree& other);
	//BinaryTree(BinaryTree&& other);
	~BinaryTree();

	Node* root() const;

	void clear();
	void removeSubtrees();


	bool isEmpty() const;

	int height(Node* root) const;
	int heightNode(Node* root, Node* node) const;

	int countOfRoots() const;

	int maxKey() const;
	int minKey() const;

	Node* addKey(int key);
	Node* nlrSearch(int key) const;

	bool removeKey(int key);

	
	bool contains(int key) const;

	std::vector<int> getVectorKeys() const;

	void bfsPrint(Node* root) const;

	void printTreeHorizontal(int marginLeft, int levelSpacing) const;


private:
	Node* m_root = nullptr;

private:

	void printHorizontal(Node* root, int marginLeft, int levelSpacing) const;
	bool contains(Node* root, int key) const;

	bool removeKey(Node* root, int key);
	Node* searchParent(Node* root, Node* node) const;

	Node* addKey(Node* root, int key);
	Node* nlrSearch(Node* root, int key) const;

	void clear(Node* node);
	void removeSubtrees(Node* node);


	std::vector<int> getVectorKeys(Node* root, std::vector<int>& keys) const;

};



/*
* ����������� ������ ������ Node (�� ������ "�����������������" ������ ����� ����� ����������� � ���� ��������� � ������� �������� ����-������):
- ������������ (�� ��������� � � �����������); +
- ���������/��������� ����� ���� (����� �����); +
- ���������/��������� �������� ����; +

����������� ������ ������ BinaryTree:
- ������������ (�� ��������� +, �����������, �����������);
- ����������; +
- ��������� ����� ������; +
- ������� ������ (�������� ���� �����); +
- �������� ����������� ����; +
- isEmpty (���������� true, ���� ������ �����); +
- ��������� ������ ������;
- ��������� ���������� ����� ������; +
- ��������� ������������/������������� ����� ������; +
- ���������� ���� � ������ (������� ���������� ������ ���������); +
- �������� ���� �� ������ �� ����� (���������� true, ���� ���� ��� �����); +
- ����� ���� ������ �� �����; +
- �������� ������ �� ������������������ (���������� true, ���� ������ �������� ����������������: ������ ������� � ������ ����������� ���������� �� �����, ��� �� �������, � ���� ���������� ����� �������� �����������������);
- ��������� ������ ������� �� ����� (���������� ������ ������ ��� -1, ���� ������� �� �������);
- ��������� ������� (std::vector<int>), ����������� ��� ����� ������ �� ����������� (����� ������ ����������� ����� ��������); +
- ����� � ������� ������ � �������������� ���� (����� ������ ������� ��������� �� ������ ������, ����� ����� - �� ������); +
- ����� � ������� ������ �� ������� � �������;
- �������� ������������;
- �������� �����������.
*/
