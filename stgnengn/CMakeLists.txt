cmake_minimum_required (VERSION 3.8)
project (stgnengn  LANGUAGES CXX)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_library (stgnengn STATIC ${SOURCES} ${HEADERS})
