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
#include "WYPB_World.hpp"
namespace WYPlayBox
{

/**
 * Implements the main class of the WYPlayBox library. This is the entry-point to the library.
 * 
 * @b Example <br>
 * @code
 * #include <exception>
 * #include "WYPB_PlayBox"
 * using namespace WYPBPlayBox;
 * // ...
 * try {
 *      WYPB_PlayBox playbox;
 * } catch (exception &e) {
 *      // Diagnose the exception.
 * }
 * @endcode
*/
class WYPB_PlayBox
{
public:
    /** Constructor. */
    WYPB_PlayBox();

    /** Destructor. */
    ~WYPB_PlayBox();

    void run() noexcept;

private:
    WYPB_World *m_world = NULL; /**< WYPB_World object. */
}; 

}
