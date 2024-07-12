# Rizon_pick_and_place

Motion planning for Flexiv Rizon 4s using Moveit 2

## Installation

Install submodules 

```bash
git submodule update --init --recursive
```

## Usage
Launch the motion planning RViz:
```bash
ros2 launch rizon_pick_and_place rizon_pick_and_place.launch.py robot_ip:=dont-care local_ip:=dont-care use_fake_hardware:=true
```
Select 'Panels' in the top ribbons. Then select `RvizVisualToolsGui` and click OK. This will create a new panel on the bottom left with a `Next` button we’ll use later.
Input the target pose:
```bash
ros2 run rizon_pick_and_place move_to_pose_client x y z qx qy qz qw
```
`x`, `y`, and `z` is the target coordinate. The `qx`, `qy`, `qz`, and `qw` parameters represent the components of a quaternion, which is used to describe the orientation of the robot's end effector in 3D space.

Click `Next` at the bottom left corner when prompted. The robot will then start planning. When done, click `Next` again when prompted, and the robot will start executing.


