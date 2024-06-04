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
#include <list>
#include "WYPB_Event.hpp"
using namespace WYPlayBox;

namespace WYPlayBox
{

/**
 * Utility class that manages a list of events. 
 * This uses a FIFO queue, but supports the m_priority attribute in WYPB_Event and will automatically insert events in the queue based on priority.
*/
class WYPB_Event_Mgr
{
public:
    /**
     * Constructor.
    */
    WYPB_Event_Mgr();

    /**
     * Destructor.
    */
    virtual ~WYPB_Event_Mgr();

    /**
     * Adds a new WYPB_Event to the event queue, FIFO-style.
     * @param p_event A valid WYPB_Event to be added to the event queue. @b std::list is used to copy the content of @b p_event so @b p_event content may be emptied after this function call. 
    */
    void add_event(const WYPB_Event *__restrict__ p_event);

    /**
     * Pops the next event, FIFO-style.
     * @param p_event Returns the event to be popped. p_event MUST be a valid initialized WYPB_Event object for the content to be written. If the queue is empty, the data is not modified.
     * @return Number of events left in the event queue. If the queue is empty, -1 is returned.
    */
    int pop_event(WYPB_Event *__restrict__ p_event) noexcept;

protected:
    std::list<WYPB_Event> m_event_queue; /**< Queue of events. */
};

}