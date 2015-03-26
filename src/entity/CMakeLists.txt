add_library (Entity ./BaseGameEntity.cpp)

target_include_directories (Entity PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory (./constructionworker)
