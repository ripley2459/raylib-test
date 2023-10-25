#ifndef RAYLIB_TEST_EVENT_H
#define RAYLIB_TEST_EVENT_H


#include <functional>
#include <utility>
#include "IEvent.h"

template<typename ..._args> class Event : public IEvent {
public:
    using _callback = std::function<void(_args...)>;

    explicit Event(std::string name, const _callback &cb) : _name(std::move(name)), _cbFunc(cb) {}

    ~Event() = default;

    [[nodiscard]] const std::string &getName() const override {
        return this->_name;
    }

    void trigger(_args... a) {
        this->_cbFunc(a...);
    }

private:
    std::string _name;
    _callback const _cbFunc;
};


#endif
