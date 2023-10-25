#include "EventDispatcher.h"
#include "Event.h"

EventDispatcher::EventDispatcher() = default;

EventDispatcher::~EventDispatcher() {
    for (const auto &el: _eventList) {
        for (auto e: el.second) {
            delete e;
        }
    }
}

void EventDispatcher::registerEvent(IEvent *event) {
    if (event) _eventList[event->getName()].push_back(event);
}

template<typename ..._args> void EventDispatcher::dispatchEvent(const std::string &eventName, _args...a) {
    auto it_eventList = _eventList.find(eventName);

    if (it_eventList == _eventList.end()) return;

    for (auto ie: it_eventList->second) {
        if (auto *event = dynamic_cast<Event<_args...> * > (ie)) event->trigger(a...);
    }
}
