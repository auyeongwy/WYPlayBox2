/*   
* Licensed to the Apache Software Foundation (ASF) under one
* or more contributor license agreements.  See the NOTICE file
* distributed with this work for additional information
* regarding copyright ownership.  The ASF licenses this file
* to you under the Apache License, Version 2.0 (the
* "License"); you may not use this file except in compliance
* with the License.  You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an
* "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
* KIND, either express or implied.  See the License for the
* specific language governing permissions and limitations
* under the License.    
*/

#pragma once
#include <ctime>

namespace WYPBPlayBox
{

/**
 * Enumerates the supported time formats.
*/
enum WYPB_Time_Type {
    WYPB_TIME_NUMERICAL, /**< Time as a simple numerical value. */
    WYPB_TIME_TIMESTAMP  /**< Time in timestamp format. Implemented by the C++ std::timespec. */
};


/**
 * Time class. Time can be measured as a simple incrementing whole number (WYPB_TIME_NUMERICAL) or timestamp (WYPB_TIME_TIMESTAMP).
 * WYPB_TIME_NUMERICAL: Uses std::timespec.tv_sec for the numerical time.<br>
 * WYPB_TIME_TIMESTAMP: Uses the whole std::timespect for the timestamp.<br>
*/
class WYPB_Time
{
public:
    /**
     * Constructor. Assumes type = WYPB_TIME_NUMERICAL and starting time is 0.
    */
    WYPB_Time();

    /**
    * Constructor.
    * @param p_type Time type. WYPB_TIME_NUMERICAL or WYPB_TIME_TIMESTAMP.
    * <br>WYPB_TIME_NUMERICAL: Time initialized as numerical 0.
    * <br>WYPB_TIME_TIMESTAMP: Time initialized with current timestamp.
    * @param p_time If not NULL, use the value provided here as the time. 
    * @param p_offset If WYPB_TIME_TIMESTAMP, sets the number of seconds to offset from UTC. E.g. for UTC+0800 set to 28,800. Defaults to 0.
    */
    WYPB_Time(const WYPB_Time_Type p_type, const std::timespec *__restrict__ p_time, const int p_offset=0);

    /** Destructor. */
    ~WYPB_Time();

    /**
    * Sets the time to the provided values.
    * @param p_type Time type. WYPB_TIME_NUMERICAL or WYPB_TIME_TIMESTAMP.
    * <br>WYPB_TIME_NUMERICAL: Time initialized as numerical 0.
    * <br>WYPB_TIME_TIMESTAMP: Time initialized with current timestamp.
    * @param p_time If not NULL, use the value provided here as the time. 
    * @param p_offset If WYPB_TIME_TIMESTAMP, sets the number of seconds to offset from UTC. E.g. for UTC+0800 set to 28,800. Defaults to 0.
    */
    void set_time(const WYPB_Time_Type p_type, const std::timespec *__restrict__ p_time, const int p_offset=0) noexcept;

    /**
     * Update to the latest time. <br>
     * If type is WYPB_TIME_NUMERICAL, increments m_time.tv_sec by 1.<br>
     * If type is WYPB_TIME_TIMESTAMP, perform a system call to get the current timestamp.
    */
    void update_time();

    /**
     * For convenience, overload = operator to assign values on a WYPB_Time object to another.
     * @param p_time The WYPB_Time object to assign from.
    */
    WYPB_Time& operator=(const WYPB_Time& p_time) noexcept;

    void to_cstring(char *__restrict__ p_value, const unsigned int p_size) noexcept;

private:
    WYPB_Time_Type m_type; /**< Type of time. */
    int m_offset; /**< Number of seconds to offset from UTC. E.g. for UTC+0800 this is 800x60x60. */
    std::timespec m_time; /**< Time value. If WYPB_TIME_NUMERICAL, uses m_time.tv_sec only. If WYPB_TIME_TIMESTAMP, uses the full std::timespec. */
};

}