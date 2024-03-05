#VIO initialization
The repository contains code another submodule which has been modified to
generate and save the following parameters :
- scale of monocular trajectory
- gravity estimate
- biases of accelerometer
- biases of gyroscope
- velocity of body.


## Bash scripts

1. `copy_data.sh` -> copies the droid slam trajectory data to the relevant folders
   in `/data/<sequence_name>`
2. `process_data.sh` -> processes each sequence `/data/<sequence_name>` and saves
   it in `<project_folder>/exp2_results/<sequence_name>`

__NOTE__: There are some parameters that are being fixed in the
`process_data.sh` script. Please check the [Running
the exceutables](#running_the_executables) section.


## Build instructions
### Dependencies
###

## Note these things your data before processing the data

### Some definitions of transformation frames.

- add figure.

## Running the executables

Flags :

## Output format of files


These are the parameters required for initialization.

The iterative methods are generally applicable as they solve a bundle adjustment
problem.

## Contributions
