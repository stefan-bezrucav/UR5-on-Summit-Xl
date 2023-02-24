/**
 * @file
 * @brief <Add brief description here>
 *
 * @ros_node <Add node function description here>
 *
 * <Add detailed description here>
 *
 * @author Bazooka
 */

#ifndef UR5_ON_SUMMIT_XL_TRAJECTORY_EXECUTION_UR5_TRAJECTORY_EXECUTION_NODE_UR5_TRAJECTORY_EXECUTION_H
#define UR5_ON_SUMMIT_XL_TRAJECTORY_EXECUTION_UR5_TRAJECTORY_EXECUTION_NODE_UR5_TRAJECTORY_EXECUTION_H

#include <ros/ros.h>
#include "std_msgs/Float32MultiArray.h"

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <geometric_shapes/shape_operations.h>

#include <actionlib/server/simple_action_server.h>
#include <ur5_on_summit_xl_trajectory_execution/MoveItWrapperAction.h>

namespace ur5_on_summit_xl_trajectory_execution
{
  /**
   * @brief <Add brief class description here>
   *
   * <Add detailed class description here>
   */
  class Ur5TrajectoryExecution
  {

  public:

    /**
     * @brief Constructor
     */
    Ur5TrajectoryExecution();

    /**
     * @brief Execute node logic
     */
    void run();

  private:

    ros::NodeHandle nh_;            //!< Node handle 
    ros::Rate       node_rate_;     //!< Loop rate for this node 
    ros::AsyncSpinner spinner_;     //!< Async spinner for the moveit calls
    boost::scoped_ptr<moveit::planning_interface::MoveGroupInterface> moveit_group_; //!< The moveit group for planning
    moveit::planning_interface::MoveGroupInterface::Plan moveit_plan_; //!< The moveit plan

    actionlib::SimpleActionServer<ur5_on_summit_xl_trajectory_execution::MoveItWrapperAction> moveit_wrapper_server_; //!< Moveit Wrapper Action Server
    /**
     * @brief Executes the move to the recieved pose
     */
    void moveItWrapperCallback(const ur5_on_summit_xl_trajectory_execution::MoveItWrapperGoalConstPtr& goal);

  };
} // ur5_on_summit_xl_trajectory_execution

#endif // UR5_ON_SUMMIT_XL_TRAJECTORY_EXECUTION_UR5_TRAJECTORY_EXECUTION_NODE_UR5_TRAJECTORY_EXECUTION_H
