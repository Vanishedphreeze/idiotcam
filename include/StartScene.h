#include "Scene.h"

#pragma once

#include "Predeclare.h"

class StartScene : public Scene {
private:
    Sprite redsq;
    Sprite yellowsq;

public:
    StartScene() {}
    virtual ~StartScene() {}
    void loadScene() override; // for loading resources
    void initialize() override; // for initialize
    void update() override; // this is called once per frame.
    void drawScene() const override; // this is also called once per frame. modifying scene members is not allowed.
    void unloadScene() override; // for unloading resources
};

