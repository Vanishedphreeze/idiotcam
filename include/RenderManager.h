// Because of an unknown problem, mInfo.flag.stereo should be 0.
#ifndef _RENDERMANAGER
#define _RENDERMANAGER

#pragma once

#define TITLE         "Idiotcam Example"
#define WINDOW_WIDTH  1024
#define WINDOW_HEIGHT 768

#include "BaseManager.h"
#include "ShaderProgram.h"
#include "Sprite.h"
#include "Camera.h"

class Sprite;
class Camera;

class RenderManager : public BaseManager {
private:
    GLuint mVBO, mVAO;
    GLFWwindow* mGameWindowHandle;
    struct APPINFO {
        char title[128];
        int windowWidth;
        int windowHeight;
        int majorVersion = 4;
        int minorVersion = 3;
        int samples = 1;
        struct {
            unsigned int    fullscreen  : 1;
            unsigned int    vsync       : 1;
            unsigned int    cursor      : 1;
            unsigned int    stereo      : 1;
            unsigned int    debug       : 1;
        } flags;
    } mInfo;

    int mSpriteIndexCounter = 0;
    void setupVertexBuffer(); // in a 2D game engine, the only shape we will use is rectangular.
    std::vector<ShaderProgram*> mShaderProgramPool; // this will create tons of dangling pointers. Be careful.
    std::map<int, Sprite*> mRenderQueue;
    Camera* mDefaultCam; // this could be changed into a queue or anything other.

public:
    RenderManager() {}
    ~RenderManager() {}
    void startUp() override;
    void shutDown() override;
    GLFWwindow* getWindowHandle() const;
    ShaderProgram* getDefaultShader() const; // this function should be in getDefaultResources
    Camera* getDefaultCamera() const;
    int addSpriteToRenderQueue(Sprite* sprite);
    void clearWindow();
    void removeSpriteFromRenderQueue(int index);
    void drawRenderQueue();
};

#endif // _RENDERMANAGER





