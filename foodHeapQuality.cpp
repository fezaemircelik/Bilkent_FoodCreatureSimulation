//
// Created by Feza on 4/22/2023.
//
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#include "foodHeapQuality.h"

foodHeapQuality::foodHeapQuality() : size(0) {

}

bool foodHeapQuality::heapIsEmpty() const {
    return (size==0);
}

void foodHeapQuality::heapInsert(const food &newItem) {
    if(size >= 500){

    }
    else{
        this->items[size] = newItem;

        int place = size;
        int parent = (place - 1)/2;
        while((place > 0) && (items[place].getQuality() > items[parent].getQuality())){
            food temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++size;
    }
}

void foodHeapQuality::heapDelete(food &rootItem) {
    if(heapIsEmpty()){

    }else{
        rootItem = items[0];
        items[0] = items[--size];
        heapRebuild(0);
    }
}

void foodHeapQuality::heapRebuild(int root) {
    int child = 2*root + 1;
    if(child < size){
        int rightChild = child + 1;

        if((rightChild < size) && items[rightChild].getQuality() > items[child].getQuality()){
            child = rightChild;
        }
        if(items[root].getQuality() < items[child].getQuality()){
            food temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            heapRebuild(child);
        }
    }
}

food foodHeapQuality::peak() {
    return items[0];
}
