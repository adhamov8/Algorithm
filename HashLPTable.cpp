//
// Created by Alibek Adhamov on 02/02/24.
//

#include<iostream>
#include "HashLPTable.h"


HashLPTable::HashLPTable(int size) : size(size) {
        table.resize(size, -1);
    }

    int HashLPTable::hashFunction(int key) {
        return key % size;
    }

    void HashLPTable::insert(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {
            index = (index + 1) % size;
        }
        table[index] = key;
    }

    bool HashLPTable::search(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + 1) % size;
        }
        return false;
    }

    void HashLPTable::remove(int key) {
        int index = hashFunction(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                table[index] = -1;
                return;
            }
            index = (index + 1) % size;
        }
    }
