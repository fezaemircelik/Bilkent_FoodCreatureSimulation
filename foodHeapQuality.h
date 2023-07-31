//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#ifndef HW3_FOODHEAPQUALITY_H
#define HW3_FOODHEAPQUALITY_H

#include "food.h"

#include <iostream>
#include <fstream>
using namespace std;

class foodHeapQuality {
public:
    foodHeapQuality();

    bool heapIsEmpty() const;
    void heapInsert(const food& newItem);
    void heapDelete(food& rootItem);

    food peak();

protected:
    void heapRebuild(int root);

private:
    food items[500];
    int size;
};


#endif //HW3_FOODHEAPQUALITY_H
