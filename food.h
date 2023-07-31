//
// Created by Feza on 4/18/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#ifndef HW3_FOOD_H
#define HW3_FOOD_H

#include <iostream>
#include <fstream>
using namespace std;

class food {
public:
    food();
    food(int id, double x, double y, int quality, int spawnTime);

    void setID(int id);
    int getID();
    void setX(double x);
    double getX();
    void setY(double y);
    double getY();
    void setQuality(int quality);
    int getQuality();

    void setSpawnTime(int spawnTime);
    int getSpawnTime();
private:
    double x;
    double y;
    int id;
    int quality;

    int spawnTime;
};


#endif //HW3_FOOD_H
