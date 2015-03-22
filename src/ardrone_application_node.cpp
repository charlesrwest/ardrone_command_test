#include "ros/ros.h"
#include "std_msgs/Empty.h"
#include <unistd.h>
#include "ardrone_command/serialized_ardrone_command.h"
#include "ardrone_command/commandInterface.h"
#include "command.hpp"

int main(int argc, char** argv)
{


ros::init(argc, argv, "ardrone_command_test");
ros::NodeHandle nodeHandle;

std::vector<command> commands;

command commandWait;
commandWait.setWaitCommand(2.0);
commands.push_back(commandWait);


//Make commands to send
command commandTakeoff;
commandTakeoff.setTakeoffCommand();
commands.push_back(commandTakeoff);


command commandSetTargetAltitude;
commandSetTargetAltitude.setTargetAltitudeCommand(500.0);
commands.push_back(commandSetTargetAltitude);

command commandWaitUntilTargetAltitudeReached;
commandWaitUntilTargetAltitudeReached.setWaitUntilAltitudeReached(10.0);
commands.push_back(commandWaitUntilTargetAltitudeReached);

command commandWaitForQRCode;
commandWaitForQRCode.setWaitUntilSpecificQRCodeIsSpottedCommand("BigQRCode", 3.0);
commands.push_back(commandWaitForQRCode);

command commandLookAtQRCodePoint;
commandLookAtQRCodePoint.setMaintainOrientationTowardSpecificQRCode("BigQRCode");
commands.push_back(commandLookAtQRCodePoint);

command commandGoToQRCodePoint;
commandGoToQRCodePoint.setMaintainPositionAtSpecificQRCodePoint("BigQRCode", .5, 0.0, 3.0+.5);
commands.push_back(commandGoToQRCodePoint);


command QRCodePointWait1; QRCodePointWait1.setWaitUntilPositionAtSpecificQRCodePointReachedCommand(10.0);
commands.push_back(QRCodePointWait1);

command commandGoToQRCodePoint2;
commandGoToQRCodePoint2.setMaintainPositionAtSpecificQRCodePoint("BigQRCode", .5, 0.0, 3.0-.5);
commands.push_back(commandGoToQRCodePoint2);

commands.push_back(QRCodePointWait1);


command commandGoToQRCodePoint3;
commandGoToQRCodePoint3.setMaintainPositionAtSpecificQRCodePoint("BigQRCode", -.5, 0.0, 3.0-.5);
commands.push_back(commandGoToQRCodePoint3);

commands.push_back(QRCodePointWait1);


command commandGoToQRCodePoint4;
commandGoToQRCodePoint4.setMaintainPositionAtSpecificQRCodePoint("BigQRCode", -.5, 0.0, 3.0+.5);
commands.push_back(commandGoToQRCodePoint4);

commands.push_back(QRCodePointWait1);


command commandGoToQRCodePoint5;
commandGoToQRCodePoint5.setMaintainPositionAtSpecificQRCodePoint("BigQRCode", .5, 0.0, 3.0+.5);
commands.push_back(commandGoToQRCodePoint5);

commands.push_back(QRCodePointWait1);

command commandWait2;
commandWait2.setWaitCommand(2.0);
commands.push_back(commandWait2);

command commandCancelMaintainPositionAtQRCodePoint;
commandCancelMaintainPositionAtQRCodePoint.setCancelMaintainPositionAtSpecificQRCodePoint();
commands.push_back(commandCancelMaintainPositionAtQRCodePoint);


command commandCancelLookAtQRCodePoint;
commandCancelLookAtQRCodePoint.setCancelMaintainOrientationTowardSpecificQRCode();
commands.push_back(commandCancelLookAtQRCodePoint);




//Serialize and send commands
ardrone_command::commandInterface interface;
for(int i=0; i<commands.size(); i++)
{
auto commandMessage = commands[i].serialize();
ardrone_command::commandInterface::Request request;
request.command = commandMessage;

ardrone_command::commandInterface::Response response;

ros::service::call("/ardrone_command/commandInterface", request, response);
}



ros::shutdown();

return true;
}




