#include "ros/ros.h"
#include "std_msgs/Int32.h"

void subscriberCallback(const std_msgs::Int32 msg)
{
	ROS_INFO("Received : %d \n", msg.data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "name_of_sub_node");
	ros::NodeHandle nh;

	ros::Subscriber i_am_the_subscriber = nh.subscribe("name_of_topic", 100, subscriberCallback);

	ros::spin();

	return 0;
}
