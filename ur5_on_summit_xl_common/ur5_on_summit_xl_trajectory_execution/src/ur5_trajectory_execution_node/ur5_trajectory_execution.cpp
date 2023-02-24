#include "ur5_trajectory_execution.h"

using namespace ur5_on_summit_xl_trajectory_execution;

Ur5TrajectoryExecution::Ur5TrajectoryExecution()
    : nh_("~"), node_rate_(10.0), spinner_(1),
      moveit_wrapper_server_(nh_, "moveit_wrapper", boost::bind(&Ur5TrajectoryExecution::moveItWrapperCallback, this, _1), false)
{
    // Load parameters from parameter server

    double loop_rate;
    if (nh_.getParam("loop_rate", loop_rate))
    {
        ROS_INFO("Successfully loaded node rate parameter.");
        node_rate_ = loop_rate;
    }
    else
        ROS_WARN("Failed to load node rate parameter. Setting to default.");

    std::string ur5_namespace;
    nh_.getParam("ur5_namespace", ur5_namespace);
    moveit_group_.reset(new moveit::planning_interface::MoveGroupInterface(ur5_namespace + "/arm"));

    // Start the server
    moveit_wrapper_server_.start();
}


void Ur5TrajectoryExecution::moveItWrapperCallback(const ur5_on_summit_xl_trajectory_execution::MoveItWrapperGoalConstPtr &goal)
{
  //wait for arm to settle
  ros::Duration(0.5).sleep();

  // Set goal
  moveit_group_->setJointValueTarget(goal->joint_space_goal);

  // Plan and move
  if (!moveit_group_->plan(moveit_plan_) == moveit::planning_interface::MoveItErrorCode::SUCCESS)
      moveit_wrapper_server_.setAborted();

  if (!moveit_group_->move()== moveit::planning_interface::MoveItErrorCode::SUCCESS)
      moveit_wrapper_server_.setAborted();

  moveit_wrapper_server_.setSucceeded();
}

void Ur5TrajectoryExecution::run()
{
    // Needed for the move function of moveit::planning_interface::MoveGroup
    spinner_.start();
    while(ros::ok())
    {
        ros::spinOnce();
        node_rate_.sleep();
    }
}
