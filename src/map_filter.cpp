#include "map_filter.h"

bool map_filter::isMapPoint(std::string target_frame, sensor_msgs::LaserScan& scan)
{
    ros::Duration dur (0.1);
    if(tf_.waitForTransform(target_frame, scan.header.frame_id, scan.header.stamp, dur))
    {
        tf::StampedTransform laser_transform;
        tf_.lookupTransform(target_frame, scan.header.frame_id, scan.header.stamp, laser_transform);

        tf::Vector3 laser_pos(laser_transform.getOrigin());
        tf::Quaternion laser_quat(laser_transform.getRotation());
        tf::Matrix3x3 tmp_mat(laser_quat);
        double roll,pitch,yaw;
        tmp_mat.getRPY(roll,pitch,yaw);

    }
}

void map_filter::checkMapReceived(const nav_msgs::OccupancyGrid::ConstPtr map)
{
    girdMap_ = *map;
    map_received_ = true;
}

map_filter::map_filter()
{
    map_received_ = false;
}
