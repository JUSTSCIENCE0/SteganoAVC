cmake_minimum_required(VERSION 3.20.1)
project (stgnavc LANGUAGES CXX)

find_package(PkgConfig)

pkg_check_modules(GST REQUIRED gstreamer-1.0>=1.4
                               gstreamer-sdp-1.0>=1.4
                               gstreamer-video-1.0>=1.4
                               gstreamer-app-1.0>=1.4)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")

add_library(stgnavc SHARED ${SOURCES} ${HEADERS})
target_include_directories(stgnavc PUBLIC ${GST_INCLUDE_DIRS})
target_link_libraries(stgnavc PUBLIC ${GST_LINK_LIBRARIES})
target_compile_options(stgnavc PUBLIC ${GST_CFLAGS})