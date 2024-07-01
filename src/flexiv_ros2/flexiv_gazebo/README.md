# Flexiv Rizon 4S in Gazebo

Flexiv Rizon 4S simulation in Gazebo (Gazebo classic) with ros-gz.


## Getting Started
1. Install [ROS 2 Humble via Debian Packages](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debians.html)

2. Install `colcon` and additional ROS packages:

   ```bash
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

3. Setup workspace:

   ```bash
   mkdir -p ~/flexiv_ros2_ws/src
   cd ~/flexiv_ros2_ws/src
   git clone https://github.com/flexivrobotics/flexiv_ros2.git
   cd flexiv_ros2/
   git submodule update --init --recursive
   ```

4. Install dependencies:

   ```bash
   cd ~/flexiv_ros2_ws
   rosdep update
   rosdep install --from-paths src --ignore-src --rosdistro humble -r -y
   ```

5. Build and source the workspace:

   ```bash
   cd ~/flexiv_ros2_ws
   source /opt/ros/humble/setup.bash
   colcon build --symlink-install
   source install/setup.bash
   ```

> [!NOTE]
> Remember to source the setup file and the workspace whenever a new terminal is opened:
> ```bash
> source /opt/ros/humble/setup.bash
> source ~/flexiv_ros2_ws/install/setup.bash
> ```

### Executing program
-Export the environmental variable to the correct path (make sure you are in the base directory of this repo)
```
export GZ_SIM_RESOURCE_PATH=$(pwd)/install/flexiv_description/share
```
-To start the robot in Gazebo:
```
ros2 launch flexiv_gazebo rizon_bringup_gazebo.launch.py robot_ip:=dont-care local_ip:=dont-care use_fake_hardware:=true
```
-Everytime anything is changed, make sure to run:
```
colcon build
```
under root directory.

### Troubleshooting
-If gazebo hangs at "Requesting list of world names. The server may be busy downloading resources. Please be patient.", enable multicast by following the instructions [here](https://docs.ros.org/en/humble/How-To-Guides/Installation-Troubleshooting.html)
