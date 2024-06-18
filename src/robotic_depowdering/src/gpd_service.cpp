#include "rclcpp/rclcpp.hpp"
#include "robotic_depowdering_interfaces/srv/gpd_grasp.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"
#include "gpd/grasp_detector.h"
#include "gpd/util/config_file.h"
#include "tf2_eigen/tf2_eigen.hpp"

#include <memory>
#include <cstdlib>
#include <sstream>
#include <iostream>

#define LINE std::cout << __LINE__ << "\n"

void generateGraspPose(const std::shared_ptr<robotic_depowdering_interfaces::srv::GpdGrasp::Request> request,
                       std::shared_ptr<robotic_depowdering_interfaces::srv::GpdGrasp::Response> response)
{

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request to get grasp pose for file %s", request->file_name.c_str());
    
    // Convert OBJ to PCD
    // $ pcl_mesh_sampling GPDtest.obj GPDtestMeshSampling.pcd -leaf_size 0.0001
    
    std::string filename_pcd{request->file_name};
    filename_pcd.replace(filename_pcd.size() - 4, 4, ".pcd");
    std::ostringstream command;
    command << "pcl_mesh_sampling ";
    command << request->file_name;
    command << " ";
    command << filename_pcd;
    command << " -leaf_size 0.001 -no_vis_result"; // TODO: Add option for modifying more parameters?

    int res = std::system(command.str().c_str());
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Point cloud conversion command \"%s\" executed with result %d", command.str().c_str(), res);
    
    if (res != 0)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to convert OBJ file to Point Cloud. See logs for output from pcl_mesh_sampling command. Perhaps the file does not exist.");
        response->found_grasp = false;
        return;
    }
    // Create GraspDetector and run

    // Read parameters from configuration file.
    std::string package_share_directory = ament_index_cpp::get_package_share_directory("robotic_depowdering") + "/";
    const std::string config_filename = "cfg/rizon_4s.cfg";
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Loading resources from config folder: %s", (package_share_directory).c_str());
    
    gpd::util::ConfigFile config_file(package_share_directory + config_filename);
    if (!config_file.ExtractKeys())
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "GPD failed to load config file. Check the file exists and has been installed into install/robotic_depowdering/share/robotic_depowdering/cfg/rizon_4s.cfg");
        response->found_grasp = false;
        return;
    }

    // Set the camera position. Assumes a single camera view.
    std::vector<double> camera_position =
        config_file.getValueOfKeyAsStdVectorDouble("camera_position",
                                                   "0.0 0.0 0.0");
    Eigen::Matrix3Xd view_points(3, 1);
    view_points << camera_position[0], camera_position[1], camera_position[2];

    // Load point cloud from file.
    gpd::util::Cloud cloud(filename_pcd, view_points);
    if (cloud.getCloudOriginal()->size() == 0)
    {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Point cloud of OBJ file is empty or does not exist. Run pcl_mesh_sampling manually to check for errors. Visualize the point cloud with pcl_viewer [could.pcd].");
        response->found_grasp = false;
        return;
    }

    // This generates a bounding box for the workspace. Might come in handy later to work with objects in varying locations.
    /*
        auto point_cloud_samples = cloud.getCloudOriginal()->points;
        std::cout << point_cloud_samples.size() << "\n";
        float min_x = std::numeric_limits<float>::max(), max_x = std::numeric_limits<float>::min(),
              min_y = std::numeric_limits<float>::max(), max_y = std::numeric_limits<float>::min(),
              min_z = std::numeric_limits<float>::max(), max_z = std::numeric_limits<float>::min();

        for (const auto &sample : point_cloud_samples)
        {
            min_x = std::min(min_x, sample.x);
            max_x = std::max(max_x, sample.x);
            min_y = std::min(min_y, sample.y);
            max_y = std::max(max_y, sample.y);
            min_z = std::min(min_z, sample.z);
            max_z = std::max(max_z, sample.z);
        }

        std::cout << "Bounding box: [" << min_x << ", " << max_x << "] x ["
                  << min_y << ", " << max_y << "] x ["
                  << min_z << ", " << max_z << "]\n";
    */

    gpd::GraspDetector detector(config_filename, package_share_directory);

    // Preprocess the point cloud.
    detector.preprocessPointCloud(cloud);

    // If the object is centered at the origin, reverse all surface normals.
    bool centered_at_origin =
        config_file.getValueOfKey<bool>("centered_at_origin", false);
    if (centered_at_origin)
    {
        printf("Reversing normal directions ...\n");
        cloud.setNormals(cloud.getNormals() * (-1.0));
    }

    // Detect grasp poses.
    auto grasps = detector.detectGrasps(cloud);
    if (grasps.size() == 0) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "GPD failed to find any grasps. Run GPD's detect_grasps executable manually to debug. Check that parameters in the config are correct, namely workspace, max_aperture, and hand geometry");
        response->found_grasp = false;
        return;
    }

    auto hand = std::move(grasps[0]);
    response->found_grasp = true;
    response->position = tf2::toMsg(hand->getPosition());
    response->approach = tf2::toMsg(hand->getApproach(), response->approach);
    response->binormal = tf2::toMsg(hand->getBinormal(), response->approach);
    response->axis = tf2::toMsg(hand->getAxis(), response->approach);
    response->width = hand->getGraspWidth();
    response->score = hand->getScore();
    response->sample = tf2::toMsg(hand->getSample());
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("gpd_service");

    rclcpp::Service<robotic_depowdering_interfaces::srv::GpdGrasp>::SharedPtr service =
        node->create_service<robotic_depowdering_interfaces::srv::GpdGrasp>("gpd_service", &generateGraspPose);

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Initialized GPD interface service. Call this service to generate grasps for a given file");

    rclcpp::spin(node);
    rclcpp::shutdown();
}