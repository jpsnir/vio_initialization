#include "io.h"
#include <gtest/gtest.h>
#include <string>
#include <filesystem>
#include <boost/filesystem.hpp>
#include <iostream>
#include <glog/logging.h>
#include <vector>
#include "data_utilities.h"

using namespace std;

TEST(IO, gt_trajectory_format_test){
    int i = 200, j = 202;
    boost::filesystem::path filepath =  "./../imu_initialization/data/MH_01_easy/state_groundtruth_estimate0/data.csv";
    cout << filepath.string() << endl;
    cout << filepath.filename().string() << endl;
    CHECK(boost::filesystem::is_regular_file(filepath))<< " Path does not exist " ;
    using Groundtruth = std::vector<io::state_t>;
    vector<io::state_t> gt = io::read_file<io::state_t>(filepath.string());
    cout << gt.size() << endl;
    cout << "********* state with ostream operator ***********" << endl;
    print_state_vector<io::state_t>(gt, i, j);

    cout << "********* gt pose stored input only 1st element ***********" << endl;
    cout << "t, \t, tx, \t, ty,\t, tz,\t, qw,\t, qx,\t, qy,\t, qz" << endl;
    cout << gt[i].timestamp 
         << "," << gt[i].pose.tx 
         << "," << gt[i].pose.ty
         << "," << gt[i].pose.tz
         << "," << gt[i].pose.qw 
         << "," << gt[i].pose.qx
         << "," << gt[i].pose.qy
         << "," << gt[i].pose.qz << endl;
    cout << "********* file raw input stored input ***********" << endl;
    std::ifstream reader(filepath.string());
    int counter = 0;
    for(std::string line; std::getline(reader, line); ){
        if (counter > j+1)
            break;
        if(counter >= i+1 && counter <= j+1){
            cout << line << endl;
        }
        counter++;
            
    }

}

TEST(IO, camera_trajectory_format_test){

}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}