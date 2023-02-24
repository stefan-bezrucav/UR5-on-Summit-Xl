<?xml version="1.0"?>
<robot name="ur5" xmlns:xacro="http://www.ros.org/wiki/xacro">
    <!-- ur5 model macro-->
    <xacro:include filename="$(find ur5_description)/urdf/ur5.urdf.xacro" />

    <!-- ur5 Arguments -->
    <xacro:arg name="namespace" default="ur5"/>

    <!-- ur5 instantiation -->
    <xacro:ur5_robot namespace="$(arg namespace)" prefix="$(arg namespace)/" joint_limited="false"/>

</robot>
