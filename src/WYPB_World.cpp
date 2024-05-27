#include <iostream>
#include "WYPB_World.hpp"
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


void WYPB_World::run() noexcept
{
    char tmp[64];
    m_world_time.to_cstring(tmp, 64);
    std::cout << tmp << "\n";
    m_world_time.update_time();
    m_world_time.to_cstring(tmp, 64);
    std::cout << tmp << "\n";
}