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

/**
 * @file WYPB_EventDefs.hpp
 * A header file to assign a numerical value to event types specific to the implementation. 
 * 
 * @b Example <br>
 * <code>
 * #define EVENT_MONEY_EARNED 101
 * #define EVENT_MONEY_LOST 102
 * <endcode> 
*/

#pragma once
namespace WYPlayBox
{

enum WYPB_Event_Priority {
    WYPB_EVENT_PRIORITY_0,
    WYPB_EVENT_PRIORITY_1,
    WYPB_EVENT_PRIORITY_2
};

enum WYPB_Event_Type {
    WYPB_EVENT_DEFAULT
};

/* All implmentation-specific event types here. */
}