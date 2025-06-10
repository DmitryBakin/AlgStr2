#include "HashTable.h"

#include <string>

int main()
{
    HashTable<std::string> HT(new QuadraticHashFunction(), 10000);

    srand(0);
    for (int i = 0; i < 100000; i++)
    {
        if (i % 10000 == 0)
        {
            std::cout << i << "\n";
        }
        int index = rand() % 1000;
        std::string str = "Sanaa-Mergen." + std::to_string(index);
        HT.insert(i, str);
    }

    HT.removeKey(23);

    std::cout << HT[23];

    //std::cout << HT;

    //HT.setFunction(new MultiplicationHashFunction());

    //std::cout << "\n\n\n" << HT;

    //HT.setFunction(new ThirdHashFunction());

    //std::cout << "\n\n\n" << HT;

    //HT.setCapacity(10);

    //std::cout << "\n\n\n" << HT;

    //HT.setCapacity(3);

    //std::cout << "\n\n\n" << HT;
    /*
    for (int i = 0; i < HT.capacity(); i++)
    {
        for (int j = 0; j < HT.hashTable()[i].size(); j++)
        {
            std::cout <<"key = " << HT.hashTable()[i][j].first << ", value = " << HT.hashTable()[i][j].second << " -----> ";
        }
        std::cout << "NULL" << std::endl;
    }
    */
}
