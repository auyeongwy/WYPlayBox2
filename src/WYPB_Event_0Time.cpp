#include <cstring>
#include "WYPB_Event_0Time.hpp"
#include "WYPB_EventDefs.hpp"

WYPB_Event_0Time::WYPB_Event_0Time() : 
WYPB_Event(WYPB_EVENT_0_TIME, new WYPB_Time(), WYPB_EVENT_PRIORITY_WORLDTIME, "Resets all numerical time to zero.")
{
    
}


WYPB_Event_0Time::~WYPB_Event_0Time()
{

}