// Because of an unknown problem, mInfo.flag.stereo should be 0.
#ifndef _RENDERMANAGER
#define _RENDERMANAGER

#pragma once

#define TITLE         "Idiotcam Example"
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#include "BaseManager.h"
#include "ShaderProgram.h"
#include "Sprite.h"

class Sprite;

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
        union {
            struct {
                unsigned int    fullscreen  : 1;
                unsigned int    vsync       : 1;
                unsigned int    cursor      : 1;
                unsigned int    stereo      : 1;
                unsigned int    debug       : 1;
            };
            unsigned int        all;
        } flags;
    } mInfo;

    void setupVertexBuffer(); // in a 2D game engine, the only shape we will use is rectangular.
    std::vector<ShaderProgram*> mShaderProgramPool; // this will create tons of dangling pointers. Be careful.
    std::vector<Sprite*> mRenderQueue; // this would be a map sooner.

public:
    RenderManager() {};
    ~RenderManager() {};
    void startUp() override;
    void shutDown() override;
    GLFWwindow* getWindowHandle();
    ShaderProgram* getDefaultShader(); // this function should be in getDefaultResources
    void addSpriteToRenderQueue(Sprite*);
    void draw(); // this function would be drawRenderQueue sooner.
};

#endif // _RENDERMANAGER





