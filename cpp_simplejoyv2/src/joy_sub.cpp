
// This is  just a simple  minimal member subscriber node to receive publisher msg.
#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("joy_subscriber")
  {
    subscription_ = this->create_subscription<std_msgs::msg::Int32>(
      "joystick_topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
  }

private:
  void topic_callback(const std_msgs::msg::Int32 & msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I receive  joystick value: '%i'", msg.data);
  }
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}