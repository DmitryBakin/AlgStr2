#pragma once

#include "/O-O-P/boolVector/boolVector.h"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>


class HuffmanTree
{
	class Node
	{
	public:
		Node();
		~Node() = default;

		std::string stringifySymbols() const;

		int frequency() const;
		void setFrequency(int frequency);

		BoolVector symbols() const;
		void setSymbols(BoolVector symbols);

		Node* leftChild() const;
		Node* rightChild() const;

		void setLeftChild(Node* leftChild);
		void setRightChild(Node* rightChild);

		void printHorizontal(Node* root, int marginLeft, int levelSpacing) const;

		BoolVector m_symbols = BoolVector(256, 0);

	private:
		

		int m_frequency = 1;

		Node* m_leftChild = nullptr;
		Node* m_rightChild = nullptr;

	};
public:
	HuffmanTree() = default;
	~HuffmanTree();

	void clear();

	void print();

	void build(const std::string& text);

	double encode(const std::string& textFilename, const std::string& encodedTextFilename);

	bool decode(const std::string& encodedText, std::string& decodedText);

private:

	std::string encode(Node* node, const char symbol);

	bool decode(Node* node, const std::string& encodedText, std::string& decodedText);

	bool decode(std::istream& encodedStream, std::ostream& decodedStream);

	void clear(Node* node);

private:
	Node* m_root = nullptr;


};


