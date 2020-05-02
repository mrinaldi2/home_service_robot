#!/bin/sh

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find assets)/worlds/office.world" &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(rospack find assets)/map/office.yaml" &
sleep 5
xterm -e " roslaunch home_rviz view_navigation.launch" &

