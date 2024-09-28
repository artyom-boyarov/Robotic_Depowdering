#include <string>

#include <gpd/grasp_detector.h>

namespace gpd {
namespace apps {
namespace detect_grasps {

bool checkFileExists(const std::string &file_name) {
  std::ifstream file;
  file.open(file_name.c_str());
  if (!file) {
    std::cout << "File " + file_name + " could not be found!\n";
    return false;
  }
  file.close();
  return true;
}

int DoMain(int argc, char *argv[]) {
  // Read arguments from command line.
  if (argc < 3) {
    std::cout << "Error: Not enough input arguments!\n\n";
    std::cout << "Usage: detect_grasps CONFIG_FILE PCD_FILE [NORMALS_FILE]\n\n";
    std::cout << "Detect grasp poses for a point cloud, PCD_FILE (*.pcd), "
                 "using parameters from CONFIG_FILE (*.cfg).\n\n";
    std::cout << "[NORMALS_FILE] (optional) contains a surface normal for each "
                 "point in the cloud (*.csv).\n";
    return (-1);
  }

  std::string config_filename = argv[1];
  std::string pcd_filename = argv[2];
  if (!checkFileExists(config_filename)) {
    printf("Error: config file not found!\n");
    return (-1);
  }
  if (!checkFileExists(pcd_filename)) {
    printf("Error: PCD file not found!\n");
    return (-1);
  }



  // Read parameters from configuration file.
  util::ConfigFile config_file(config_filename);
  config_file.ExtractKeys();

  // Set the camera position. Assumes a single camera view.
  // std::vector<double> camera_position =
  //     config_file.getValueOfKeyAsStdVectorDouble("camera_position",
  //                                                "0.0 0.0 0.0");

  // TODO: Look at gpd_ros to see how they form cloud.
  // Where to place cameras?
  // Can we just place them above/below, left/right, forward/behind?

  // Set the view points. Most basic implementation.
  Eigen::Matrix3Xd view_points(3, 6);

  view_points.col(0) <<  0.0,  0.0,  1.0;
  view_points.col(1) <<  0.0,  0.0, -1.0;
  view_points.col(2) <<  0.0,  1.0,  0.0;
  view_points.col(3) <<  0.0, -1.0,  0.0;
  view_points.col(4) <<  1.0,  0.0,  0.0;
  view_points.col(5) << -1.0,  0.0,  0.0;

  // Load the point cloud
  pcl::PointCloud<pcl::PointNormal>::Ptr pointCloud (new pcl::PointCloud<pcl::PointNormal>);
  if (pcl::io::loadPCDFile<pcl::PointNormal>(argv[2], *pointCloud) == -1) {
    PCL_ERROR ("Couldn't read input point cloud file \n");
    return (-1);
  }

  std::cout << "Loaded " << pointCloud->width * pointCloud->height << " points from " << argv[2] << "\n";
  std::cout << "Loaded point cloud with width " << pointCloud->width << " and height " << pointCloud->height << "\n";

  // Initialize the camera sources.
  Eigen::MatrixXi camera_source = Eigen::MatrixXi::Zero(view_points.cols(), pointCloud->size());

  for (int point_idx = 0; point_idx <  pointCloud->size(); point_idx++) {
    // Do it by which direction the surface normal is facing.
    // They all have the same length, so just do smallest dot product.
    // std::cout << (*pointCloud)[point_idx].normal_x << " " << (*pointCloud)[point_idx].normal_y << " " << (*pointCloud)[point_idx].normal_z << "\n";

    float min_dp_adjusted = 100;
    int min_dp_adjusted_idx;
    for (int camera_idx = 0; camera_idx < 6; camera_idx++) {
      float dp = view_points.col(camera_idx).dot( Eigen::Vector3d(
        (*pointCloud)[point_idx].normal_x,
        (*pointCloud)[point_idx].normal_y,
        (*pointCloud)[point_idx].normal_z
      ));
      // std::cout << dp << "\n";
      float dp_adjusted = 1 - dp;

      if (dp_adjusted < min_dp_adjusted) {
        min_dp_adjusted = dp_adjusted;
        min_dp_adjusted_idx = camera_idx;
      }
    }
    // std::cout << "Min dp: " << min_dp_adjusted_idx << "\n";
    camera_source(min_dp_adjusted_idx, point_idx) = 1;
  }

  // Load point cloud from file.
  util::Cloud cloud(pointCloud, camera_source, view_points);
  if (cloud.getCloudOriginal()->size() == 0) {
    std::cout << "Error: Input point cloud is empty or does not exist!\n";
    return (-1);
  }

  // Load surface normals from file.
  if (argc > 3) {
    std::string normals_filename = argv[3];
    cloud.setNormalsFromFile(normals_filename);
    std::cout << "Loaded surface normals from file: " << normals_filename
              << "\n";
  }

  cloud.loadNormalsPointCloud(pcd_filename);

  // TODO: Maybe we can do table/other part collision avoidance, since in GPD
  // we can have other parts in the scene, we just specify which part we want
  // to grap using sample indices.
  

  GraspDetector detector(config_filename);


  // Preprocess the point cloud.
  detector.preprocessPointCloud(cloud);

  // If the object is centered at the origin, reverse all surface normals.
  bool centered_at_origin =
      config_file.getValueOfKey<bool>("centered_at_origin", false);
  if (centered_at_origin) {
    printf("Reversing normal directions ...\n");
    cloud.setNormals(cloud.getNormals() * (-1.0));
  }

  // Detect grasp poses.
  detector.detectGrasps(cloud);

  return 0;
}

}  // namespace detect_grasps
}  // namespace apps
}  // namespace gpd

int main(int argc, char *argv[]) {
  return gpd::apps::detect_grasps::DoMain(argc, argv);
}
