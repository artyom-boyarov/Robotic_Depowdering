#include "rclcpp/rclcpp.hpp"
#include "robotic_depowdering_interfaces/srv/gpd_grasp.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;


int main(int argc, char** argv) {

    rclcpp::init(argc, argv);

    if (argc != 2) {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Usage: ros2 run robotic_depowdering pick_up_object [filename.obj]");
        return -1;
    }

    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("pick_up_object_client");
    rclcpp::Client<robotic_depowdering_interfaces::srv::GpdGrasp>::SharedPtr client = 
        node->create_client<robotic_depowdering_interfaces::srv::GpdGrasp>("gpd_service");
    
    auto request = std::make_shared<robotic_depowdering_interfaces::srv::GpdGrasp::Request>();
    request->file_name = argv[1];

    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service gpd_service unavailable");
    }

    auto resultFuture = client->async_send_request(request);
    std::shared_ptr<robotic_depowdering_interfaces::srv::GpdGrasp::Response> result;
    // Wait for the result
    if (rclcpp::spin_until_future_complete(node, resultFuture) == 
        rclcpp::FutureReturnCode::SUCCESS) 
    {
        result = resultFuture.get();
        if (result.get()->found_grasp) {
            RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Got back grasp configuration.");
        } else {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "GPD failed to return a grasp configuration");
            return -2;
        }
        
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service");
        return -3;
    }

    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tposition: <%f, %f, %f>", result.get()->position.x, result.get()->position.y, result.get()->position.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tapproach: <%f, %f, %f>", result.get()->approach.x, result.get()->approach.y, result.get()->approach.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tbinormal: <%f, %f, %f>", result.get()->binormal.x, result.get()->binormal.y, result.get()->binormal.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\taxis: <%f, %f, %f>", result.get()->axis.x, result.get()->axis.y, result.get()->axis.z);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\taperture: %f", result.get()->width);
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\tscore: %f", result.get()->score);

    // Carry out IK 
    //   \/\/\/\/

    rclcpp::shutdown();
    return 0;
}