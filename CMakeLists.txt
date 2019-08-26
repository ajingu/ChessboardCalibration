cmake_minimum_required(VERSION 3.0)
project(chessboard-calibration)

if(NOT DEFINED OpenCV_DIR)
    message(FATAL_ERROR "set OpenCV_DIR")
endif()

# OpenCV
find_package(OpenCV REQUIRED)

# header & source
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
file(GLOB CORE_SOURCES src/*.cpp)

# library
set(DEPENDENCY ${OpenCV_LIBS})

add_library(CORE STATIC ${CORE_SOURCES})
target_link_libraries(CORE ${DEPENDENCY})

# executable
add_executable(main_photo main_photo.cpp)
target_link_libraries(main_photo CORE ${DEPENDENCY})

add_executable(main_calibration main_calibration.cpp)
target_link_libraries(main_calibration CORE ${DEPENDENCY})