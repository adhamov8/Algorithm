//
// Created by Alibek Adhamov on 02/02/24.
//

#include "HashCuckooTable.h"

HashCuckooTable::HashCuckooTable(int size) : size(size) {
        table1.resize(size, -1);
        table2.resize(size, -1);
    }

    int HashCuckooTable::hashFunction1(int key) {
        return key % size;
    }

    int HashCuckooTable::hashFunction2(int key) {
        return (key / size) % size;
    }

    bool HashCuckooTable::insertHelper(int key, std::vector<int>& table, int count) {

        if (count == size) {
            return false;
        }

        int index;
        if (count % 2 == 0) {
            index = hashFunction1(key);
        } else {
            index = hashFunction2(key);
        }

        if (table[index] == -1) {
            table[index] = key;
            return true;
        } else {
            int displace = table[index];
            table[index] = key;
            return insertHelper(displace, table, count + 1);
        }
    }

    bool HashCuckooTable::insert(int key) {
        return insertHelper(key, table1, 0) || insertHelper(key, table2, 0);
    }

bool HashCuckooTable::search(int key) {
    return (table1[hashFunction1(key)] == key ||
    table2[hashFunction2(key)] == key ||
    table1[hashFunction2(key)] == key ||
    table2[hashFunction1(key)] == key);
}


