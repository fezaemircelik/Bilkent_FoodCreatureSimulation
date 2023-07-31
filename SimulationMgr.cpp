//
// Created by Feza on 4/18/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/

#include "SimulationMgr.h"
#include <cmath>

void SimulationMgr::readTxtFile(string fileName) {
    ifstream filein(fileName);
    int creature_count;
    this->food_count = 0;
    this->simTime = 0;
    if(filein.is_open()){

        ///add the creatures
        filein >> creature_count;

        setCreatureCapacity(creature_count);
        setHeapSize(0);
        this->creature_p = new creature[creature_count];
        this->creature_arr = new creature[creature_count];

        for(int i = 0; i < creature_count; i++){
            int id_NewCreature;
            double x_NewCreature;
            double y_NewCreature;
            int health_NewCreature;

            char comma;

            filein >> id_NewCreature >> comma >> x_NewCreature >> comma >> y_NewCreature >> comma >> health_NewCreature;

            creature newCreature = creature(id_NewCreature,x_NewCreature,y_NewCreature,health_NewCreature);
            newCreature.setName(i+1);

            this->creature_arr[i] = newCreature;
            this->insertKey_c(newCreature);

            this->creature_count++;
        }

        ///add the foods
        int foodID, foodX, foodY, foodQuality, spawnTime;
        char comma;

        while(filein >> foodID >> comma >> foodX >> comma >> foodY >> comma >> foodQuality >> comma >> spawnTime){
            food newFood = food(foodID, foodX, foodY, foodQuality, spawnTime);
            pq_quality.pqInsert(newFood);
            pq_spawnTime.pqInsert(newFood);
            this->food_count++;
        }
    }
    else{}
}

void SimulationMgr::setCreatureCount(int creature_count) {
    this->creature_count = creature_count;
}
int SimulationMgr::getCreatureCount() {
    return this->creature_count;
}
void SimulationMgr::setFoodCount(int food_count) {
    this->food_count = food_count;
}
int SimulationMgr::getFoodCount() {
    return this->food_count;
}
void SimulationMgr::setCreatureCapacity(int capacity) {
    this->creature_capacity = capacity;
}
void SimulationMgr::setHeapSize(int heapSize) {
    this->creature_heapSize = heapSize;
}

int SimulationMgr::parent_c(int i) {
    return (i-1)/2;
}
int SimulationMgr::left_c(int i) {
    return (2*i + 1);
}
int SimulationMgr::right_c(int i) {
    return (2*i + 2);
}
void SimulationMgr::insertKey_c(creature k) {
    if(this->creature_heapSize == this->creature_capacity){
        cout << "COULD NOT INSERT KEY!!!" << endl;
    }
    else{
        //this will insert the new key to the end
        this->creature_heapSize++;
        int i = this->creature_heapSize - 1;
        creature_p[i] = k;

        //this will fix minHeap
        while(i != 0 && creature_p[parent_c(i)].getID() > creature_p[i].getID()){
            creature temp = creature_p[i];
            creature_p[i] = creature_p[parent_c(i)];
            creature_p[parent_c(i)] = temp;
            i = parent_c(i);
        }
    }
}
void SimulationMgr::deleteKey_c(int i) {
    decreaseKey_c(i, creature(INT_MIN,INT_MIN,INT_MIN,INT_MIN));
    extractMin_c();
}
creature SimulationMgr::extractMin_c() {
    if(creature_heapSize <= 0){
        return creature(INT_MAX,INT_MAX,INT_MAX,INT_MAX);
    }
    if(creature_heapSize == 1){
        this->creature_heapSize--;
        return creature_p[0];
    }

    creature root = creature_p[0];
    creature_p[0] = creature_p[this->creature_heapSize-1];
    this->creature_heapSize--;
    MinHeapify_c(0);

    return root;
}
void SimulationMgr::decreaseKey_c(int i, creature new_val) {
    creature_p[i] = new_val;
    while(i != 0 && creature_p[parent_c(i)].getID() > creature_p[i].getID()){
        creature temp = creature_p[i];
        creature_p[i] = creature_p[parent_c(i)];
        creature_p[parent_c(i)] = temp;
        i = parent_c(i);
    }
}
void SimulationMgr::MinHeapify_c(int i) {
    int l = left_c(i);
    int r = right_c(i);
    int smallest = i;
    if(l < creature_heapSize && creature_p[l].getID() < creature_p[i].getID()){
        smallest = l;
    }
    if(r < creature_heapSize && creature_p[r].getID() < creature_p[smallest].getID()){
        smallest = r;
    }
    if(smallest != i){
        creature temp = creature_p[i];
        creature_p[i] = creature_p[parent_c(i)];
        creature_p[parent_c(i)] = temp;
        MinHeapify_c(smallest);
    }
}
creature SimulationMgr::getMin_c() {
    return creature_p[0];
}

