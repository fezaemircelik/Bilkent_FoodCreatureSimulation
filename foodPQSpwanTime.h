//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#ifndef HW3_FOODPQSPWANTIME_H
#define HW3_FOODPQSPWANTIME_H

#include "foodHeapSpawnTime.h"

#include <iostream>
#include <fstream>
using namespace std;

class foodPQSpwanTime {
public:
    bool pqIsEmpty() const;
    void pqInsert(const food& newItem);
    void pqDelete(food priorityItem);

    foodHeapSpawnTime getH();

    food extractMin();

    food peak();
private:
    foodHeapSpawnTime h;
};


#endif //HW3_FOODPQSPWANTIME_H
