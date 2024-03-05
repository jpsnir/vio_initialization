#!/bin/bash

if [ "$#" -ne "1" ]; then
    echo "Usage: ./process_data.sh <folder_name>"
    exit 1
fi


input_dir=$1
dataset_name=$(basename ${input_dir})
echo "Dataset name : $dataset_name"
read -p "Enter to continue"
declare -A files_dict
files_dict["mono"]="DroidKeyFrameTrajectoryMono.txt"
files_dict["stereo"]="DroidKeyFrameTrajectoryStereo.txt"

# gap time - max time between keyframes (in seconds)
# step size: distance between two keyframes (we have interpolated the droid slam
# trajectory to 20hz camera rate, by keeping the step size to 4, we
# are making it 5 hz keyframe rate for trajectory evaluation"
# nframes : number of keyframes for solving the

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
    mkdir -p ./exp2_results/${k}
    mv -r ./build/imu_initialization/*.csv ./exp2_results/${k}/
done
