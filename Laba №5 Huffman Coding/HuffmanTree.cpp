#include "HuffmanTree.h"

#include "iostream"



HuffmanTree::Node::Node()
{}

std::string HuffmanTree::Node::stringifySymbols() const
{
	std::string str;
	for (int i = 0; i < symbols().length(); ++i)
	{
		if (symbols().bitValue(i))
		{
			str += char(i);
		}
	}
	return str;
}

int HuffmanTree::Node::frequency() const
{
	return m_frequency;
}

void HuffmanTree::Node::setFrequency(int frequency)
{
    m_frequency = frequency;
}

BoolVector HuffmanTree::Node::symbols() const
{
    return m_symbols;
}

void HuffmanTree::Node::setSymbols(BoolVector symbols)
{
    m_symbols = symbols;
}

HuffmanTree::Node* HuffmanTree::Node::leftChild() const
{
	return m_leftChild;
}

HuffmanTree::Node* HuffmanTree::Node::rightChild() const
{
	return m_rightChild;
}

void HuffmanTree::Node::setLeftChild(Node* leftChild)
{
	m_leftChild = leftChild;
}

void HuffmanTree::Node::setRightChild(Node* rightChild)
{
	m_rightChild = rightChild;
}

void HuffmanTree::Node::printHorizontal(Node* root, int marginLeft, int levelSpacing) const
{
	if (root == nullptr) {
		return;
	}
	printHorizontal(root->rightChild(), marginLeft + levelSpacing, levelSpacing);
	std::cout << std::string(marginLeft, ' ');
	std::cout << root->frequency() << ' ' << root->stringifySymbols();
	std::cout << std::endl;
	printHorizontal(root->leftChild(), marginLeft + levelSpacing, levelSpacing);
}

HuffmanTree::~HuffmanTree()
{
}

void HuffmanTree::clear()
{
	clear(m_root);
	m_root = nullptr;
}

void HuffmanTree::print()
{
	m_root->printHorizontal(m_root, 0, 15);
}

void HuffmanTree::build(const std::string& textFilename)
{
    std::string text;
    
    std::ifstream textFile;
    textFile.open(textFilename);

    if (!textFile.is_open())
        return;

    char ch;

    textFile >> ch;

    while (textFile.good())
    {
        text += ch;

        textFile >> ch;
    }

    textFile.close();

    BoolVector BV(256, 0);

    if (m_root)
    {
        clear();
    }

    std::vector<Node*> nodes;
    for (const char& symbol : text)
    {
        std::vector<Node*>::iterator it = std::find_if(
            nodes.begin(),
            nodes.end(),
            [&symbol](Node* node) // Безымянная функция
            {
                return node->symbols().bitValue(symbol);
            }
        );

        if (it == nodes.end())
        {
            nodes.push_back(new Node());

            BoolVector BV = nodes.back()->symbols();

            BV[symbol] = true;

            nodes.back()->setSymbols(BV);
        }
        else
        {
            Node* node = *it;
            node->setFrequency(node->frequency() + 1);
        }
    }

    // Ещё одна безымянная функция, сложили в переменную
    auto sorter = [](Node* a, Node* b) -> bool
        {
            return a->frequency() < b->frequency();
        };
    std::sort(nodes.begin(), nodes.end(), sorter);
    
    while (nodes.size() > 1)
    {
        Node* root = new Node();
        root->setFrequency(nodes[0]->frequency() + nodes[1]->frequency());
        
        BoolVector BV = root->symbols();

        for (int i = 0; i < root->symbols().length(); ++i)
        {
            BV[i] = nodes[0]->symbols()[i] || nodes[1]->symbols()[i];
        }

        root->setSymbols(BV);
        
        root->setLeftChild(nodes[0]);
        root->setRightChild(nodes[1]);

        nodes.erase(nodes.begin(), nodes.begin() + 2);
        nodes.push_back(root);
        std::sort(nodes.begin(), nodes.end(), sorter);
    }

    m_root = nodes.front();
}
<<<<<<< HEAD
=======

>>>>>>> Lab5
bool isEndFile(const std::string& fileBI);

