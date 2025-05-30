#include "HuffmanTree.h"

int main()
{

	HuffmanTree HT;


	const std::string fileName = "textFile.txt";
	const std::string encodedFileName = "encodedTextFile.txt";
<<<<<<< HEAD
=======
	const std::string decodedFileName = "decodedTextFile.txt";
>>>>>>> Lab5

	//HT.build(fileName);

	
	std::cout << HT.encode(fileName, encodedFileName);
	
<<<<<<< HEAD
=======
	puts("");

	HT.decode(encodedFileName, decodedFileName);

>>>>>>> Lab5
	HT.print();
	return 0;
}
