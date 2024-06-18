# Robotic Depowdering Github Repo

## Packages
- ```flexiv_ros2```: contains the Flexiv RDK for interfacing with the Flexiv Rizon 4s.
- ```gpd```: Grasp Pose Detection, used to detect where to grasp an object.
- ```robotic_depowdering```: nodes and services used in the depowdering process.
- ```robotic_depowdering_interfaces```: message and service definitions used by ```robotic_depowdering```.

## Setup
```colcon build --symlink-install```

## Running
### Grasp Pose Detection Service
```ros2 run robotic_depowdering gpd_service```
### Pick up object
```ros2 run robotic_depowdering pick_up_object src/robotic_depowdering/test_parts/HollowCube.obj```