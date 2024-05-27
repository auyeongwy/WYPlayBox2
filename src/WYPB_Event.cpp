#include <cstring>
#include "WYPB_Event.hpp"
using namespace WYPlayBox;

WYPB_Event::WYPB_Event(const WYPB_Event_Type p_type, const WYPB_Time *__restrict__ p_time, const WYPB_Event_Priority p_priority,  char *__restrict__ p_desc)
{ 
    m_event_type = p_type;
    m_priority = p_priority;
    m_time = *p_time; /* Using operator overload. */
    std::memset(m_description, 0, EVENT_DESC_LEN); /* Defaults to 0. */
    if(p_desc != NULL)  /* Fill in the description if it is provided. */
        strncpy(m_description, p_desc, EVENT_DESC_LEN-1);
}


WYPB_Event::~WYPB_Event()
{

}


char* WYPB_Event::describe()
{
    return m_description;
}
