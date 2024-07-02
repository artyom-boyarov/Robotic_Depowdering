# Robotic Depowdering Github Repo

## Packages
- ```flexiv_ros2```: contains the Flexiv RDK for interfacing with the Flexiv Rizon 4s.
- ```gpd```: Grasp Pose Detection, used to detect where to grasp an object.
- ```robotic_depowdering```: nodes and services used in the depowdering process.
- ```robotic_depowdering_interfaces```: message and service definitions used by ```robotic_depowdering```.

## Setup
Source ROS underlay: <br>
```
source /opt/ros/humble/setup.sh
```
Install dependencies (from packages + pcl_tools):<br>
```
rosdep install --from-paths src --ignore-src -r -y
sudo apt install pcl-tools -y
```
First, build gpd:<br>
```
colcon build --symlink-install --packages-select gpd
```
Then build everything else: <br>
```
colcon build --symlink-install
```
In any terminal where you run code, do: <br>
```
source /opt/ros/humble/setup.sh
source install/setup.sh
```
## Additional dependencies
Also install ```pcl-tools``` : <br>
```sudo apt install pcl-tools```
## Running
### Pick up object + visualization
In one terminal run:<br>
```
ros2 launch flexiv_bringup rizon_with_object_pickup.launch.py robot_ip:=dont-care local_ip:=dont-care use_fake_hardware:=true
```
In another terminal run:<br>
```
ros2 launch robotic_depowdering robotic_depowdering.launch.py test_object:=Buckle.obj test_object_x_pos:=0.5 test_object_y_pos:=0.5 test_object_z_pos:=1.0
```
Replace Buckle.obj with the name of the part you want to use, and the positions with the position of where the part is located.
### Test parts
All test parts are in `src/robotic_depowdering/test_parts`. The obj, stl and binary stl are provided. The parts are centered at (0,0,0) in the CAD files - if you place the part at a different location while testing, you pass this location into ```robotic_depowdering.launch.py``` by adjusting the ``` test_object_x_pos```, ```test_object_y_pos```, and ```test_object_z_pos``` parameters, instead of modifying the CAD file.<br> The dimensions of the part are in metres. If you want to 3D print a part, then CURA will automatically scale the part up to mm. Don't export the part from CURA, as this is unnecessary.
