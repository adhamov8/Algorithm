//
// Created by Alibek Adhamov on 02/02/24.
//

#include<vector>

#ifndef UNTITLED2_HASHCUCKOOTABLE_H
#define UNTITLED2_HASHCUCKOOTABLE_H

class HashCuckooTable {
private:
    std::vector<int> table1;
    std::vector<int> table2;
    int size;

public:
    HashCuckooTable(int size);

    int hashFunction1(int key);

    int hashFunction2(int key);

    bool insertHelper(int key, std::vector<int>& table, int count);

    bool insert(int key);

    bool search(int key);
};

#endif //UNTITLED2_HASHCUCKOOTABLE_H
