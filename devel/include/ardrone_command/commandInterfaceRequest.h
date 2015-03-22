// Generated by gencpp from file ardrone_command/commandInterfaceRequest.msg
// DO NOT EDIT!


#ifndef ARDRONE_COMMAND_MESSAGE_COMMANDINTERFACEREQUEST_H
#define ARDRONE_COMMAND_MESSAGE_COMMANDINTERFACEREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ardrone_command/serialized_ardrone_command.h>

namespace ardrone_command
{
template <class ContainerAllocator>
struct commandInterfaceRequest_
{
  typedef commandInterfaceRequest_<ContainerAllocator> Type;

  commandInterfaceRequest_()
    : command()  {
    }
  commandInterfaceRequest_(const ContainerAllocator& _alloc)
    : command(_alloc)  {
    }



   typedef  ::ardrone_command::serialized_ardrone_command_<ContainerAllocator>  _command_type;
  _command_type command;




  typedef boost::shared_ptr< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct commandInterfaceRequest_

typedef ::ardrone_command::commandInterfaceRequest_<std::allocator<void> > commandInterfaceRequest;

typedef boost::shared_ptr< ::ardrone_command::commandInterfaceRequest > commandInterfaceRequestPtr;
typedef boost::shared_ptr< ::ardrone_command::commandInterfaceRequest const> commandInterfaceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ardrone_command

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'ardrone_command': ['/home/hewhosurvives/c++/randomProjects/ros/catkin_ws/src/ardrone_command/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1a4b282ca88ee0d79c0d0ed9262007d4";
  }

  static const char* value(const ::ardrone_command::commandInterfaceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1a4b282ca88ee0d7ULL;
  static const uint64_t static_value2 = 0x9c0d0ed9262007d4ULL;
};

template<class ContainerAllocator>
struct DataType< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ardrone_command/commandInterfaceRequest";
  }

  static const char* value(const ::ardrone_command::commandInterfaceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "serialized_ardrone_command command\n\
\n\
================================================================================\n\
MSG: ardrone_command/serialized_ardrone_command\n\
#ROS message format doesn't support recursive definitions (a message type cannot contain more messages of the same type), so commands will have to be decomposed when they are serialized and will not be exactly the same on the other side\n\
serialized_ardrone_command_part command\n\
serialized_ardrone_command_part[] subcommands \n\
\n\
\n\
================================================================================\n\
MSG: ardrone_command/serialized_ardrone_command_part\n\
uint32 type\n\
string[] strings\n\
float64[] doubles\n\
int64[] integers\n\
uint32[] flightAnimations\n\
uint32[] ledAnimations\n\
";
  }

  static const char* value(const ::ardrone_command::commandInterfaceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct commandInterfaceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ardrone_command::commandInterfaceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ardrone_command::commandInterfaceRequest_<ContainerAllocator>& v)
  {
    s << indent << "command: ";
    s << std::endl;
    Printer< ::ardrone_command::serialized_ardrone_command_<ContainerAllocator> >::stream(s, indent + "  ", v.command);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ARDRONE_COMMAND_MESSAGE_COMMANDINTERFACEREQUEST_H
