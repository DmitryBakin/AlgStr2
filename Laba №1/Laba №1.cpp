#include <iostream>
#include <fstream>
#include <string>

bool isFileContainsSortedArray(const std::string& fileName, const int min)
{
	int valueNow = 0, valuePrev = min;
	std::ifstream file;
	file.open(fileName);
	while (file >> valueNow)
	{
		if (valueNow < valuePrev)
		{
			return false;
		}
		valuePrev = valueNow;
	}
	return true;
}

bool isEndFile(std::string& fileBI)
{
	std::ifstream fileB(fileBI);
	int ch;
	if (!(fileB >> ch))
	{
		fileB.close();
		return true;
	}
	fileB.close();
	return false;
}

void splitting(std::string& filename, std::string& fileSplit1, std::string& fileSplit2)
{
	std::ofstream fileSplit[2];
	fileSplit[0].open(fileSplit1);
	fileSplit[1].open(fileSplit2);
	std::ifstream file(filename);

	int n = 0, x, i;
	file >> x;
	while (file.good())
	{
		i = 0;
		while (file.good() && i < 1)
		{
			fileSplit[n] << x << " ";
			file >> x;
			i++;
		}
		n = 1 - n;
	}
	file.close();
	fileSplit[0].close();
	fileSplit[1].close();
}

bool fileMerges(const int p, std::string& inputFile1, std::string& inputFile2, std::string& outputFile1, std::string& outputFile2)
{

	std::ifstream inputFile[2];
	std::ofstream outputFile[2];

	inputFile[0].open(inputFile1);
	inputFile[1].open(inputFile2);
	outputFile[0].open(outputFile1);
	outputFile[1].open(outputFile2);

	int mas[2];

	inputFile[0] >> mas[0];
	inputFile[1] >> mas[1];
	int n = 0;
	while (inputFile[0].good() || inputFile[1].good())
	{
		int i = 0, j = 0;
		bool firstEnded = !(inputFile[0].good() && i < p);
		bool secondEnded = !(inputFile[1].good() && j < p);
		while (!firstEnded || !secondEnded)
		{
			if (!firstEnded && (secondEnded || mas[0] < mas[1]))
			{
				outputFile[n] << mas[0] << " ";
				inputFile[0] >> mas[0];
				i++;
				firstEnded = !(inputFile[0].good() && i < p);
			}
			else if (!secondEnded)
			{
				outputFile[n] << mas[1] << " ";
				inputFile[1] >> mas[1];
				j++;
				secondEnded = !(inputFile[1].good() && j < p);
			}
			bool foo = false;
		}
		n = 1 - n;
	}

	if (!isEndFile(outputFile2))
	{
		inputFile[0].close();
		inputFile[1].close();
		outputFile[0].close();
		outputFile[1].close();
		return true;
	}

	inputFile[0].close();
	inputFile[1].close();
	outputFile[0].close();
	outputFile[1].close();
	return false;

}

void fileSort(std::string& filename)
{
	std::string file_0 = "file_0";
	std::string file_1 = "file_1";
	std::string file_2 = "file_2";
	std::string file_3 = "file_3";
	
	splitting(filename, file_0, file_1);
	
	int p = 1;

	while(fileMerges(p, file_0, file_1, file_2, file_3))
	{
		std::swap(file_0, file_2);
		std::swap(file_1, file_3);
		p *= 2;
	} 

}

void main()
{
	for (int border = 10; border <= 10; border *= 100)
		for (int size = 10000; size <= 10000; size *= 10)
		{
			std::string filename = "random_mas_" + std::to_string(size) + "_" + std::to_string(border) + ".txt";

			fileSort(filename);

			if (isFileContainsSortedArray("file_0", -border) || isFileContainsSortedArray("file_2", -border))
				std::cout << "File sorted\n";
			else
				std::cout << "File is not sorting\n";
		}
}