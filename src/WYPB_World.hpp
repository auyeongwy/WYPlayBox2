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
#include "WYPB_Time.hpp"
using namespace WYPBPlayBox;
namespace WYPlayBox
{

/**
 * Implements a world in a WYPB_PlayBox instance.
*/
class WYPB_World
{
public:
    /**
     * Constructor.
     * @param p_type Determines the time type. WYPB_TIME_NUMERICAL = numerical value. WYPB_TIME_TIMESTAMP = timestamp value.
     * @param p_time If not NULL, manually sets the time of the time object.
     * @param p_offset Only applicable for WYPB_TIME_TIMESTAMP. The timezone offset in seconds. E.g. for UTC+0800 this is 28,800. Defaults to 0.
    */
    WYPB_World(const WYPB_Time_Type p_type, const std::timespec *__restrict__ p_time, const int p_offset=0);

    /** Destructor. */
    ~WYPB_World();

    /**
     * Returns the current world time tracked by WYPB_World. This does not update the world time. 
     * @param p_time Returns the current world time.
    */
    void get_world_time(WYPB_Time *__restrict__ const p_time) noexcept;

    /**
     * Updates the world time and optionally returns the updated time.
     * @param p_time If not NULL, returns the updated world time.
    */
    void update_world_time(WYPB_Time *__restrict__ const p_time) noexcept;

    void run() noexcept;

private:
    WYPB_Time m_world_time; /**< Tracks the world time. The default initialised values can be updated later in the constructor. */
};

} 
