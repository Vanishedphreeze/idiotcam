#ifndef _RESOURCEMANAGER
#define _RESOURCEMANAGER

#pragma once

#include "Predeclare.h"
#include "BaseManager.h"

class ResourceManager : public BaseManager {
private:

public:
    ResourceManager() {}
    ~ResourceManager() {}
    void startUp() override;
    void shutDown() override;
};

#endif // _RESOURCEMANAGER
