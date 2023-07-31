cmake_minimum_required(VERSION 3.23)
project(hw3)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw3 main.cpp food.cpp food.h creature.cpp creature.h SimulationMgr.cpp SimulationMgr.h foodHeapQuality.cpp foodHeapQuality.h foodPQQuality.cpp foodPQQuality.h foodHeapSpawnTime.cpp foodHeapSpawnTime.h foodPQSpwanTime.cpp foodPQSpwanTime.h)
