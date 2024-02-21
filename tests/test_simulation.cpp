#include "simulation.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(run, io_test)
{
    using namespace vio_init;
    // dummy imu params, keeping the scale of
    ImuParams imuParams = {
        .sigma_white_gyro = 0.01,
        .sigma_white_acc = 0.1,
        .sigma_brown_gyro = 0.001,
        .sigma_brown_acc = 0.01,
        .sigmas_pink_acc = {0.05, 0.05},
        .sigmas_pink_gyro = {0.005, 0.005},
    };

    CameraParams camParams = {
        .fx = 50,
        .fy = 50,
        .cx = 50,
        .cy = 50,
        .radial_d =
            {
                0,
                0,
                0,
            },
        .tangential_d = {0, 0},
    };

    VioSimulationParams vioSimParams = {
        .sample_time = 10,
        .cam_fs = 20,
        .imu_fs = 100,
        .imuParams = imuParams,
        .camParams = camParams,
    };

    Waypoints w_pts;
    w_pts.push_back(gtsam::Pose3(gtsam::Rot3(gtsam::Matrix33::Identity()),
                                 gtsam::Point3(0, 0, 0)));

    w_pts.push_back(gtsam::Pose3(gtsam::Rot3(gtsam::Matrix33::Identity()),
                                 gtsam::Point3(1, 0, 0)));

    w_pts.push_back(gtsam::Pose3(gtsam::Rot3(gtsam::Matrix33::Identity()),
                                 gtsam::Point3(2, 0, 0)));

    w_pts.push_back(gtsam::Pose3(gtsam::Rot3(gtsam::Matrix33::Identity()),
                                 gtsam::Point3(3, 0, 0)));
    SimulationVio simVio(w_pts, vioSimParams);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}