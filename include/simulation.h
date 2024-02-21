#include <Eigen/Dense>
#include <iostream>
#include <gtsam/geometry/Point3.h>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/navigation/ScenarioRunner.h>
#include <gtsam/navigation/Scenario.h>
#include <gtsam/geometry/Cal3_S2.h>
#include <gtsam/geometry/PinholeCamera.h>

/* 1. We will generate camera and IMU measurements from ground truth using splines.
 */

namespace vio_init
{
    typedef std::vector<gtsam::Pose3> Waypoints;

    struct ImuParams
    {
        double sigma_white_gyro;
        double sigma_white_acc;
        double sigma_brown_gyro;
        double sigma_brown_acc;
        std::pair<double, double> sigmas_pink_acc;
        std::pair<double, double> sigmas_pink_gyro;
    };

    struct CameraParams
    {
        double fx, fy;
        double cx, cy;
        vector<double> radial_d;
        vector<double> tangential_d;
    };

    struct VioSimulationParams
    {
        int sample_time = 10;
        int cam_fs = 20;
        int imu_fs = 100;
        ImuParams imuParams;
        CameraParams camParams;
    };

    

    class SimulationVio
    {
    public:
        SimulationVio(const Waypoints &w_pts, const VioSimulationParams &simParams);
        void generate_groundtruth();
        void generate_camera_poses();
        void generate_imu_poses();
        void simulate();
        static Waypoints generate_spiral_waypoints();

    private:
    };
};
