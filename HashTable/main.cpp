#include "HashTable.h"

int main()
{
    HashTable<std::string> HT(new QuadraticHashFunction(), 6);

    HT.insert(23, "1234");
    HT.insert(65, "1234");
    HT.insert(75, "1234");
    HT.insert(2, "1234");
    HT.insert(8, "1234");
    HT.insert(5, "1234");
    HT.insert(9, "1234");

    std::cout << HT;

    HT.removeKey(9);

    std::cout << "\n\n\n" << HT;
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
