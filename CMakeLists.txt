
cmake_minimum_required (VERSION 2.8)

project (ep1)
include_directories (src)

add_executable(main 
	src/main.cxx)

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")