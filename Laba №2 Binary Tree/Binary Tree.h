#pragma once

#include "iostream"
#include <vector>

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

	void clear(Node* root);
	void removeSubtrees(Node* root);

	bool isEmpty() const;

	//int height(Node* root) const;

	int countOfRoots() const;

	int maxKey() const;
	int minKey() const;

	Node* addNode(Node* root, int key);
	bool searchNode(int key);

	void lrnPrint(Node* root) const;

	std::vector<int> getVectorKeys(Node* root, std::vector<int> &key) const;

	void printTree(int leftBorderPos, int rightBorderPos) const;
	void printTreeHorizontal(int marginLeft, int levelSpacing) const;



private:
	Node* m_root = nullptr;

private:
	void m_print(Node* root, int leftBorderPos, int rightBorderPos, int yPos) const;
	void m_printHorizontal(Node* root, int marginLeft, int levelSpacing) const;

};



/*
* ����������� ������ ������ Node (�� ������ "�����������������" ������ ����� ����� ����������� � ���� ��������� � ������� �������� ����-������):
- ������������ (�� ��������� � � �����������); +
- ���������/��������� ����� ���� (����� �����); +
- ���������/��������� �������� ����; +

����������� ������ ������ BinaryTree:
- ������������ (�� ���������M +, �����������, �����������);
- ����������; +
- ��������� ����� ������; +
- ������� ������ (�������� ���� �����); +
- �������� ����������� ����; +
- isEmpty (���������� true, ���� ������ �����); +
- ��������� ������ ������;
- ��������� ���������� ����� ������; +
- ��������� ������������/������������� ����� ������; +
- ���������� ���� � ������ (������� ���������� ������ ���������); +
- �������� ���� �� ������ �� ����� (���������� true, ���� ���� ��� �����);
- ����� ���� ������ �� �����; +
- �������� ������ �� ������������������ (���������� true, ���� ������ �������� ����������������: ������ ������� � ������ ����������� ���������� �� �����, ��� �� �������, � ���� ���������� ����� �������� �����������������);
- ��������� ������ ������� �� ����� (���������� ������ ������ ��� -1, ���� ������� �� �������);
- ��������� ������� (std::vector<int>), ����������� ��� ����� ������ �� ����������� (����� ������ ����������� ����� ��������); +
- ����� � ������� ������ � �������������� ���� (����� ������ ������� ��������� �� ������ ������, ����� ����� - �� ������); +
- ����� � ������� ������ �� ������� � �������;
- �������� ������������;
- �������� �����������.
*/
