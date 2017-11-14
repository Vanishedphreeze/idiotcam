#include "Scene.h"

#pragma once

#include "Predeclare.h"

class StartScene : public Scene {
private:
    Sprite* redsq;
    Sprite* yellowsq;
    // this is only for testing. use resource map when available.

public:
    StartScene() {}
    virtual ~StartScene();
    void loadScene() override; // for loading resources
    void initialize() override; // for initialize
    void update() override; // this is called once per frame.
    void unloadScene() override; // for unloading resources
};

