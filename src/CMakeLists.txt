add_library (ConstructionWorker ./main.cpp)
target_include_directories (ConstructionWorker PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}
	)

add_subdirectory (./enum) #done
add_subdirectory (./state) #done
add_subdirectory (./entity) #done
add_subdirectory (./misc) #done
