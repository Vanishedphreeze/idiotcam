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
            //drawRenderQueue(defaultCamera);
            _drawScene();
            mRealtimeRenderFPS = 1 / (mCurTime - mPrevRenderTime);
            mPrevRenderTime = mCurTime;
        }
    }
}

void Scene::_drawScene() const {
    // Render
    // Clear the colorbuffer
    clearWindow();

    // Draw
    // bind/unbind VAO is now in startup/shutdown.
    //(mShaderProgramPool[0])->activate(); // Optimize. if the shader program is the same as the former one, then THIS is not necessary.
    drawScene();

    // Swap the screen buffers
    glfwSwapBuffers(gRenderManager.getWindowHandle());
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

/*
int Scene::addSpriteToRenderQueue(Sprite& sprite) {
    mRenderQueue.insert(std::pair<int, Sprite&> (mSpriteIndexCounter, sprite));
    return sprite.mIndex = mSpriteIndexCounter++;
}
*/

/*
void Scene::removeSpriteFromRenderQueue(Sprite& sprite) {
    mRenderQueue.erase(sprite.mIndex);
}
*/

void Scene::clearWindow() const {
    glClearColor(0.75f, 0.75f, 0.75f, 1.0f); // set the background to light gray.
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
}

/*
void Scene::drawRenderQueue(const Camera& camera) const {
    // Render
    // Clear the colorbuffer
    clearWindow();
    camera.clearCamera();

    // Draw
    // bind/unbind VAO is now in startup/shutdown.
    //(mShaderProgramPool[0])->activate(); // Optimize. if the shader program is the same as the former one, then THIS is not necessary.
    //for (auto i=mRenderQueue.begin(); i!=mRenderQueue.end(); ++i) { // first: index, second: Sprite&
        //if ((*i).second.getVisibility()) (*i).second.draw(camera);
    //}

    // Swap the screen buffers
    glfwSwapBuffers(gRenderManager.getWindowHandle());
}
*/
