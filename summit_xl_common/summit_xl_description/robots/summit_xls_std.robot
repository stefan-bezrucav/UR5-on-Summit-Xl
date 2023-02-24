<?xml version="1.0"?>
<robot name="summit_xls_std" xmlns:xacro="http://www.ros.org/wiki/xacro">
    <!-- Include model macro -->
    <xacro:include filename="$(find summit_xl_description)/models/summit_xls_std.xacro"/>

    <!-- Arguments -->
    <xacro:arg name="namespace" default="summit_xl"/>
    <xacro:arg name="publish_bf" default="true"/>
    <!-- Flag to select the high or low quality model -->
    <xacro:arg name="hq" default="false" />

    <!-- Summit XL Steel STD instantiation -->
    <xacro:summit_xls_std namespace="$(arg namespace)" publish_bf="$(arg publish_bf)" hq="$(arg hq)"/>

</robot>
