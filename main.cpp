#include <iostream>
/**
* Author : Feza Emir Çelik
* ID: 22101910
* Section : 1
* Homework : 3
*/
#include "SimulationMgr.h"

using namespace std;
#include <iostream>
#include <fstream>

int main() {
    SimulationMgr f;
    f.readTxtFile("data.txt");
    f.simulation();
    return 0;
}
