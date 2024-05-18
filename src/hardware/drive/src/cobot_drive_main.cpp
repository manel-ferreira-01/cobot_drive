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

#include <iostream>
#include <stdio.h>
#include "drive.h"
//#include "terminal_utils.h"
//#include "proghelp.h"
#include "sys/time.h"
#include <ros/ros.h>
//#include "cobot_msgs/CobotDriveMsg.h"
//#include "cobot_msgs/CobotDriveRawMsg.h"
//#include "cobot_msgs/CobotOdometryMsg.h"
//#include "popt_pp.h"
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include "std_msgs/Int32.h"
#include "geometry_msgs/TwistStamped.h"
#include "messages/CobotRawStatus.h"

// using namespace cobot_msgs;

#define RAD(deg) ((deg) * M_PI / 180.0)


bool run = true;
CobotDrive* cobotDrive;
tf::TransformBroadcaster *tfBroadcaster;

void cobotDriveCallback(const geometry_msgs::TwistStampedPtr& msg) {
  cobotDrive->setSpeeds(msg->twist.linear.x, msg->twist.linear.y, msg->twist.angular.z);
}

void timerEvent( int sig ) {
  const bool debugTimer = false;
  const ros::Time tNow = ros::Time::now();
  static double tLast = tNow.toSec();
  static double tLastOdometry = tNow.toSec();
  if(debugTimer){
    printf( "dT = %f\n", tNow.toSec()-tLast );
    tLast = tNow.toSec();
  }
  cobotDrive->run();

  //Get raw drive message
  double vxRaw,vyRaw,vrRaw;
  cobotDrive->GetDriveRawFeedback(vxRaw,vyRaw,vrRaw);
  geometry_msgs::TwistStamped cobotDriveRawMsg;
  cobotDriveRawMsg.twist.linear.x = vxRaw;
  cobotDriveRawMsg.twist.linear.y = vyRaw;
  cobotDriveRawMsg.twist.angular.z = vrRaw;
  cobotDriveRawMsg.header.seq++;
  cobotDriveRawMsg.header.stamp = tNow;
  cobotDriveRawMsg.header.frame_id = "drive";
  cobotDriveRawPublisher.publish(cobotDriveRawMsg);

  //Get odometry messageicad
  double dr,dx,dy,v0,v1,v2,v3,vr,vx,vy,adc,curAngle;
  unsigned char status;
  vector2d curLoc;
  if(cobotDrive->GetFeedback(dr,dx,dy,v0,v1,v2,v3,vr,vx,vy,adc,status,curLoc,curAngle)){
    CobotOdometryMsg cobotOdometryMsg;
    //cobotOdometryMsg.dr = dr;
    //cobotOdometryMsg.dx = dx;
    //cobotOdometryMsg.dy = dy;
    //cobotOdometryMsg.v0 = v0;
    //cobotOdometryMsg.v1 = v1;
    //cobotOdometryMsg.v2 = v2;
    //cobotOdometryMsg.v3 = v3;
    //cobotOdometryMsg.vr = vr;
    //cobotOdometryMsg.vx = vx;
    //cobotOdometryMsg.vy = vy;
    //cobotOdometryMsg.VBatt = adc;
    //cobotOdometryMsg.status = status;

//
    //cobotOdometryMsg.header.seq++;
    //cobotOdometryMsg.header.stamp = tNow;
    //cobotOdometryMsg.header.frame_id = "odom";


    static nav_msgs::Odometry odometryMsg;
    odometryMsg.header.frame_id = "odom";
    odometryMsg.header.seq ++;
    odometryMsg.header.stamp = ros::Time::now();
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

    double dT = GetTimeSec() - tLastOdometry;
    tLastOdometry = GetTimeSec();
    static const double MaxTransSpeed = 3.0;
    static const double MaxRotSpeed = 360.0;
    if((std::pow(dx,2)+std::pow(dy,2))>std::pow(MaxTransSpeed/dT , 2) || fabs(dr)>RAD(MaxRotSpeed/dT)){
      std::cout << ("Odometry out of bounds! Dropping odometry packet.") << std::endl;
    }else{
      cobotRawStatusPublisher.publish(cobotOdometryMsg);

      tf::Transform transform;
      transform.setOrigin(tf::Vector3(curLoc[0],curLoc[1], 0.0));
      transform.setRotation(tf::Quaternion(tf::Vector3(1,0,0),curAngle));
      tfBroadcaster->sendTransform(
          tf::StampedTransform(transform, ros::Time::now(),
                               "odom", "base_footprint"));

      transform.setOrigin(tf::Vector3(0.0 ,0.0, 0.0));
      transform.setRotation(tf::Quaternion(0, 0, 0, 1));
      tfBroadcaster->sendTransform(
          tf::StampedTransform(transform, ros::Time::now(),
                               "base_footprint", "base_link"));

      odometryPublisher.publish(odometryMsg);
    }
  }
  if( !run ){
    CancelTimerInterrupts();
  }
}

