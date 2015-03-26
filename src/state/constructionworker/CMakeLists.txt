add_library (ConstructionWorkerState ./ConstructionWorkerStates.cpp)

target_include_directories (ConstructionWorker PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	)
