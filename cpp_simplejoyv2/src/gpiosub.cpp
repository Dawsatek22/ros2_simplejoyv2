// This is a minimal member subscriber node to to toggle leds with publisher nodes msgs.
#include <wiringPi.h> // Is the gpio library for the pins.
// Below are the standard headers for the subscriber node
#include <functional>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
// below are the integers for the leds pins.
int led1 = 14;
int led2 = 15;


using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("gpio_subscriber")
  {

    subscription_ = this->create_subscription<std_msgs::msg::Int32>(
      "joystick_topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

wiringPiSetupGpio(); // BCM pins are setup.
// Pins are setup.
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pullUpDnControl(led1,PUD_DOWN);
pullUpDnControl(led2,PUD_DOWN);
    }

private:
  void topic_callback(const std_msgs::msg::Int32 & msg) const
  {
    RCLCPP_INFO(this->get_logger(), "I receive  joystick value: '%i'", msg.data);

  
if(msg.data == 1 ){ // led 1 on led2 off.
  digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);

 
}

  if(msg.data == 3 ){ // led 1 off led2 on.
  digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
  }
  if(msg.data == 0 ){ // led 1 off led2 off.
  digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
  
  }
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