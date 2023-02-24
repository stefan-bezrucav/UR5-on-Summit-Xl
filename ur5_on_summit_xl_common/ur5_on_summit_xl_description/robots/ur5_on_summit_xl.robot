<?xml version="1.0"?>
<robot name="ur5_on_summit_xl" xmlns:xacro="http://ros.org/wiki/xacro">
    <!-- summit model macro -->
    <xacro:include filename="$(find summit_xl_description)/models/summit_xls_std.xacro"/>
    <!-- ur5 model macro-->
    <xacro:include filename="$(find ur5_description)/urdf/ur5.urdf.xacro" />

    <!-- summit Arguments -->
    <xacro:arg name="summit_namespace" default="summit_xl"/>
    <xacro:arg name="summit_publish_bf" default="true"/>
    <xacro:arg name="summit_hq" default="true" />

    <!-- summit instantiation -->
    <xacro:summit_xls_std namespace="$(arg summit_namespace)" publish_bf="$(arg summit_publish_bf)" hq="$(arg summit_hq)"/>

    <!-- ur5 Arguments -->
    <xacro:arg name="ur5_namespace" default="ur5"/>

    <!-- ur5 instantiation -->
    <xacro:ur5_robot namespace="$(arg ur5_namespace)" prefix="$(arg ur5_namespace)/" joint_limited="false"/>

    <!-- connection ur5 on summit-->
    <joint name="$(arg summit_namespace)/base_link__$(arg ur5_namespace)/base_link" type="fixed">
      <parent link="$(arg summit_namespace)/base_link" />
      <child link = "$(arg ur5_namespace)/base_link" />
      <origin xyz="0.0 0.0 0.35" rpy="0.0 0.0 0.0" />
    </joint>
</robot>
