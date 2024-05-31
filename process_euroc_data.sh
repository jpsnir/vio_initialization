#!/bin/bash

if [ "$#" -ne "1" ]; then
    echo "Usage: ./process_data.sh <data_folder>"
    exit 1
fi

sequences=(
    MH_01_easy
    MH_02_easy
    MH_03_medium
    MH_04_difficult
    MH_05_difficult
    V1_01_easy
    V1_02_medium
    V1_03_difficult
    V2_01_easy
    V2_02_medium
    V2_03_difficult
)


output_dir="./exp2_results"
declare -A files_dict
files_dict["mono"]="DroidKeyFrameTrajectoryMono.txt"
files_dict["stereo"]="DroidKeyFrameTrajectoryStereo.txt"

# gap time - max time between keyframes (in seconds)
# step size: distance between two keyframes (we have interpolated the droid slam
# trajectory to 20hz camera rate, by keeping the step size to 4, we
# are making it 5 hz keyframe rate for trajectory evaluation"
# nframes : number of keyframes for solving the

for dataset_name in ${sequences[@]}; do
    echo "Processing : dataset name : ${dataset_name}"
    sleep 2
    input_dir=$1/${dataset_name}
    for k in ${!files_dict[@]}; do
        echo "Camera type : ${k} - filename : ${files_dict[$k]}"
        echo " Processing data"
        f=${files_dict[$k]}
        ./build/imu_initialization/experiment02\
        ${input_dir}\
        --nframes 5\
        --gap_time 1\
        --camera_step_size 4\
        --filename ${f}
        wait
        mkdir -p ${output_dir}/${dataset_name}/${k}
        mv  *.csv ${output_dir}/${dataset_name}/${k}/
    done
done
