#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv)
{
	ros::init(argc, argv, "name_of_pub_node"); // initialize ROS val, set node name.
	ros::NodeHandle nh; //Create Node handle
	ros::Publisher i_am_publisher = nh.advertise<std_msgs::Int32>("name_of_topic",100);
	//Create Publisher name & Communication route(topic) and size of buf

	ros::Rate loop_rate(5);
	//loop cycle = 5Hz

	int count = 0;

	while(ros::ok())
	{
		std_msgs::Int32 testmsg;
		
		testmsg.data = count; // Communication data == Count
		ROS_INFO("Value: %c\n", testmsg.data); // Show data into terminal

		i_am_publisher.publish(testmsg); // Send message
	
		ros::spinOnce(); // match loop cycle. 
		loop_rate.sleep(); // ( occur one time and sleep)

		count ++;
	}
	
	return 0;
}
