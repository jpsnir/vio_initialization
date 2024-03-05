#!/bin/bash

droid_results_folder="/home/${USER}/workspaces/NEUFR/vins/vio_initialization/evo"
output_folder="/home/${USER}/workspaces/NEUFR/vins/vio_initialization/data"
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

for seq in ${sequences[@]}; do
    echo "Copying ${seq}"

    echo "Copy Mono trajectory"
    cp "$droid_results_folder/${seq}/mono/lba/T_wc_ip_s_lba.txt"\
    "$output_folder/${seq}/DroidKeyFrameTrajectoryMono.txt"

    echo "Copy stereo trajectory"
    cp "$droid_results_folder/${seq}/stereo/lba/T_wc_ip_s_lba.txt"\
    "$output_folder/${seq}/DroidKeyFrameTrajectoryStereo.txt"


    echo "Droid frame trajectory expressed in TUM format, T_wc - camera to world
    frame " > "$output_folder/$seq/readme.txt"
    sleep 0.1
done
