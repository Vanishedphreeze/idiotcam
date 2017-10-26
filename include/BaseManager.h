#pragma once

#include "Predeclare.h"

class BaseManager {
public:
    BaseManager() {}
    virtual ~BaseManager() {}
    virtual void startUp() = 0;
    virtual void shutDown() = 0;
};
