#!/bin/sh
export TURTLEBOT_GAZEBO_WORLD_FILE=/home/workspace/catkin_ws/src/worlds/office.world
export TURTLEBOT_GAZEBO_MAP_FILE=/home/workspace/catkin_ws/src/map/office.yaml

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 5
xterm -e " roslaunch home_rviz view_navigation.launch" &

