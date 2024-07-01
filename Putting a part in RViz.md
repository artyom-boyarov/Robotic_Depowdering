1. Open RViz through one of the launch bringups
2. Add a marker display (add -> marker)
3. Configure the topic of the marker to /visualization_marker
4. Convert STL to binary STL from ascii
5. Publish a message to /visualization_marker in the format of:
type = 10
action = 0
pose/position: 0.25, 0.25, 0
header/frame_id: 'base_link'
color/a = 1.0
scale = 0.001, 0.001, 0.001 (stls are in m)
mesh_resource: "package://robotic_depowdering/test_parts/Buckle.bin.stl"