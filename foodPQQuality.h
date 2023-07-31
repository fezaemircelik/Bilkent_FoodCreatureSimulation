//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#ifndef HW3_FOODPQQUALITY_H
#define HW3_FOODPQQUALITY_H

#include "foodHeapQuality.h"

#include <iostream>
#include <fstream>
using namespace std;

class foodPQQuality {
public:
    bool pqIsEmpty() const;
    void pqInsert(const food newItem);
    void pqDelete(food &priorityItem);

    foodHeapQuality getH();

    food peak();
private:
    foodHeapQuality h;
};


#endif //HW3_FOODPQQUALITY_H
