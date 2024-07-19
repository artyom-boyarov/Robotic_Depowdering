#include <rclcpp/rclcpp.hpp>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include "hpp/fcl/math/transform.h"
#include "hpp/fcl/mesh_loader/loader.h"
#include "hpp/fcl/BVH/BVH_model.h"
#include "hpp/fcl/collision.h"
#include "hpp/fcl/collision_data.h"
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <numbers>

std::shared_ptr<rclcpp::Node> this_node;

double randr() {
    const double MIN = -10.0;
    const double MAX = 10.0;
    return (((double)rand()) / RAND_MAX) + MIN;
};

struct loop_part {
    std::string part_file_name; // Name of the part
    hpp::fcl::Transform3f transform; // Transform
    std::shared_ptr<hpp::fcl::ConvexBase> shape = nullptr;
};

visualization_msgs::msg::Marker generate_part_marker_msg(const loop_part& part, const int id) {
    const std::string PART_RES_DIR = "package://robotic_depowdering/test_parts/";
    visualization_msgs::msg::Marker marker;
    marker.header.frame_id = "base_link";
    marker.header.stamp = rclcpp::Time();
    marker.id = id;
    marker.type = 10;
    marker.action = 0;
    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;
    marker.color.r = 1.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 0.4f;
    marker.lifetime = rclcpp::Duration(std::chrono::seconds(0));
    marker.pose = geometry_msgs::msg::Pose();
    marker.pose.position = geometry_msgs::msg::Point();
    marker.pose.position.x = part.transform.getTranslation().x();
    marker.pose.position.y = part.transform.getTranslation().y();
    marker.pose.position.z = part.transform.getTranslation().z();
    marker.pose.orientation = geometry_msgs::msg::Quaternion();
    marker.pose.orientation.w = part.transform.getQuatRotation().w();
    marker.pose.orientation.x = part.transform.getQuatRotation().w();
    marker.pose.orientation.y = part.transform.getQuatRotation().w();
    marker.pose.orientation.z = part.transform.getQuatRotation().w();
    marker.mesh_resource = PART_RES_DIR +  part.part_file_name + ".obj.bin.stl";
    return marker;
}

std::shared_ptr<hpp::fcl::ConvexBase> loadConvexMesh(const std::string& file_name) {
    hpp::fcl::NODE_TYPE bv_type = hpp::fcl::BV_AABB;
    hpp::fcl::MeshLoader loader(bv_type);
    hpp::fcl::BVHModelPtr_t bvh = loader.load(file_name);
    bvh->buildConvexHull(true, "Qt");
    return bvh->convex;
}

