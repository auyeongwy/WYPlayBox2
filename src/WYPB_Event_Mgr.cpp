#include "WYPB_Event_Mgr.hpp"

WYPB_Event_Mgr::~WYPB_Event_Mgr()
{
    if(!m_event_queue.empty())
        m_event_queue.clear();
}