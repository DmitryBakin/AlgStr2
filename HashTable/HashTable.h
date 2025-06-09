#include <math.h>
#include <iostream>
#include <vector>
#include <utility>

#include "/O-O-P/List/List.h"


class IHashFunction
{
public:
    virtual int hash(const int& key, const int& capacity) const = 0;
};

class QuadraticHashFunction : public IHashFunction
{
public:
    int hash(const int& key, const int& capacity) const override
    {
        int hash0 = key % capacity;
        int hash = (hash0 + 2) % capacity;

        return hash;
    }
};

class MultiplicationHashFunction : public IHashFunction
{
public:
    int hash(const int& key, const int& capacity) const override
    {
        int hash0 = key % capacity;
        double a = -(1. - std::sqrt(5)) / 2.;

        int hash = int(hash0 * a * capacity) % capacity;

        return hash;
    }
};

class ThirdHashFunction : public IHashFunction
{
public:
    int hash(const int& key, const int& capacity) const override
    {
        int hash0 = key % capacity;
        int hash = ((hash0 + 1) * (1 + key % (capacity - 2))) % capacity;

        return hash;
    }
};

template <typename T>
class HashTable
{
public:
    HashTable() = default;
    HashTable(IHashFunction* hashFunction, int capacity);
    HashTable(const HashTable& other);
    ~HashTable();

    void setCapacity(int capacity);
    int capacity() const;

    void setFunction(IHashFunction* someFunction);
    IHashFunction* hashFunction() const;

    std::vector<List<std::pair<int, T>>> hashTable() const;

    bool contains(const int& key) const;
    int indexKey(const int& key) const;

    void insert(const int& key, const T& value);
    void removeKey(const int& key);

    void swap(HashTable& other);

    friend std::ostream& operator<<(std::ostream& os, const HashTable<T>& other);

private:

    IHashFunction* m_hashFunction = nullptr;

    std::vector<List<std::pair<int, T>>> m_hashTable;

    int m_capacity = 0;
};

template <typename T>
HashTable<T>::HashTable(IHashFunction* hashFunction, int capacity)
    :m_hashFunction(hashFunction), m_capacity(capacity)
{
    for (int i = 0; i < m_capacity; i++)
    {
        List<std::pair<int, T>> list = List<std::pair<int, T>>();
        m_hashTable.push_back(list);
    }
}

template <typename T>
HashTable<T>::HashTable(const HashTable& other)
    :m_capacity(other.capacity()), m_hashFunction(other.hashFunction()), m_hashTable(other.hashTable())
{
}

template <typename T>
HashTable<T>::~HashTable()
{}

template <typename T>
void HashTable<T>::setCapacity(int capacity)
{
    HashTable<T> HTcopy(*this);

    m_hashTable.clear();

    for (int i = 0; i < capacity; i++)
    {
        List<std::pair<int, T>> list = List<std::pair<int, T>>();
        m_hashTable.push_back(list);
    }

    m_capacity = capacity;

    for (int i = 0; i < HTcopy.capacity(); i++)
    {
        for (int j = 0; j < HTcopy.hashTable()[i].size(); j++)
        {
            insert(HTcopy.hashTable()[i][j].first, HTcopy.hashTable()[i][j].second);
        }
    }

    
}

template <typename T>
int HashTable<T>::capacity() const
{
    return m_capacity;
}

template<typename T>
void HashTable<T>::setFunction(IHashFunction* someFunction)
{
    HashTable<T> HTcopy(*this);

    for (int i = 0; i < m_hashTable.size(); i++)
    {
        m_hashTable[i].clear();
    }

    m_hashFunction = someFunction;

    for (int i = 0; i < HTcopy.capacity(); i++)
    {
        for (int j = 0; j < HTcopy.hashTable()[i].size(); j++)
        {
            insert(HTcopy.hashTable()[i][j].first, HTcopy.hashTable()[i][j].second);
        }
    }
}

template<typename T>
IHashFunction* HashTable<T>::hashFunction() const
{
    return m_hashFunction;
}

template <typename T>
std::vector<List<std::pair<int, T>>> HashTable<T>::hashTable() const
{
    return m_hashTable;
}

template<typename T>
bool HashTable<T>::contains(const int& key) const
{
    int hash = m_hashFunction->hash(key, m_capacity);

    for (int i = 0; i < m_hashTable[hash].size(); i++)
    {
        if (m_hashTable[hash][i].first == key)
        {
            return true;
        }
    }
    return false;
}

template<typename T>
inline int HashTable<T>::indexKey(const int& key) const
{
    int hash = m_hashFunction->hash(key, m_capacity);

    for (int i = 0; i < m_hashTable[hash].size(); i++)
    {
        if (m_hashTable[hash][i].first == key)
        {
            return i;
        }
    }
    return false;
}

template <typename T>
void HashTable<T>::insert(const int& key, const T& value)
{
    if (contains(key))
    {
        return;
    }
    int hash = m_hashFunction->hash(key, m_capacity);

    m_hashTable[hash].addToTail(std::pair<int, T>(key, value));
}

template<typename T>
void HashTable<T>::removeKey(const int& key)
{
    int index = indexKey(key);
    if (index == -1)
    {
        return;
    }
    int hash = m_hashFunction->hash(key, m_capacity);

    m_hashTable[hash].deleteElementFromPosition(index);
}

template<typename T>
void HashTable<T>::swap(HashTable& other)
{
    std::swap(m_capacity, other.m_capacity);
    std::swap(m_hashFunction, other.m_hashFunction);
    std::swap(m_hashTable, other.m_hashTable);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, HashTable<T>& other)
{
    for (int i = 0; i < other.capacity(); i++)
    {
        os << "hash = " << i << ":\t";
        for (int j = 0; j < other.hashTable()[i].size(); j++)
        {
            os << "key = " << other.hashTable()[i][j].first << ", value = " << other.hashTable()[i][j].second << " -----> ";
        }
        os << "NULL" << std::endl;
    }
    return os;
}



/*Необходимые методы класса:
- конструкторы (по умолчанию +, копирования +);
- деструктор; +
- добавление элемента с заданным ключом в таблицу; +
- удаление элемента из таблицы по ключу; +
- проверка наличия в таблице элемента с заданным ключом; +
- обмен содержимым с другой таблицей (swap); +
- вывод содержимого таблицы в консоль (в каждой строке выводить хеш, после этого все связанные с ним пары "ключ-значение"); +
- вывод содержимого таблицы на форму (Qt);
- замена хеш-функции (места для уже добавленных элементов должны быть пересчитаны в соответствии с новой функцией); +
- изменение размера хеш-таблицы; +
- оператор присваивания;
- получение ссылки на значение по ключу (operator []).
*/