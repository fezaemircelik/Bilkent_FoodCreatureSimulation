//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#include "foodPQSpwanTime.h"

bool foodPQSpwanTime::pqIsEmpty() const {
    return h.heapIsEmpty();
}

void foodPQSpwanTime::pqInsert(const food &newItem) {
    h.heapInsert(newItem);
}

void foodPQSpwanTime::pqDelete(food priorityItem) {
    h.heapDelete(priorityItem);
}

foodHeapSpawnTime foodPQSpwanTime::getH() {
    return this->h;
}

food foodPQSpwanTime::extractMin() {
    return h.extractMin();
}

food foodPQSpwanTime::peak() {
    return this->h.peak();
}
