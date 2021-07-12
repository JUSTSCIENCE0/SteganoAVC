cmake_minimum_required(VERSION 3.20.1)
project("SteganoAVC" LANGUAGES C CXX)

set( LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin )
set( EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin )

add_subdirectory(stgnengn)
add_subdirectory(stgnavc)