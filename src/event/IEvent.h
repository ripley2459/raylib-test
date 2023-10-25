#ifndef RAYLIB_TEST_IEVENT_H
#define RAYLIB_TEST_IEVENT_H

#include "raylib.h"
#include <string>

class IEvent {
public:
    [[nodiscard]] virtual const std::string &getName() const = 0;
};


#endif