SimulationMgr::SimulationMgr() {

}
SimulationMgr::~SimulationMgr() {

}

void SimulationMgr::simulation() {
    bool allDie = false;
    int currentTime = 0;

    foodPQQuality currentFoods;

    while(!allDie){
        /// 1. Current locations of all creatures should be printed.
        for(int i = 0; i < this->creature_count;i++){
            cout << creature_arr[i].getName() << ": " << creature_arr[i].getX() << ", " << creature_arr[i].getY() << endl;
        }

        /// 2. New food resources should be added (if any)
        while ((currentTime >= pq_spawnTime.peak().getSpawnTime()) && (pq_spawnTime.peak().getSpawnTime() >= 0)) {
            currentFoods.pqInsert(pq_spawnTime.peak());
            pq_spawnTime.pqDelete(pq_spawnTime.peak()); //priorityitem ile oynadım bozulmuş olabilir
        }

        ///3. Fights between creatures should be resoulved (if any)
        for(int i = 0; i < this->creature_count; i++){
            if(creature_p[i].getHealth()>0){
                double firstX = creature_p[i].getX();
                double firstY = creature_p[i].getY();
                for(int j = 0; j < this->creature_count; j++){
                    if(i == j){

                    }
                    else{
                        double secondX = creature_p[j].getX();
                        double secondY = creature_p[j].getY();

                        double differenceX = firstX - secondX;
                        double differenceY = firstY - secondY;

                        double sqX = pow(differenceX, 2);
                        double sqY = pow(differenceY, 2);

                        double distance = sqrt((sqX + sqY));

                        if((distance < 2)&&(creature_p[i].getHealth()>=creature_p[j].getHealth())){
                            //kill j
                            creature_p[j].setHealth(0);
                        }
                    }
                }
            }
        }

        /// 4. Creatures should consume the best food if it is nearby
        for(int i = 0; i < creature_count; i++){
            if(creature_p[i].getHealth() > 0){
                food targetFood = currentFoods.peak();

                double differenceX = creature_p[i].getX() - targetFood.getX();
                double differenceY = creature_p[i].getY() - targetFood.getY();

                double sqX = pow(differenceX, 2);
                double sqY = pow(differenceY, 2);

                double distance = sqrt((differenceX + differenceY));

                if((distance < 1)){
                    creature_p[i].setHealth(creature_p[i].getHealth() + targetFood.getQuality());
                    currentFoods.pqDelete(*currentFoods.peak());   //priorityitem ile oynadım bozulmuş olabilir
                }
            }
        }

        /// 5. Health of each creature should decrease by 1
        for(int i = 0; i < creature_count; i++){
            creature_p[i].setHealth(creature_p->getHealth()-1);
        }

        /// 6. MOVE
        for(int i = 0; i < creature_count; i++){
            if(creature_p[i].getHealth() > 0){
                double speed = 10.00/creature_p[i].getHealth();
                double slope = (pq_quality.peak().getY() - creature_p[i].getY()) / (pq_quality.peak().getX() - creature_p[i].getX());

                double destX = creature_p[i].getX() + (speed / sqrt(1 + pow(slope,2)));
                double destY = creature_p[i].getY() + (slope * (speed / sqrt(1 + pow(slope,2))));


                creature_p[i].setX(destX);
                creature_p[i].setY(destY);
            }
        }

        allDie = true;
        for(int i = 0; i < this->creature_count; i++){
            if(creature_p[i].getHealth() > 0){
                allDie = false;
            }
        }
        currentTime++;
    }
}

