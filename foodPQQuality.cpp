//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#include "foodPQQuality.h"

bool foodPQQuality::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void foodPQQuality::pqInsert(const food newItem) {
    h.heapInsert(newItem);
}

void foodPQQuality::pqDelete(food &priorityItem) {
    h.heapDelete(priorityItem);
}

foodHeapQuality foodPQQuality::getH() {
    return this->h;
}

food foodPQQuality::peak() {
    return this->h.peak();
}
