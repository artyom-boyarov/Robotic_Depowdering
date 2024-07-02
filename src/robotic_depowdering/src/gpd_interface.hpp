#pragma once
#include "rclcpp/rclcpp.hpp"
#include "robotic_depowdering_interfaces/srv/gpd_grasp.hpp"
#include "ament_index_cpp/get_package_share_directory.hpp"
#include "gpd/grasp_detector.h"
#include "gpd/util/config_file.h"
#include "tf2_eigen/tf2_eigen.hpp"
#include "pcl/PolygonMesh.h"
#include "pcl/io/io.h"
#include "pcl/io/vtk_lib_io.h"
#include "pcl/io/obj_io.h"

std::unique_ptr<gpd::candidate::Hand> generateGraspPose(const std::string filename);