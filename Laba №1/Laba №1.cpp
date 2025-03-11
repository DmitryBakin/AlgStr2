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


void fileSort(std::string& filename)
{
	std::string file_0 = "file_0";
	std::string file_1 = "file_1";
	std::string file_2 = "file_2";
	std::string file_3 = "file_3";

	split(filename, file_0, file_1);

	
}
void main()
{
	for (int border = 10; border <= 10; border *= 100)
		for (int size = 10000; size <= 10000; size *= 10)
		{
			std::string filename = "random_mas_" + std::to_string(size) + "_" + std::to_string(border) + ".txt";
			
			fileSort(filename);

			if (isFileContainsSortedArray("random_mas_" + std::to_string(size) + "_" + std::to_string(border) + ".txt"))
				std::cout << "OK";
			else
				std::cout << "GG\n";
		}
}