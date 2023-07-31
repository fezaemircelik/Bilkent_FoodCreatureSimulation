//
// Created by Feza on 4/18/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#include "creature.h"

void creature::setID(int id) {
    this->id = id;
}

int creature::getID() {
    return this->id;
}

void creature::setX(double x) {
    this->x = x;
}

double creature::getX() {
    return this->x;
}

void creature::setY(double y) {
    this->y = y;
}

double creature::getY() {
    return this->y;
}

void creature::setHealth(int health) {
    this->health = health;
}

int creature::getHealth() {
    return this->health;
}

creature::creature(int id, double x, double y, int health) {
    this->id = id;
    this->x = x;
    this-> y = y;
    this->health = health;
}

void creature::setName(int count) {
    this->name = "Creature " + to_string(count);
}

creature::creature() {

}

string creature::getName() {
    return this->name;
}