double HuffmanTree::encode(const std::string& textFilename, const std::string& encodedTextFilename)
{
    std::ifstream textFile;
    std::ofstream encodedTextFile;

    std::string encodedText;

<<<<<<< HEAD
    int textFileSize = 0;
=======
    int encodedTextSize = 0;
>>>>>>> Lab5
    char symbol;

    textFile.open(textFilename);
    encodedTextFile.open(encodedTextFilename);

    if (isEndFile(textFilename) || !textFile.is_open() || !encodedTextFile.is_open())
    {
        textFile.close();
        encodedTextFile.close();
        return -1;
    }

    if (m_root == nullptr)
    {
        build(textFilename);
    }

    textFile >> symbol;
<<<<<<< HEAD

    while(textFile.good())
    {
        encodedText += encode(m_root, symbol);

        textFile >> symbol;
        
        textFileSize++;
    }

    double compresСoef = encodedText.size() / (textFileSize * 8.);
=======
    if (!m_root->leftChild() && !m_root->rightChild())
    {
        while (textFile.good())
        {
            encodedTextFile << '0';

            textFile >> symbol;
        }
        encodedTextSize = m_root->frequency();
    }
    else 
    {
        while (textFile.good()) 
        {
            for (int i = 0; i < encode(m_root, symbol).size(); i++)
            {
                encodedTextFile << encode(m_root, symbol)[i];
                encodedTextSize++;
            }
            textFile >> symbol;
        }
    }


    double compresСoef = encodedTextSize / (m_root->frequency() * 8.);
>>>>>>> Lab5

    for (int i = 0; i < encodedText.size(); i++)
    {
        encodedTextFile << encodedText[i];
    }

    textFile.close();
    encodedTextFile.close();

    return compresСoef;
}

<<<<<<< HEAD
bool HuffmanTree::decode(const std::string& encodedText, std::string& decodedText)
{
    return true;
}


=======
bool HuffmanTree::decode(const std::string& encodedTextFilename,const std::string& decodedTextFilename)
{

    std::ifstream encodedTextFile;
    std::ofstream decodedTextFile;

    encodedTextFile.open(encodedTextFilename);
    decodedTextFile.open(decodedTextFilename);

    if (!encodedTextFile.is_open() || !decodedTextFile.is_open())
    {
        return false;
    }

    decodedTextFile << decode(m_root, encodedTextFile);

    while (encodedTextFile.good())
    {
        decodedTextFile << decode(m_root, encodedTextFile);
    }

    encodedTextFile.close();
    decodedTextFile.close();

    return true;
}
>>>>>>> Lab5

std::string HuffmanTree::encode(Node* node, const char symbol)
{
    std::string str;

    if (node->leftChild() == nullptr && node->rightChild() == nullptr)
    {
        return str;
    }
    else if (node->leftChild()->symbols()[symbol])
    {
        str += '0';
        str += encode(node->leftChild(), symbol);
    }
    else
    {
        str += '1';
        str += encode(node->rightChild(), symbol);
    }

    return str;
}

<<<<<<< HEAD
bool HuffmanTree::decode(Node* node, const std::string& encodedText, std::string& decodedText)
{
    if (node->leftChild() == nullptr && node->rightChild() == nullptr)
    {
        return true;
    }

    return true;
}

bool HuffmanTree::decode(std::istream& encodedStream, std::ostream& decodedStream)
{
    return false;
=======
char HuffmanTree::decode(Node* node,std::ifstream& encodedTextFile)
{
    char symbol, letter;
    if (!encodedTextFile.good())
    {
        return ' ';
    }
    if (node->leftChild() == nullptr && node->rightChild() == nullptr)
    {
        return node->stringifySymbols()[0];
    }

    encodedTextFile >> symbol;

    if (symbol == '0')
    {
        letter = decode(node->leftChild(), encodedTextFile);
    }
    else
    {
        letter = decode(node->rightChild(), encodedTextFile);
    }

    return letter;
>>>>>>> Lab5
}

void HuffmanTree::clear(Node* node)
{
	if (node == nullptr)
		return;

	clear(node->leftChild());
	clear(node->rightChild());

	delete node;
	node = nullptr;
}

<<<<<<< HEAD

=======
>>>>>>> Lab5
bool isEndFile(const std::string& fileBI)
{
    std::ifstream fileB(fileBI);
    char ch;
    if (!(fileB >> ch))
    {
        fileB.close();
        return true;
    }
    fileB.close();
    return false;
}