#ifndef INTERFACE_H
#define INTERFACE_H

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

class Interface
{
 public:
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered;
  virtual int sample_filter() = 0;
  Interface()
  {
    cloud.reset(new pcl::PointCloud<pcl::PointXYZ>());
    cloud_filtered.reset(new pcl::PointCloud<pcl::PointXYZ>());
  }

  // 加载点云
  int setCloudPath(std::string path)
  {
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(path, *cloud) == -1)
    {
      PCL_ERROR("Couldn't read file your_point_cloud_file.pcd \n");
      return (-1);
    }
    return 0;
  }
  int saveCloud(std::string path = "../result/filtered_point_cloud.pcd")
  {
    pcl::io::savePCDFileBinary(path, *cloud_filtered);
    return 0;
  }
};

#endif