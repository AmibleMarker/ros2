#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/u_int32.hpp"

using std::placeholders::_1;
using std::placeholders::_2;


class SingleDogNode : public rclcpp::Node
{

public:
    
    SingleDogNode(std::string name) : Node(name)
    {
        
        hjj = this->create_subscription<std_msgs::msg::String>("rmb", 10, std::bind(&SingleDogNode::topic_callback, this, _1));
    }

private:
    
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr hjj;

    
    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "已收到：'%s'", msg->data.c_str());
    };

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<SingleDogNode>("hjj");
    
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
