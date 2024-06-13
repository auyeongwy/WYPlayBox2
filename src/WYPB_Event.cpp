#include <cstring>
#include <iostream>
#include "WYPB_Event.hpp"
using namespace WYPlayBox;


WYPB_Event::WYPB_Event()
{
    WYPB_Time time;
    m_event_type = WYPB_EVENT_DEFAULT;
    m_priority = WYPB_EVENT_PRIORITY_NORMAL;
    m_time = time; /* Operator override. */
    std::memset(m_description, 0, EVENT_DESC_LEN);
}


WYPB_Event::WYPB_Event(const WYPB_Event_Type p_type, const WYPB_Time *__restrict__ p_time, const WYPB_Event_Priority p_priority, const char *__restrict__ p_desc)
{ 
    m_event_type = p_type;
    m_priority = p_priority;
    if(p_time == NULL) {
        WYPB_Time time;
        m_time = time; /* Using operator overload. */
    } else
        m_time = *p_time; /* Using operator overload. */
    std::memset(m_description, 0, EVENT_DESC_LEN); /* Defaults to 0. */
    if(p_desc != NULL)  /* Fill in the description if it is provided. */
        strncpy(m_description, p_desc, EVENT_DESC_LEN-1);
}


WYPB_Event::~WYPB_Event()
{

}


void WYPB_Event::describe() noexcept
{
    char tmp[64];
    m_time.to_cstring(tmp, 64);
    std::cout << " Priority:" << m_priority << " Type:" << m_event_type << " Time:" << tmp << "\n";
}


WYPB_Event& WYPB_Event::operator=(const WYPB_Event& p_event) noexcept
{
    m_priority = p_event.m_priority;
    m_event_type = p_event.m_event_type;
    m_time = p_event.m_time; /* Operator overload. */
    std::strncpy(m_description, p_event.m_description, EVENT_DESC_LEN);
    return *this;
}