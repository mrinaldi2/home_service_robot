# home_service_robot
Udacity project home service robot

## Packages used
In building my home service robot I have used the following ros projects

 - [gmapping](http://wiki.ros.org/gmapping): With the gmapping_demo.launch file, you can easily perform SLAM and build a map of the environment with a robot equipped with laser range finder sensors or RGB-D cameras.
 - [turtlebot_teleop](http://wiki.ros.org/turtlebot_teleop): With the keyboard_teleop.launch file, you can manually control a robot using keyboard commands.
 - [turtlebot_rviz_launchers](http://wiki.ros.org/turtlebot_rviz_launchers): With the view_navigation.launch file, you can load a preconfigured rviz workspace. You’ll save a lot of time by launching this file, because it will automatically load the robot model, trajectories, and map for you.
 - [turtlebot_gazebo](http://wiki.ros.org/turtlebot_gazebo): With the turtlebot_world.launch you can deploy a turtlebot in a gazebo environment by linking the world file to it.
 - [pgm_map_creator](https://github.com/hyfan1116/pgm_map_creator): With this package you can create a pgm map using and exist world in gazebo.

## Scripts

The project has 5 scripts to test different functionalities
 
 - test_slam.sh: will launch gazebo with the office world created by me, rviz and the teleop keyboard so you can control the robot and check that he builds a map.
 
 - test_navigation.sh: will launch gazebo with the office world, rviz and amcl to test with the rviz 2d nav goal button that robot recognize the map created and is capable to move between rooms
 
 - pick_objects.sh: will launch gazebo with the office world, rviz, amcl and my pick_objects package that will move the robot to a pickup zone and then to a dropoff zone
 
 - add_marker.sh: will launch gazebo with the office world, rviz, amcl and my package add_markers to demostrate how you can simulate virtual objects to rviz with markers.
 
 - home_service.sh: wil launch gazebo with the office world, rviz, amcl, pick_objects and add_markers edited to listen to the odom topic. This will allow markers to appear and disappear based on the robot position
