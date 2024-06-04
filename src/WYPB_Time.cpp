#include <cstring>
#include <cstdio>
#include "WYPB_Time.hpp"
using namespace WYPBPlayBox;


WYPB_Time::WYPB_Time()
{
    set_time(WYPB_TIME_NUMERICAL, NULL);
}


WYPB_Time::WYPB_Time(const WYPB_Time_Type p_type, const std::timespec *__restrict__ p_time, const int p_offset)
{
    set_time(p_type, p_time, p_offset);
}


WYPB_Time::~WYPB_Time()
{

}


void WYPB_Time::set_time(const WYPB_Time_Type p_type, const std::timespec *__restrict__ p_time, const int p_offset) noexcept
{
    m_type = p_type;
    m_offset = p_offset;
    std::memset(&m_time, 0, sizeof(std::timespec)); /* Init values to 0. */
    if(p_time != NULL) /* Use the provided value. */
        memcpy(&m_time, p_time, sizeof(std::timespec));
    else if(m_type == WYPB_TIME_TIMESTAMP) /* If pre-defined time is not provided and type is WYPB_TIME_TIMESTAMP, get current timestamp.*/
        update_time();
}


void WYPB_Time::update_time() noexcept
{
    if(m_type == WYPB_TIME_NUMERICAL)
        ++m_time.tv_sec;
    else {
        std::timespec_get(&m_time, TIME_UTC);
        m_time.tv_sec += m_offset; /* Add the timezone offset. */
    }
}


WYPB_Time& WYPB_Time::operator=(const WYPB_Time& p_time) noexcept
{
    m_type = p_time.m_type;
    m_offset = p_time.m_offset;
    memcpy(&m_time, &(p_time.m_time), sizeof(std::timespec));
    return *this;
}


void WYPB_Time::to_cstring(char *__restrict__ p_value, const unsigned int p_size) noexcept
{
    if(m_type == WYPB_TIME_NUMERICAL)
        snprintf(p_value, p_size, "%ld", m_time.tv_sec);
    else {
        int tmp = strftime(p_value, p_size, "%F %T", gmtime(&m_time.tv_sec)); /* Date and time. */
        snprintf(p_value+tmp, p_size-tmp, ".%06ld", m_time.tv_nsec/1000);
    }
}