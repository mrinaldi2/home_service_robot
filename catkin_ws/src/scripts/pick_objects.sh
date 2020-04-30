#!/bin/sh
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/worlds/office.world
export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/catkin_ws/src/turtlebot_simulator/turtlebot_gazebo/maps/office.yaml

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 5
xterm -e " roslaunch home_rviz view_navigation.launch" &
sleep 1
xterm -e " roslaunch pick_objects pick_objects.launch" &

