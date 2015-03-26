add_library (ConstructionWorker ./main.cpp)
target_include_directories (ConstructionWorker PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	)

add_subdirectory (./enum)
add_subdirectory (./state)
add_subdirectory (./entity)
add_subdirectory (./misc)
