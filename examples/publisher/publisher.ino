#include <ros2arduino.h>

#include "std_msgs/String.hpp"

#define RTPS_SERIAL  Serial   //OpenCR USB
#define PUBLISH_FREQUENCY 2 //hz

void publishString(std_msgs::String* msg, void* arg)
{
  (void)(arg);

  static int cnt = 0;
  sprintf(msg->data, "Hello ros2arduino %d", cnt++);
}

class StringPub : public ros2::Node
{
public:
  StringPub()
  : Node()
  {
    ros2::Publisher<std_msgs::String>* publisher_ = this->createPublisher<std_msgs::String>("arduino_chatter");
    this->createWallFreq(PUBLISH_FREQUENCY, (ros2::CallbackFunc)publishString, NULL, publisher_);
  }
};

void setup() 
{
  RTPS_SERIAL.begin(1000000);
  ros2::init((Stream*)&RTPS_SERIAL);

  while (!RTPS_SERIAL); 
}

void loop() 
{
  static StringPub StringNode;

  ros2::spin(&StringNode);
}