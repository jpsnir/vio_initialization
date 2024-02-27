cmake_minimum_required(VERSION 3.0)
project(vio_initialization)
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/imu_initialization/cmake_modules")
# gtsam based code
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(GTSAM_DIR "/home/jagatpreet/software/gtsam/install_4_1/lib/cmake/GTSAM")
set(GTSAM_UNSTALBE_DIR
    "/home/jagatpreet/software/gtsam/install_4_1/lib/cmake/GTSAM_UNSTABLE")

find_package(GTSAM REQUIRED PATHS ${GTSAM_DIR} NO_DEFAULT_PATH)
find_package(GTSAM_UNSTABLE REQUIRED PATHS ${GTSAM_UNSTALBE_DIR} NO_DEFAULT_PATH)
find_package(Eigen3 REQUIRED)
find_package(Gflags REQUIRED)
find_package(Glog REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)

if(${GTSAM_FOUND})
    message(STATUS "GTSAM library found at ${GTSAM_DIR}")
    message(STATUS "gtsam found : ${GTSAM_VERSION_STRING}")
endif()

# ceres based code
include_directories(
    "${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/src/*.cpp")

# this is using ceres.
add_subdirectory(imu_initialization)

message(STATUS "Project sources are : ${sources}}")
include_directories(
    ${Boost_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR} ${GFLAGS_INCLUDE_DIR} ${GLOG_INCLUDE_DIRS}
)

### PORTED TO GTSAM
# library for vio initialization using gtsam as a solver.
add_library(vio_init ${sources})
target_link_libraries(vio_init gtsam)

# tests for gtsam code
add_subdirectory(tests)
