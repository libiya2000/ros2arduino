// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _STD_MSGS_INT8_HPP_
#define _STD_MSGS_INT8_HPP_


#include <topic_config.h>
#include <topic.hpp>


namespace std_msgs {


class Int8 : public ros2::Topic<Int8>
{
public:
  uint8_t data;

  Int8():
    Topic("std_msgs::msg::dds_::Int8_", STD_MSGS_INT8_TOPIC),
    data(0)
  { 
  }

  bool serialize(ucdrBuffer* writer, const Int8* topic)
  {
    (void) ucdr_serialize_uint8_t(writer, topic->data);

    return !writer->error;
  }

  bool deserialize(ucdrBuffer* reader, Int8* topic)
  {
    (void) ucdr_deserialize_uint8_t(reader, &topic->data);

    return !reader->error;
  }

  uint32_t size_of_topic(const Int8* topic, uint32_t size)
  {
    (void)(topic);

    uint32_t previousSize = size;
    size += ucdr_alignment(size, 1) + 1;

    return size - previousSize;
  }

};

} // namespace std_msgs


#endif // _STD_MSGS_INT8_HPP_
