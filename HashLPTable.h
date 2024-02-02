//
// Created by Alibek Adhamov on 02/02/24.
//

#ifndef UNTITLED2_HASHLPTABLE_H
#define UNTITLED2_HASHLPTABLE_H

#include<vector>

class HashLPTable {
private:
    std::vector<int> table;
    int size;

public:
    HashLPTable(int size);
    int hashFunction(int key);
    void insert(int key);
    bool search(int key);
    void remove(int key);
};


#endif //UNTITLED2_HASHLPTABLE_H
