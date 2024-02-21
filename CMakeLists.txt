cmake_minimum_required(VERSION 3.0)
# gtsam based code
set(GTSAM_DIR "/home/jagatpreet/software/gtsam/install_4_1/lib/cmake/GTSAM")
set(GTSAM_UNSTALBE_DIR
    "/home/jagatpreet/software/gtsam/install_4_1/lib/cmake/GTSAM_UNSTABLE")
find_package(GTSAM REQUIRED PATHS ${GTSAM_DIR} NO_DEFAULT_PATH)
find_package(GTSAM_UNSTABLE REQUIRED PATHS ${GTSAM_UNSTALBE_DIR} NO_DEFAULT_PATH)
if(${GTSAM_FOUND})
    message(STATUS "GTSAM library found at ${GTSAM_DIR}")
    message(STATUS "gtsam found : ${GTSAM_VERSION_STRING}")
endif()

# ceres based code
include_directories(
    "${PROJECT_SOURCE_DIR}/include")
file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_subdirectory(imu_initialization)




message(STATUS "Project sources are : ${sources}}")
include_directories(
    ${GTSAM_INCLUDE_DIRS}
)
add_library(vio_init ${sources})
target_link_libraries(vio_init gtsam)

# tests
add_subdirectory(tests)




