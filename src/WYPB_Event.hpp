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
#include "WYPB_EventDefs.hpp"
#include "WYPB_Time.hpp"
using namespace WYPBPlayBox;

namespace WYPlayBox
{
#define EVENT_DESC_LEN 32 /**< Max size of the event description. */

/**
 * Describes an event processed by the WYPlayBox simulator.
 * 
 * This class can be used as it is. But it is also created to be inherited by any event class.
*/
class WYPB_Event
{
public:
    /**
     * Simple convenience constructor for fast initialization. 
     * Creates a WYPB_Event object with the attributes:<br>
     * Type: WYPB_EVENT_DEFAULT<br>
     * Time: WYPB_TIME_NUMERICAL with time=0.<br>
     * Priority: WYPB_EVENT_PRIORITY_NORMAL<br>
     * Description: NULL<br>
     * 
    */
    WYPB_Event();

    /** Constructor. 
     * @param p_type Type of event.
     * @param p_time Time of the event. 
     * @param p_priority Priority of the event. Defaults to WYPB_EVENT_PRIORITY_1.
     * @param p_desc Text description of the event. This can be returned by the describe() function. Defaults to "".
    */
    WYPB_Event(const WYPB_Event_Type p_type, const WYPB_Time *__restrict__ p_time, const WYPB_Event_Priority p_priority=WYPB_EVENT_PRIORITY_NORMAL,  const char *__restrict__ p_desc=NULL);

    /** Destructor. */
    virtual ~WYPB_Event();

    /**
     * Returns a text description of the event, if it was set during object construction.
    */
    char* describe() noexcept;

    /**
     * Overload the @b = operator to easily copy the values of one WYPB_Event to another.
     * @param p_event The WYPB_Event to copy from.
    */
    WYPB_Event& operator=(const WYPB_Event& p_event) noexcept;

    int m_priority; /**< Event priority. */
    int m_event_type; /**< Type of event. */
    WYPB_Time m_time; /**< Time of the event. */
    char m_description[EVENT_DESC_LEN]; /**< A text description of the event. */
};

}