std::vector<loop_part> create_parts_loop() {
    srand(time(NULL));
    
    return  {
        {"Buckle", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        {"bucky60", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        {"Buckle",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        {"bucky60", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"ClampBar85", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"dragon", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Dremel_Impeller",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"highres_fist", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Hollow_Pyramid", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"HollowCube", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Input_Pinion",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"IntermediateGear-NoDrum-OnBearings", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"IntermediateGear-WithDrum-OnBearings", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Magneto_Helmet", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"makerbot_ring",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Octocat-v2", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Buckle", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"bucky60", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Buckle",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"bucky60", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"ClampBar85", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"dragon", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Dremel_Impeller",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"highres_fist", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Hollow_Pyramid", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"HollowCube", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Input_Pinion",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"IntermediateGear-NoDrum-OnBearings", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"IntermediateGear-WithDrum-OnBearings", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Magneto_Helmet", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"makerbot_ring",  hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
        // {"Octocat-v2", hpp::fcl::Transform3f(hpp::fcl::Vec3f(randr(),randr(),randr()))},
    };
}

void publish_part_markers_to_rviz(const std::vector<loop_part>& loop) {
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_publisher = this_node->create_publisher<visualization_msgs::msg::Marker>("/visualization_markers", 10);
    for (size_t i = 0; i < loop.size(); i++) {
        auto marker_msg = generate_part_marker_msg(loop[i], i);
        marker_publisher->publish(marker_msg);
        RCLCPP_INFO(this_node->get_logger(), "Added part %s.obj.bin.stl to Rviz", loop[i].part_file_name.c_str());
    }
}

void load_gripper_and_parts(
    std::shared_ptr<hpp::fcl::ConvexBase>& gripper,
    hpp::fcl::Transform3f& gripper_transform, std::vector<loop_part>& loop_parts) {

    std::string robotic_depowdering_dir = ament_index_cpp::get_package_share_directory("robotic_depowdering") + "/test_parts/";
    std::string flexiv_description_dir = ament_index_cpp::get_package_share_directory("flexiv_description") + "/";
    gripper = loadConvexMesh(flexiv_description_dir + "meshes/grav/visual/static_assembly.stl");
    
    gripper_transform.setTranslation(hpp::fcl::Vec3f(randr(),randr(),randr()));
    gripper_transform.setQuatRotation(hpp::fcl::fromAxisAngle(hpp::fcl::Vec3f(randr(),randr(),randr()), randr()));
    
    for (auto& part : loop_parts) {
        part.shape = loadConvexMesh(robotic_depowdering_dir + part.part_file_name + ".stl");
    }
}

void collide_part_with_gripper(const loop_part& part, 
    const std::shared_ptr<hpp::fcl::ConvexBase> gripper, 
    const hpp::fcl::Transform3f& gripper_transform) {

    hpp::fcl::CollisionRequest col_req;
    col_req.security_margin = 1e-1;
    hpp::fcl::CollisionResult col_res;

    // Collision call
    RCLCPP_INFO(this_node->get_logger(), "Colliding part %s with the gripper", part.part_file_name.c_str());
    hpp::fcl::collide(part.shape.get(), part.transform, gripper.get(), gripper_transform, col_req, col_res);

    // We can access the collision result once it has been populated
    RCLCPP_INFO(this_node->get_logger(), "%s", col_res.isCollision() ? "Collision" : "No collision");
    if (col_res.isCollision()) {
        hpp::fcl::Contact contact = col_res.getContact(0);
        // The penetration depth does **not** take into account the security margin.
        // Consequently, the penetration depth is the true signed distance which separates the shapes.
        // To have the distance which takes into account the security margin, we can simply add the two together.
        RCLCPP_INFO(this_node->get_logger(), "   Penetration depth: %f", contact.penetration_depth);
        RCLCPP_INFO(this_node->get_logger(), "   Distance between the shapes including the security margin: %f", contact.penetration_depth + col_req.security_margin);
        RCLCPP_INFO(this_node->get_logger(), "   Contact position: (%f, %f, %f)", contact.pos.transpose().x(), contact.pos.transpose().y(), contact.pos.transpose().z());
        RCLCPP_INFO(this_node->get_logger(), "   Normal: <%f, %f, %f> ", contact.normal.transpose().x(), contact.normal.transpose().y(), contact.normal.transpose().z());
    }

    // Before calling another collision test, it is important to clear the previous results stored in the collision result.
    col_res.clear();
}

int main(int argc, char** argv) {

    rclcpp::init(argc, argv);
    this_node = rclcpp::Node::make_shared("loop_parts_collision_demo");
    
    std::vector<loop_part> loop = create_parts_loop();

    publish_part_markers_to_rviz(loop);
    RCLCPP_INFO(this_node->get_logger(), "Added parts to Rviz");
    
    std::shared_ptr<hpp::fcl::ConvexBase> gripper;
    hpp::fcl::Transform3f gripper_transform;

    load_gripper_and_parts(gripper, gripper_transform, loop);
    
    const auto t_start = std::chrono::high_resolution_clock::now();
    for (auto& part : loop) {
        collide_part_with_gripper(part, gripper, gripper_transform);
    }
    const auto t_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> t_diff = t_end - t_start;
    RCLCPP_INFO(this_node->get_logger(), "All parts collided in %3.7f seconds", t_diff);

    rclcpp::shutdown();
    return 0;
}