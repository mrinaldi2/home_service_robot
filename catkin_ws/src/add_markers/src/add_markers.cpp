#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

visualization_msgs::Marker marker;


int main( int argc, char** argv )
{
   ros::init(argc, argv, "add_markers");
   ros::NodeHandle n;
   ros::Rate r(1);
   ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
 
   // Set our initial shape type to be a cube
   uint32_t shape = visualization_msgs::Marker::CUBE;
 
  
  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
  marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "add_markers";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = -5.86;
  marker.pose.position.y = 1.89;
  marker.pose.position.z = 0.5;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.8;
  marker.scale.y = 0.8;
  marker.scale.z = 0.8;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();

  // Publish the marker
  while (marker_pub.getNumSubscribers() < 1)
  {
    if (!ros::ok())
    {
      return 0;
    }
    ROS_WARN_ONCE("Please create a subscriber to the marker");
    sleep(1);
  }

  marker.action = visualization_msgs::Marker::ADD;
  marker_pub.publish(marker);

  ROS_INFO("Pick up location marker");
  ros::Duration(5.0).sleep();

  marker.action = visualization_msgs::Marker::DELETE;
  marker_pub.publish(marker);

  ROS_INFO("Pick up location marker deleted");
  ros::Duration(5.0).sleep();

  marker.pose.position.x = 5.36;
  marker.pose.position.y = 1.19;
  marker.pose.position.z = 0.5;

  marker.action = visualization_msgs::Marker::ADD;
  marker_pub.publish(marker);
  ROS_INFO("Dropoff location marker");
  ros::Duration(5.0).sleep();
  // Cycle between different shapes
 
 
}