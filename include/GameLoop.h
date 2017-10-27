#ifndef _GAMELOOP
#define _GAMELOOP

#pragma once

#include "include/Predeclare.h"

extern RenderManager gRenderManager;

class GameLoop {
private:
    bool isLoopRunning = false;
    float mPrevDrawTIme, mPrevUpdateTime, mCurTime, mRealtimeFPS;

    void mainLoop() {
        while (isLoopRunning) {
            // Update.
            mCurTime = glfwGetTime();
            if (mCurTime > mPrevUpdateTime + cFixedUpdateRefreshPeriod) {


                //realtimeFPS = 1 / (curTime - prevTime);
                //std::cout << std::setprecision(5) << realtimeFPS << std::endl;

                mPrevUpdateTime = mCurTime;
            }

            // Draw. get current time again for the exact time.
            mCurTime = glfwGetTime();
            if (mCurTime > mPrevDrawTIme + cFixedDrawRefreshPeriod) {
                gRenderManager.draw();

                //realtimeFPS = 1 / (curTime - prevTime);
                //std::cout << std::setprecision(5) << realtimeFPS << std::endl;

                mPrevDrawTIme = mCurTime;
            }
        }
    }

public:
    const float cFixedUpdateFPS;
    const float cFixedUpdateRefreshPeriod;
    const float cFixedDrawFPS;
    const float cFixedDrawRefreshPeriod;

    void start() {
        mPrevTime = glfwGetTime();
        isLoopRunning = true;
    }
};

GameLoop::cFixedUpdateFPS = 60.0;
GameLoop::cFixedUpdateRefreshPeriod = 1 / GameLoop::cFixedUpdateFPS;
GameLoop::cFixedDrawFPS = 60.0;
GameLoop::cFixedDrawRefreshPeriod = 1 / GameLoop::cFixedDrawFPS;

#endif // _GAMELOOP
