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
Install dependencies for the Flexiv ROS2 packages:
```
sudo apt install -y \
python3-colcon-common-extensions \
python3-rosdep2 \
libeigen3-dev \
ros-humble-xacro \
ros-humble-tinyxml2-vendor \
ros-humble-ros2-control \
ros-humble-realtime-tools \
ros-humble-control-toolbox \
ros-humble-moveit \
ros-humble-ros2-controllers \
ros-humble-test-msgs \
ros-humble-joint-state-publisher \
ros-humble-joint-state-publisher-gui \
ros-humble-robot-state-publisher \
ros-humble-rviz2
```
First, build gpd:<br>
```
colcon build --symlink-install --packages-select gpd
```
Then build the flexiv rdk:
```
cd src/flexiv_ros2/flexiv_hardware/rdk
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=<where you cloned this repo>/install/flexiv_rdk
make
sudo make install
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
#### With real robot
Connect robot and power it on. Test connection:
```
ping 192.168.2.100
```
Find your IP address: (look for ```inet``` under ```eth0```):
```
ifconfig
```
In one terminal run:<br>
```
ros2 launch flexiv_bringup rizon_with_object_pickup.launch.py robot_ip:=192.167.2.100 local_ip:=[your IP]
```
In another terminal run:<br>
```
ros2 launch robotic_depowdering robotic_depowdering.launch.py test_object:=Buckle.obj test_object_x_pos:=0.5 test_object_y_pos:=0.5 test_object_z_pos:=1.0
```
Replace Buckle.obj with the name of the part you want to use, and the positions with the position of where the part is located.
<br>
More in-depth instructions are located at <a> https://docs.google.com/document/d/1rZFnRo6KGYT_emA9AcjmK8JNeBhtwec6_ygwI96AM5s/edit?usp=sharing </a>.
#### Without robot (just simulation)
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
- All test parts are in `src/robotic_depowdering/test_parts`. The obj, stl and binary stl are provided.
- The parts are centered at (0,0,0) in the CAD files - if you place the part at a different location while testing, you pass this location into ```robotic_depowdering.launch.py``` by adjusting the ``` test_object_x_pos```, ```test_object_y_pos```, and ```test_object_z_pos``` parameters, instead of modifying the CAD file.
  - Keep in mind, the Rizon's base plate is 15mm thick. So if you place parts on the ground, and the rizon is on the base plate mounted on the ground, your part's z-coordinate is -0.015.
- The dimensions of the part are in metres. If you want to 3D print a part, then CURA will automatically scale the part up to mm.
