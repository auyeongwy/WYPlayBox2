#include <utility>
#include "WYPB_Event_Mgr.hpp"

WYPB_Event_Mgr::WYPB_Event_Mgr()
{

}


WYPB_Event_Mgr::~WYPB_Event_Mgr()
{
    if(!m_event_queue.empty())
        m_event_queue.clear();
}


// void WYPB_Event_Mgr::add_event(const WYPB_Event *__restrict__ p_event)
// {
//     const int priority = p_event->m_priority;
//     if(priority != WYPB_EVENT_PRIORITY_WORLDTIME) {
//         if(m_event_queue.empty()) /* Empty so just insert. */
//             m_event_queue.push_back(*p_event);
//         else {
//             int i=0;
//             auto iter = m_event_queue.end();
//             while(std::prev(iter, ++i) != m_event_queue.begin()) {
//                 if((*iter).m_priority <= priority)
//                     break;
//             }
//             m_event_queue.insert(std::prev(iter,i+1), std::move(*p_event));
//         }
//     } else /* WYPB_EVENT_PRIORITY_WORLDTIME gets highest priority and get pushed to the front. */
//         m_event_queue.push_front(std::move(*p_event));
// }


int WYPB_Event_Mgr::pop_event(WYPB_Event *__restrict__ p_event)
{
    if(m_event_queue.size() == 0) /* Empty queue. */
        return 0; 
    else {
        *p_event = m_event_queue.front(); /* User override operator to copy the value. */
        m_event_queue.pop_front(); /* Remove the front item from the list. */
        return m_event_queue.size(); /* Return remaining number of items. */
    }
}
