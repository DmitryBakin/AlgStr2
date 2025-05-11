#pragma once

#include "../Laba №2 Binary Tree/Binary Tree.h"


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

	std::vector<int> getVectorKeys() const override;

	BinarySearchTree& operator=(const BinarySearchTree& other) = default;
	BinarySearchTree& operator=(BinarySearchTree&& other) = default;

private:
	Node* addKey(Node* root, int key) override;

	bool removeKey(Node* root, int key) override;
	
	Node* findKey(Node* root, int key) const;

	int minKey(Node* root) const override;
	int maxKey(Node* root) const override;

	std::vector<int> getVectorKeys(Node* root, std::vector<int>& keys) const override;
};











/*
Необходимые методы класса:
- конструкторы (по умолчанию, копирования, перемещения); +
- деструктор; +
- получение минимального/максимального ключа дерева (имеет другой алгоритм); +
- добавление узла в дерево (имеет другой алгоритм); +
- удаление узла из дерева по ключу (возвращает true, если узел был удалён) (имеет другой алгоритм); +
- поиск узла дерева по ключу (имеет другой алгоритм); +
- получение уровня вершины по ключу (возвращает индекс уровня или -1, если вершина не найдена) (имеет другой алгоритм);
- получение вектора (std::vector<int>), содержащего все ключи дерева по возрастанию (имеет другой алгоритм); +
- оператор присваивания; +
- оператор перемещения. +
*/