#include "include/Predeclare.h"
#include "include/RenderManager.h"
#include "include/Sprite.h"
#include "include/InputManager.h"
#include "include/SceneManager.h"

#include "testScene.h"

extern RenderManager gRenderManager;
extern InputManager gInputManager;
extern SceneManager gSceneManager;

//glEnable(GL_DEPTH_TEST);  // this should be discussed later.

int main () {
    gRenderManager.startUp();
    gInputManager.startUp();
    gSceneManager.startUp();

    gSceneManager.runScene();

    gSceneManager.shutDown();
    gInputManager.shutDown();
    gRenderManager.shutDown();
}


/*
int main () {
    gRenderManager.startUp();
    gInputManager.startUp();
    TestScene scene1;
    scene1.loadScene();
    scene1.initialize();
    scene1._loopStart();
    scene1.unloadScene();
    gInputManager.shutDown();
    gRenderManager.shutDown();
    return 0;
}
*/

