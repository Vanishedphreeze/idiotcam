#ifndef _SCENEMANAGER
#define _SCENEMANAGER

#pragma once

#include "BaseManager.h"
#include "Scene.h"
#include "StartScene.h"

class SceneManager : public BaseManager {
private:
    std::unique_ptr<Scene> pPresScene;
    //std::unique_ptr<Scene> pNextScene;

public:
    SceneManager() {}
    ~SceneManager() {}
    void startUp() override;
    void shutDown() override;
    void runScene();
};

#endif // _SCENEMANAGER

