cmake_minimum_required (VERSION 2.6 FATAL_ERROR)
project ("Construction Worker" CXX)

set (ConstructionWorker_VERSION_MAJOR 0)
set (ConstructionWorker_VERSION_MINOR 1)

set (PROJECT_SRCS ./src/main.cpp
	./src/entity/BaseGameEntity.cpp
	./src/entity/constructionworker/ConstructionWorker.cpp
	./src/state/constructionworker/ConstructionWorkerStates.cpp
	)

include_directories (./src)

add_executable (ConstructionWorker ${PROJECT_SRCS})
