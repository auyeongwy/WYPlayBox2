#include <utility>
#include <iostream>
#include "WYPB_Event_Mgr.hpp"

WYPB_Event_Mgr::WYPB_Event_Mgr()
{

}


WYPB_Event_Mgr::~WYPB_Event_Mgr()
{
    if(!m_event_queue.empty())
        m_event_queue.clear();
}


void WYPB_Event_Mgr::add_event(const WYPB_Event *__restrict__ p_event)
{
    const int priority = p_event->m_priority;
    if(priority != WYPB_EVENT_PRIORITY_WORLDTIME) {

        if(m_event_queue.empty()) /* Empty so just insert. */
            m_event_queue.push_back(std::move(*p_event));

        else { /* Go through the list and insert the new event according to its priority. */
            auto iter = m_event_queue.end(); /* Start from the back of the queue. */
            while(--iter != m_event_queue.begin()) {
                if(iter->m_priority <= priority) /* Found an event with equal or higher priority(lower priority numeral), insert after it. */
                    break;
            }
            m_event_queue.insert(++iter, std::move(*p_event));
        }

    } else  /* WYPB_EVENT_PRIORITY_WORLDTIME gets highest priority and get pushed to the front. */
        m_event_queue.push_front(std::move(*p_event));
}


int WYPB_Event_Mgr::pop_event(WYPB_Event *__restrict__ p_event) noexcept
{
    if(m_event_queue.size() == 0) /* Empty queue. */
        return -1; 
    else {
        *p_event = m_event_queue.front(); /* User override operator to copy the value. */
        m_event_queue.pop_front(); /* Remove the front item from the list. */
        return m_event_queue.size(); /* Return remaining number of items. */
    }
}


void WYPB_Event_Mgr::list_events() noexcept
{
    unsigned int num = 0;
    std::list<WYPB_Event>::iterator iter;
    for(iter = m_event_queue.begin(); iter != m_event_queue.end(); iter++) {
        std::cout << "Event " << ++num << " ";
        iter->describe();
    }
}
