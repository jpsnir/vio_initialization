#include <gtest/gtest.h>
#include <iostream>
#include "imu_initialization.h"
#include "data_utilities.h"
#include <stdexcept>

using namespace std;

TEST(Vector, slice_vector_test ){
    vector<unsigned> v = {0, 1, 2, 3, 4, 5};
    int i = 0, j = 1;
    auto v1 = slice_vector(v, i, j);
    print_vector(v1);

    i = 0, j = 3;
    v1 = slice_vector(v, i, j);
    print_vector(v1);

    i = 0, j = 6;
    try{
        v1 = slice_vector(v, i, j);
        print_vector(v1);
    }
    catch(exception e){
        cout << "Exception occured: " << e.what() << endl;
    }
    
    

}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}