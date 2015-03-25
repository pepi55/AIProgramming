cmake_minimum_required (VERSION 2.6)
project ("Construction Worker" CXX)
add_executable (ConstructionWorker ./src/main.cpp ./src/entity/BaseGameEntity.cpp ./src/entity/constructionworker/ConstructionWorker.cpp ./src/state/constructionworker/ConstructionWorkerStates.cpp)
