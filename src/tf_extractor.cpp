#include <ros/ros.h>
#include <tf/transform_listener.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "tf_extractor");
  ros::NodeHandle private_nh("~");
  
  double frequency;
  std::string source_frameid, target_frameid;
  private_nh.param<double>("frequency", frequency, 10);
  private_nh.param<std::string>("source_frameid", source_frameid, "/map");
  private_nh.param<std::string>("target_frameid", target_frameid, "/base_link");
  
  ros::Publisher tf_pub = private_nh.advertise<tf2_msgs::TFMessage>("tf", 100, true);
  
  tf::TransformListener listener;

  ros::Rate rate(frequency);
  
  while(private_nh.ok()) {
    tf::StampedTransform transform;
    try {
      listener.lookupTransform(source_frameid, target_frameid, ros::Time(0), transform);
      geometry_msgs::TransformStamped ts;
      tf2_msgs::TFMessage msg;
      tf::transformStampedTFToMsg(transform, ts);
      msg.transforms.push_back(ts);
      tf_pub.publish(msg);
    } catch(tf::TransformException &ex) {
      //ROS_ERROR("%s",ex.what());
    }
    rate.sleep();
  }
  
  return 0;
}
