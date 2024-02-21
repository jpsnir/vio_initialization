find_package(GTest REQUIRED)


if(${GTest_FOUND})
    message(STATUS "Gtest found : ${GTest_VERSION}")
endif()


include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/imu_initialization/include"
    ${GTest_INCLUDE_DIRS} 
    ${GTSAM_INCLUDE_DIRS} 
)


add_executable(test_simulation ./test_simulation.cpp)
target_link_libraries(test_simulation GTest::gtest gtsam vio_init)

add_executable(test_data_utils ./test_data_utilities.cpp)
target_link_libraries(test_data_utils GTest::gtest gtsam vio_init)


include(GoogleTest)
