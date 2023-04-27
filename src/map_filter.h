//
// Created by hmc on 22. 3. 11..
//

#ifndef DATMO_MAP_FILTER_H
#define DATMO_MAP_FILTER_H

#include <ros/ros.h>
#include <tf/transform_listener.h>

#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/OccupancyGrid.h>
#include <nav_msgs/Odometry.h>

class map_filter {
private:
    bool map_received_;

    nav_msgs::OccupancyGrid girdMap_;
    tf::TransformListener tf_;

public:
    bool isMapPoint(std::string target_frame, sensor_msgs::LaserScan& scan);

    void checkMapReceived(const nav_msgs::OccupancyGrid::ConstPtr map);

    map_filter();

};


#endif //DATMO_MAP_FILTER_H
