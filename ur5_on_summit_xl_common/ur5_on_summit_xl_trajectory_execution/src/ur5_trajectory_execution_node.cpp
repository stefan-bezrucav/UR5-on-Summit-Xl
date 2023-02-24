/**
 *  @file
 *  @brief <add brief description here>
 *
 *  @author Bazooka
 */

#include <ros/ros.h>
#include "ur5_trajectory_execution_node/ur5_trajectory_execution.h"

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "ur5_trajectory_execution");

  // Please rename 'node_object' into a comprehensible name of the node_class instance
  ur5_on_summit_xl_trajectory_execution::Ur5TrajectoryExecution node_object;

  node_object.run();

  return 0;

}
