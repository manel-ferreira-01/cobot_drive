//========================================================================
//  This software is free: you can redistribute it and/or modify
//  it under the terms of the GNU Lesser General Public License Version 3,
//  as published by the Free Software Foundation.
//
//  This software is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public License
//  Version 3 in the file COPYING that came with this distribution.
//  If not, see <http://www.gnu.org/licenses/>.
//========================================================================
/*!
\file    cobot_drive_main.cpp
\brief   The drive module for CoBot II
\author  Joydeep Biswas, (C) 2010
*/
//========================================================================

#include "cobot_drive_main.hpp"

// using namespace cobot_msgs;

#define RAD(deg) ((deg) * M_PI / 180.0)

using namespace std::chrono_literals;

cobotDriveMain::cobotDriveMain() : Node("cobot_drive") {

  static const bool debug = false;

  int portNum = this->get_parameter("port_num_drive").as_int();

  // Sacred data from CMU code - do not change
  motor_properties_t motorProps;
  motorProps.xyFlipped = true;
  motorProps.encoderCountsPerMeter = vector2d(-1.0,1.0)*30466.8;
  motorProps.encoderCountsPerRadian = 8701.6;
  motorProps.transMotionScale = vector2d(1.0,1.0)*8620.68965517241379310345;
  motorProps.rotMotionScale = -1736.11494888090632771484;
  cobotDrive = new CobotDrive(motorProps);


  char serialPort[256];
  sprintf(serialPort,"/dev/ttyUSB%d",portNum);
  printf("Using port %s\n",serialPort);

  //TODO: Get the limits from the parameter server
  AccelLimits transLimits, rotLimits;

  transLimits.set(this->get_parameter("translation_limits.max_accel").as_double(),
    this->get_parameter("translation_limits.max_deccel").as_double(),
    this->get_parameter("translation_limits.max_vel").as_double()
  );

  rotLimits.set(this->get_parameter("rotation_limits.max_accel").as_double(), 
    this->get_parameter("rotation_limits.max_deccel").as_double(),
    this->get_parameter("rotation_limits.max_vel").as_double()
  );

  cobotDrive->setLimits(transLimits, rotLimits);
  cobotDrive->init(serialPort);

  cobotRawStatusPublisher = this->create_publisher<messages::msg::CobotRawStatus>("/cobot/raw_status", 10);
  cobotOdometryPublisher = this->create_publisher<nav_msgs::msg::Odometry>("/cobot/odometry", 10);

  drive_sub = this->create_subscription<geometry_msgs::msg::Twist>("/cmd_vel", 10,
   std::bind(&cobotDriveMain::cobotDriveCallback, this, std::placeholders::_1));

  timer_ = this->create_wall_timer(50ms, std::bind(&cobotDriveMain::timerEvent, this));

}

cobotDriveMain::~cobotDriveMain() {
  cobotDrive->close();
  delete cobotDrive;
}

void cobotDriveMain::cobotDriveCallback(const geometry_msgs::msg::Twist::SharedPtr msg) {
  cobotDrive->setSpeeds(msg->linear.x, msg->linear.y, msg->angular.z);
}


void cobotDriveMain::timerEvent() {

  // print debug "got to timer"
  printf("got to timer\n");

  const bool debugTimer = false;
  rclcpp::Time tNow = this->now();
  static double tLast = tNow.seconds();
  static double tLastOdometry = tNow.seconds();

  if(debugTimer){
    printf( "dT = %f\n", tNow.seconds()-tLast );
    tLast = tNow.seconds();
  }

  cobotDrive->run();

  //Get odometry message
  
  double dr,dx,dy,v0,v1,v2,v3,vr,vx,vy,adc,curAngle;
  unsigned char status;
  vector2d curLoc;
  if(cobotDrive->GetFeedback(dr,dx,dy,v0,v1,v2,v3,vr,vx,vy,adc,status,curLoc,curAngle)){
    messages::msg::CobotRawStatus cobotRawStatusMsg;
    cobotRawStatusMsg.dr = dr;
    cobotRawStatusMsg.dx = dx;
    cobotRawStatusMsg.dy = dy;
    cobotRawStatusMsg.v0 = v0;
    cobotRawStatusMsg.v1 = v1;
    cobotRawStatusMsg.v2 = v2;
    cobotRawStatusMsg.v3 = v3;
    cobotRawStatusMsg.vr = vr;
    cobotRawStatusMsg.vx = vx;
    cobotRawStatusMsg.vy = vy;
    cobotRawStatusMsg.v_batt = adc;
    cobotRawStatusMsg.status = status;

    //cobotRawStatusMsg.header.seq++;
    cobotRawStatusMsg.header.stamp = tNow;
    cobotRawStatusMsg.header.frame_id = "base_footprint";


    static nav_msgs::msg::Odometry odometryMsg;
    odometryMsg.header.frame_id = "odom";
    // odometryMsg.header.seq ++;
    odometryMsg.header.stamp = this->now();
    odometryMsg.child_frame_id = "base_footprint";
    odometryMsg.pose.pose.position.x = curLoc[0];
    odometryMsg.pose.pose.position.y = curLoc[1];
    odometryMsg.pose.pose.position.z = 0;
    odometryMsg.pose.pose.orientation.w = cos(curAngle*0.5);
    odometryMsg.pose.pose.orientation.x = 0;
    odometryMsg.pose.pose.orientation.y = 0;
    odometryMsg.pose.pose.orientation.z = sin(curAngle*0.5);
    odometryMsg.twist.twist.angular.x = 0;
    odometryMsg.twist.twist.angular.y = 0;
    odometryMsg.twist.twist.angular.z = vr;
    odometryMsg.twist.twist.linear.x = vx;
    odometryMsg.twist.twist.linear.y = vy;
    odometryMsg.twist.twist.linear.z = 0;

    double dT = tNow.seconds() - tLastOdometry;

    tLastOdometry = tNow.seconds();
    static const double MaxTransSpeed = 3.0;
    static const double MaxRotSpeed = 360.0;

    if((std::pow(dx,2)+std::pow(dy,2))>std::pow(MaxTransSpeed/dT , 2) || fabs(dr)>RAD(MaxRotSpeed/dT)){
      std::cout << ("Odometry out of bounds! Dropping odometry packet.") << std::endl;
    }else{
      cobotRawStatusPublisher->publish(cobotRawStatusMsg);
      cobotOdometryPublisher->publish(odometryMsg);


      tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);

      geometry_msgs::msg::TransformStamped t;
      t.header.stamp = this->get_clock()->now();
      t.header.frame_id = "odom";
      t.child_frame_id = "base_link"; // https://ros.org/reps/rep-0105.html

      t.transform.translation.x = curLoc[0];
      t.transform.translation.y = curLoc[1];
      t.transform.translation.z = 0.0;

      tf2::Quaternion q;
      q.setRPY(0, 0, curAngle);
      t.transform.rotation.x = q.x();
      t.transform.rotation.y = q.y();
      t.transform.rotation.z = q.z();
      t.transform.rotation.w = q.w();

      tf_broadcaster_->sendTransform(t);

    }
  }
}

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<cobotDriveMain>());
  rclcpp::shutdown();
  return(0);
}
