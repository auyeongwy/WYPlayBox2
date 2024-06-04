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
#include "WYPB_Event.hpp"
using namespace WYPlayBox;

namespace WYPlayBox
{

/**
 * An event to signal a time reset when time is set to WYPB_TIME_NUMERICAL.
 * The intention is that when it is necessary to reset time to 0, this event is sent to all entities in the simulator and all the entities will have to reset their own time values.
*/
class WYPB_Event_0Time : public WYPB_Event
{
public:
    /**
     * Constructor. 
     * This creates an event with the attributes:<br>
     * Event type: WYPB_EVENT_0_TIME<br> 
     * Time: WYPB_TIME_NUMERICAL and value 0<br>
     * Priority: WYPB_EVENT_PRIORITY_WORLDTIME<br>
    */
    WYPB_Event_0Time();

    /**
     * Destructor.
    */
    ~WYPB_Event_0Time();
};

}