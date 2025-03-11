#include <iostream>
#include <vector>
#include <fstream>
#include <string>

bool isFileContainsSortedArray(const std::string& fileName)
{
	int valueNow = 0, valuePrev = -100000000;
	std::string ch;
	std::ifstream file;
	file.open(fileName);
	while (!file.eof())
	{
		ch = "";
		file >> ch;
		if (ch != "")
		{
			valueNow = stoi(ch);
			if (valueNow < valuePrev)
				return false;
			valuePrev = valueNow;
		}
	}
	return true;
}



void split(std::string& filename, std::string& fileSplit1, std::string& fileSplit2)
{
	std::ifstream file(filename);
	std::ofstream file_1(fileSplit1);
	std::ofstream file_2(fileSplit2);

	int value;
	file >> value;

	while ((!file.eof()))
	{
		//std::cout << value;
		file_1 << value << " ";
		file >> value;
		///std::cout << value;
		file_2 << value << " ";
		file >> value;
	}
	file.close();
	file_1.close();
	file_2.close();
}

void fileMerges(const int p, std::ifstream *inputFile, std::ofstream* outputFile)
{

	int* mas = new int[2];

	inputFile[0] >> mas[0];
	inputFile[1] >> mas[1];
	int n = 0;
	while (!inputFile[0].eof() && !inputFile[1].eof())
	{
		int i = 0, j = 0;
		while (!inputFile[0].eof() && !inputFile[1].eof() && i < p && j < p)
		{
			if (mas[0] < mas[1])
			{
				outputFile[n] << mas[0] << " ";
				inputFile[0] >> mas[0];
				i++;
			}
			else
			{
				outputFile[n] << mas[1] << " ";
				inputFile[1] >> mas[1];
				j++;
			}
		}
		while (!inputFile[0].eof() && i < p)
		{
			outputFile[n] << mas[0] << " ";
			inputFile[0] >> mas[0];
			i++;
		}
		while (!inputFile[1].eof() && j < p)
		{
			outputFile[n] << mas[1] << " ";
			inputFile[1] >> mas[1];
			j++;
		}
		n = 1 - n;
	}
	while (!inputFile[0].eof())
	{
		outputFile[n] << mas[0] << " ";
		inputFile[0] >> mas[0];
	}
	while (!inputFile[1].eof())
	{
		outputFile[n] << mas[1] << " ";
		inputFile[1] >> mas[1];
	}
	delete[]mas;
}


void fileSort(std::string& filename)
{
	std::string file_0 = "file_0";
	std::string file_1 = "file_1";
	std::string file_2 = "file_2";
	std::string file_3 = "file_3";
	


	split(filename, file_0, file_1);
	int p = 1;

	while(file_1.eof())
	{
		std::ifstream inputFile[2];
		std::ofstream outputFile[2];

		inputFile[0].open(file_0);
		inputFile[1].open(file_1);
		outputFile[0].open(file_2);
		outputFile[1].open(file_3);

		fileMerges(p, inputFile, outputFile);

		inputFile[0].close();
		inputFile[1].close();
		outputFile[0].close();
		outputFile[1].close();

		p *= 2;

		inputFile[0].open(file_2);
		inputFile[1].open(file_3);
		outputFile[0].open(file_0);
		outputFile[1].open(file_1);

		fileMerges(p, inputFile, outputFile);

		inputFile[0].close();
		inputFile[1].close();
		outputFile[0].close();
		outputFile[1].close();
		
		p *= 2;

		file.open(file_3);
	} 
	
}
void main()
{
	for (int border = 10; border <= 10; border *= 100)
		for (int size = 10000; size <= 10000; size *= 10)
		{
			std::string filename = "random_mas_" + std::to_string(size) + "_" + std::to_string(border) + ".txt";
			
			fileSort(filename);

			if (isFileContainsSortedArray("file_0"))
				std::cout << "OK";
			else
				std::cout << "GG\n";
		}
}