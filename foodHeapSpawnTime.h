//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#ifndef HW3_FOODHEAPSPAWNTIME_H
#define HW3_FOODHEAPSPAWNTIME_H

#include "food.h"

#include <iostream>
#include <fstream>
using namespace std;


class foodHeapSpawnTime {
public:
    foodHeapSpawnTime();

    bool heapIsEmpty() const;
    void heapInsert(const food& newItem);
    void heapDelete(food& rootItem);

    food peak();

    void MinHeapify(int i);
    int parent(int i){return (i-1)/2;}
    int left(int i){return (2*i + 1);}
    int right(int i){return (2*i + 2);}
    food extractMin();
    void decreaseKey(int i , food new_val);
    food getMin(){return food_p[0];}
    void deleteKey(int i);
    void insertKey(food k);

protected:
    void heapRebuild(int root);

private:
    food items[500];
    int size;

    food *food_p;
    int capacity;
    int heapSize;
};


#endif //HW3_FOODHEAPSPAWNTIME_H