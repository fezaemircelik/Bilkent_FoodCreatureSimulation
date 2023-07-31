//
// Created by Feza on 4/18/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#include "food.h"

void food::setID(int id) {
    this->id = id;
}

int food::getID() {
    return this->id;
}

void food::setX(double x) {
    this->x = x;
}

double food::getX() {
    return this->x;
}

void food::setY(double y) {
    this->y = y;
}

double food::getY() {
    return this->y;
}

void food::setQuality(int quality) {
    this->quality = quality;
}

int food::getQuality() {
    return this->quality;
}

food::food() {
    spawnTime = -1;
}

food::food(int id, double x, double y, int quality, int spawnTime) {
    setID(id);
    setX(x);
    setY(y);
    setQuality(quality);
    this->spawnTime = spawnTime;
}

void food::setSpawnTime(int spawnTime) {
    this->spawnTime = spawnTime;
}

int food::getSpawnTime() {
    return this->spawnTime;
}
