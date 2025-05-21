#include "HuffmanTree.h"

int main()
{

	HuffmanTree HT;


	const std::string fileName = "textFile.txt";
	const std::string encodedFileName = "encodedTextFile.txt";

	//HT.build(fileName);

	
	std::cout << HT.encode(fileName, encodedFileName);
	
	HT.print();
	return 0;
}
