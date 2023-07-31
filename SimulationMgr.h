//
// Created by Feza on 4/18/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#ifndef HW3_SIMULATIONMGR_H
#define HW3_SIMULATIONMGR_H

#include "creature.h"
#include "food.h"
#include "creature.h"

#include "foodPQQuality.h"
#include "foodPQSpwanTime.h"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class SimulationMgr {
public:
    SimulationMgr();
    ~SimulationMgr();

    void simulation();

    void readTxtFile(string fileName);

    void setCreatureCapacity(int capacity);
    void setHeapSize(int heapSize);
    void MinHeapify_c(int i);
    int parent_c(int i);
    int left_c(int i);
    int right_c(int i);
    creature extractMin_c();
    void decreaseKey_c(int i, creature new_val);
    creature getMin_c();
    void deleteKey_c(int i);
    void insertKey_c(creature k);

    void setCreatureCount(int creature_count);
    int getCreatureCount();
    void setFoodCount(int food_count);
    int getFoodCount();
private:
    creature *creature_p;
    int creature_capacity;
    int creature_heapSize;

    creature* creature_arr;

    int creature_count;
    int food_count;

    foodPQQuality   pq_quality;
    foodPQSpwanTime pq_spawnTime;

    int simTime;
};


#endif //HW3_SIMULATIONMGR_H
