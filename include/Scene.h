#ifndef _SCENE
#define _SCENE

#pragma once

#include "Predeclare.h"
#include "RenderManager.h"
#include "InputManager.h"

#define FIXED_UPDATE_FPS 60.0
#define FIXED_RENDER_FPS 60.0

extern RenderManager gRenderManager;
extern InputManager gInputManager;

class Camera;

class Scene {
    // Do put resources, objects, cameras, etc into recourse map as much as possible.

private:
    bool isLoopRunning = false;
    float mPrevRenderTime, mPrevUpdateTime, mUpdateLagTime, mCurTime, mRealtimeUpdateFPS, mRealtimeRenderFPS;
    void _mainLoop();

public:
    Camera defaultCamera;
    Scene() : defaultCamera(0, 0, 1, 100) {}
    virtual ~Scene() {}
    virtual void loadScene() = 0; // for loading resources
    virtual void initialize() = 0; // for initialize
    void _loopStart(); // for starting the scene(loop). this is not available to users.
    virtual void update() = 0; // this is called once per frame.
    void setNextScene(const Scene& scene);
    void exitScene(); // for exiting from scene and move into next scene. this can be directly called by users.
    virtual void unloadScene() = 0; // for unloading resources

    // load/unload resources should be done automatically by engine. this should be discussed later.
    // Important
    // how can we know that which scene should we go? games may not linear.
};

#endif // _SCENE
