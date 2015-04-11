cmake_minimum_required (VERSION 2.8.9)
project ("AI")

set (PRJ ${PROJECT_SOURCE_DIR})
set (FILELIST ${PRJ}/sources.src)

message (STATUS "PRJ : ${PRJ}")
message (STATUS "FILELIST : ${FILELIST}")

include_directories (
	${PRJ}/src
	)

file (READ ${FILELIST} SRC)
string (REGEX REPLACE "#.*$" "" SRC ${SRC})
string (REGEX REPLACE "\n" ";" SRC ${SRC})

add_executable (${PROJECT_NAME} ${SRC})

foreach (f ${SRC})
	set_source_files_properties (${f} PROPERTIES LANGUAGE CXX)
endforeach(f)
