#include <vector>
#include <gtsam/3rdparty/Eigen/Eigen/Dense>
#include <gtsam/geometry/Point3.h>
#include <gtsam/geometry/Pose3.h>
#include <gtsam/inference/Key.h>

#include <gtsam/nonlinear/NonlinearFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/navigation/ImuFactor.h>

struct VioInitData
{
    uint64_t t1, t2;
    gtsam::Pose3 p1, p2;
    gtsam::PreintegratedImuMeasurements pIntImu;

    VioInitData(pair<uint64_t, uint64_t> times, pair<gtsam::Pose3, gtsam::Pose3> poses, gtsam::PreintegratedImuMeasurements &pIntImu);

};
struct VioInitSolution{
    
    // in IMU frame
    Eigen::Vector3f acc_bias_i_;
    Eigen::Vector3f gyro_bias_i;
    // in world frame
    Eigen::Vector3f gravity_W;
    std::vector<Eigen::Vector3f> v_velocities_W_;
    gtsam::Pose3 p_i_T_c;  // transformation of camera to IMU.
    gtsam::Pose3 p_wg_T_i; // gravity aligned world frame.
    float scale_;
};

class ImuInitializer
{
public:
    ImuInitializer();

    // solve a bundle adjustment problem to get initial values
    void initialize_scale();
    void initialize_accelerometer_bias();
    void initialize_gyroscopic_bias();

    // solve a joint bundle adjustment problem
    // to optimize all variables
    void optimize_all();

    // data functions and visualization
    void load_data();
    void save_output();
    void plot_results();
    void simulate_data();

private:
    // IMU measurements in IMU frame
    std::vector<Eigen::VectorXf> v_acc_i_;
    std::vector<Eigen::VectorXf> v_gyro_i_;
    // camera poses wrt to camera world frame
    std::vector<gtsam::Pose3> v_mono_cam_poses_;
    std::vector<gtsam::Pose3> v_stereo_cam_poses_;

    // input data for initialization problem - a factor graph problem

    std::vector<VioInitData> v_input_data;
    VioInitSolution vioInitSolution;
    gtsam::NonlinearFactorGraph fg_gyro_bias;
    gtsam::NonlinearFactorGraph fg_acc_bias;
    gtsam::NonlinearFactorGraph fg_scale_bias;
    gtsam::NonlinearFactorGraph fg_optimize_all;

    /*
    In gtsam, the factor graph
    */
};