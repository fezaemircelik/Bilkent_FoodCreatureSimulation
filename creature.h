//
// Created by Feza on 4/18/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#ifndef HW3_CREATURE_H
#define HW3_CREATURE_H

#include <iostream>
#include <fstream>
using namespace std;

class creature {
public:
    creature();
    creature(int id, double x, double y, int health);

    void setName(int count);
    string getName();

    void setID(int id);
    int getID();
    void setX(double x);
    double getX();
    void setY(double y);
    double getY();
    void setHealth(int health);
    int getHealth();
private:
    int id;
    double x;
    double y;
    int health;

    string name;
};


#endif //HW3_CREATURE_H