int main(int argc, char **argv) {
  static const bool debug = false;
	if (debug) {
    ColourTerminal(TerminalUtils::TERMINAL_COL_WHITE,TerminalUtils::TERMINAL_COL_BLACK,TerminalUtils::TERMINAL_ATTR_BRIGHT);
    printf("\nCoBot Drive module\n\n");
    ResetTerminal();
	}
  int portNum = 0;
  // option table
  static struct poptOption options[] = {
    { "port-num", 'p', POPT_ARG_INT , &portNum,  0, "Laser Scanner serial port number", "NUM"},

    POPT_AUTOHELP
    { NULL, 0, 0, NULL, 0, NULL, NULL }
  };
  // parse options
  POpt popt(NULL,argc,(const char**)argv,options,0);
  int c;
  while((c = popt.getNextOpt()) >= 0){
  }

  motor_properties_t motorProps;
  motorProps.xyFlipped = true;
  motorProps.encoderCountsPerMeter = vector2d(-1.0,1.0)*30466.8;
  motorProps.encoderCountsPerRadian = 8701.6;
  motorProps.transMotionScale = vector2d(1.0,1.0)*8620.68965517241379310345;
  motorProps.rotMotionScale = -1736.11494888090632771484;
  cobotDrive = new CobotDrive(motorProps);

  char serialPort[256];
  sprintf(serialPort,"/dev/ttyUSB%d",portNum);
  if(debug) printf("Using port %s\n",serialPort);


  InitHandleStop(&run);
  AccelLimits transLimits, rotLimits;
  transLimits.set(1.0,2.0,2.5);
  rotLimits.set(1.0*M_PI,1.0*M_PI,1.5*M_PI);
  cobotDrive->setLimits(transLimits, rotLimits);
  cobotDrive->init(serialPort);
  //Interrupt frequency of 20 Hz
  if(!SetTimerInterrupt(50000, &timerEvent)){
    TerminalWarning( "Unable to set timer interrupt\n" );
    cobotDrive->close();
    return(1);
  }

  ros::init(argc, argv, "Cobot2_Drive_Module");
  ros::NodeHandle n;
  ros::Subscriber drive_sub = n.subscribe("Cobot/Drive", 1, cobotDriveCallback);
  ros::Publisher cobotRawStatusPublisher = n.advertise<nav_msgs::Odometry>("Cobot/RawStatus",1);
  ros::Publisher cobotDriveRawPublisher = n.advertise<geometry_msgs::TwistStamped>("Cobot/DriveRaw",1);
  tfBroadcaster = new tf::TransformBroadcaster();

  // main loop
  while(ros::ok() && run){
    ros::spinOnce();
    Sleep(0.01);
  }
  printf("closing.\n");
  cobotDrive->close();

  return(0);
}
