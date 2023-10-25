#ifndef RAYLIB_TEST_EVENTDISPATCHER_H
#define RAYLIB_TEST_EVENTDISPATCHER_H

#include "raylib.h"
#include <map>
#include <string>
#include <vector>
#include "IEvent.h"

class EventDispatcher {
public:
    EventDispatcher();

    virtual ~EventDispatcher();

private:
    std::map<std::string, std::vector<IEvent *>> _eventList;

    void registerEvent(IEvent *event);

    template<typename ..._args> void dispatchEvent(const std::string &eventName, _args... a);
};


#endif
