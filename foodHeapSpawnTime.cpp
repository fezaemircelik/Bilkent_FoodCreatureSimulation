//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#include "foodHeapSpawnTime.h"

foodHeapSpawnTime::foodHeapSpawnTime() : size(0) {
    heapSize = 0;
    capacity = 500;
    food_p = new food[capacity];
}

bool foodHeapSpawnTime::heapIsEmpty() const {
    return (size == 0);
}

void foodHeapSpawnTime::heapInsert(const food &newItem) {
    if(size >= 500){

    }
    else{
        items[size] = newItem;

        int place = size;
        int parent = (place - 1)/2;
        while((place > 0) && (items[place].getSpawnTime() < items[parent].getSpawnTime())){
            food temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++size;
    }
}

void foodHeapSpawnTime::heapDelete(food &rootItem) {
    if(heapIsEmpty()){
    }
    else{
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void foodHeapSpawnTime::heapRebuild(int root) {
    int child = 2*root + 1;
    if(child < size){
        int rightChild = child + 1;

        if((rightChild < size) && items[rightChild].getSpawnTime() < items[child].getSpawnTime()){
            child = rightChild;
        }

        if(items[root].getSpawnTime() > items[child].getSpawnTime()){
            food temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}

void foodHeapSpawnTime::insertKey(food k) {
    if(heapSize == capacity){

    }
    else{
        heapSize++;
        int i = heapSize - 1;
        food_p[i] = k;

        while(i != 0 && food_p[parent(i)].getSpawnTime() > food_p[i].getSpawnTime()){
            food temp = food_p[parent(i)];
            food_p[parent(i)] = food_p[i];
            food_p[i] = temp;

            i = parent(i);
        }
    }
}

void foodHeapSpawnTime::decreaseKey(int i, food new_val) {
    food_p[i] = new_val;
    while(i != 0 && food_p[parent(i)].getSpawnTime() > food_p[i].getSpawnTime()){
        food temp = food_p[parent(i)];
        food_p[parent(i)] = food_p[i];
        food_p[i] = temp;

        i = parent(i);
    }
}

food foodHeapSpawnTime::extractMin() {
    if(heapSize <= 0){
        return food(INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX);
    }
    if(heapSize == 1){
        heapSize--;
        return food_p[0];
    }

    food root = food_p[0];
    food_p[0] = food_p[heapSize-1];
    heapSize--;
    MinHeapify(0);

    return root;
}

void foodHeapSpawnTime::deleteKey(int i) {
    decreaseKey(i, food(INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN));
    extractMin();
}

void foodHeapSpawnTime::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heapSize &&food_p[l].getSpawnTime() < food_p[i].getSpawnTime()){
        smallest = l;
    }
    if(r < heapSize && food_p[r].getSpawnTime() < food_p[smallest].getSpawnTime()){
        smallest = r;
    }
    if(smallest != i){
        food temp = food_p[i];
        food_p[i] = food_p[smallest];
        food_p[smallest] = temp;
        MinHeapify(smallest);
    }
}

food foodHeapSpawnTime::peak() {
    return items[0];
}
