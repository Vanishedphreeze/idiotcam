#include "Scene.h"

void Scene::_mainLoop() {
    int cntUpdateFrames;
    while (isLoopRunning) {
        if (glfwWindowShouldClose(gRenderManager.getWindowHandle())) {
            exitScene();
            break;
        }
        glfwPollEvents();

        // is kind of looping does not update in 60fps accurately.
        // Update.
        cntUpdateFrames = 0;
        mCurTime = glfwGetTime();
        if (mCurTime > mPrevUpdateTime + 1 / FIXED_UPDATE_FPS) {
            // if lag larger then update frames, update until caught up.
            mUpdateLagTime += mCurTime - mPrevUpdateTime;
            while (mUpdateLagTime > 1 / FIXED_UPDATE_FPS) {
                gInputManager.updateKeyState();
                update();
                cntUpdateFrames++;
                mUpdateLagTime -= 1 / FIXED_UPDATE_FPS;
            }
            mRealtimeUpdateFPS = cntUpdateFrames / (mCurTime - mPrevUpdateTime);
            mPrevUpdateTime = mCurTime;
        }

        // Draw. get current time again for the exact time.
        mCurTime = glfwGetTime();
        if (mCurTime > mPrevRenderTime + 1 / FIXED_RENDER_FPS) {
            gRenderManager.drawRenderQueue(defaultCamera);
            mRealtimeRenderFPS = 1 / (mCurTime - mPrevRenderTime);
            mPrevRenderTime = mCurTime;
        }
    }
}

void Scene::_loopStart() {
    mPrevUpdateTime = mPrevRenderTime = glfwGetTime();
    mUpdateLagTime = 0;
    isLoopRunning = true;
    _mainLoop();
}

void Scene::setNextScene(const Scene& scene) {

}

void Scene::exitScene() {
    isLoopRunning = false;
}
