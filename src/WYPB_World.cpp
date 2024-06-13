#include <iostream>
#include "WYPB_World.hpp"
#include "WYPB_Event_0Time.hpp"
using namespace WYPlayBox;

WYPB_World::WYPB_World(const WYPB_Time_Type p_type, const std::timespec *__restrict__ p_time, const int p_offset)
{
    m_world_time.set_time(p_type, p_time, p_offset);
}


WYPB_World::~WYPB_World()
{

}


void WYPB_World::get_world_time(WYPB_Time *__restrict__ const p_time) noexcept
{
    *p_time = m_world_time; /* Using operator overload. */
}


void WYPB_World::update_world_time(WYPB_Time *__restrict__ const p_time) noexcept
{
    m_world_time.update_time();
    if(p_time != NULL) 
        *p_time = m_world_time; /* Using operator overload. */
}


void WYPB_World::get_new_event_time(WYPB_Event *__restrict__ const p_event) noexcept
{
    m_world_time.update_time();
    p_event->m_time = m_world_time; /* Using operator overload. */
}


void WYPB_World::add_to_eventmgr(const WYPB_Event *__restrict__ p_event) noexcept
{
    m_event_mgr.add_event(p_event);
}


void WYPB_World::run() noexcept
{
    test_events();
    list_events();
}


void WYPB_World::test_time() noexcept
{
    char tmp[64];
    m_world_time.to_cstring(tmp, 64);
    std::cout << tmp << "\n";
    m_world_time.update_time();
    m_world_time.to_cstring(tmp, 64);
    std::cout << tmp << "\n";
}


void WYPB_World::test_events() noexcept
{
    WYPB_Event event;
    WYPB_Time time;

    get_new_event_time(&event);
    add_to_eventmgr(&event);
    get_new_event_time(&event);
    add_to_eventmgr(&event);
    update_world_time(&time);
    event.modify(WYPB_EVENT_DEFAULT, &time, WYPB_EVENT_PRIORITY_WORLDTIME, NULL);
    add_to_eventmgr(&event);
    update_world_time(&time);
    event.modify(WYPB_EVENT_DEFAULT, &time, WYPB_EVENT_PRIORITY_NORMAL, NULL);
    add_to_eventmgr(&event);
}


void WYPB_World::list_events() noexcept
{
    m_event_mgr.list_events();
}
