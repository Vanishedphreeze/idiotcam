#include "Scene.h"

void Scene::_mainLoop() {
    while (isLoopRunning) {
        // Update.
        mCurTime = glfwGetTime();
        if (mCurTime > mPrevUpdateTime + 1 / FIXED_UPDATE_FPS) {
            update();
            //realtimeFPS = 1 / (curTime - prevTime);
            //std::cout << std::setprecision(5) << realtimeFPS << std::endl;
            mPrevUpdateTime = mCurTime;
        }

        // Draw. get current time again for the exact time.
        mCurTime = glfwGetTime();
        if (mCurTime > mPrevDrawTime + 1 / FIXED_RENDER_FPS) {
            gRenderManager.draw();
            //realtimeFPS = 1 / (curTime - prevTime);
            //std::cout << std::setprecision(5) << realtimeFPS << std::endl;
            mPrevDrawTime = mCurTime;
        }
    }
}

void Scene::_loopStart() {
    mPrevUpdateTime = mPrevDrawTime = glfwGetTime();
    isLoopRunning = true;
}

void Scene::exitScene() {
    isLoopRunning = false;
}
