#include "include/Predeclare.h"
#include "include/RenderManager.h"
#include "include/Sprite.h"
#include "include/InputManager.h"

#include "testScene.h"

extern RenderManager gRenderManager;

//glEnable(GL_DEPTH_TEST);  // this should be discussed later.

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


/*
int main() {
    gRenderManager.startUp();

    Sprite* redsq = new Sprite();
    Sprite* yellowsq = new Sprite();

    // initialization
    redsq->setColor(1, 0, 0, 0);
    yellowsq->setColor(1, 1, 0, 0);

    redsq->setPos(-15, -5, 0);
    redsq->setScale(25, 40);
    redsq->setAngleByRad(PI / 6);

    yellowsq->setPos(20, 10, 0);
    yellowsq->setScale(30, 30);
    yellowsq->setAngleByRad(PI / 4);

    Camera* cam = gRenderManager.getDefaultCamera();
    cam->setBgColor(0, 1, 0, 1);
    cam->setViewport(112, 84, 800, 600);

    double prevTime, curTime, realtimeFPS;
    const double fixedFPS = 60.0;
    const double fixedFreshPeriod = 1 / fixedFPS;
    bool startUp = false;

    std::cout << fixedFreshPeriod << std::endl;

    // Gameloop
    while (!glfwWindowShouldClose(gRenderManager.getWindowHandle())) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        curTime = glfwGetTime();
        if (!startUp || curTime > prevTime + fixedFreshPeriod) {
            if (startUp) {
                realtimeFPS = 1 / (curTime - prevTime);
                std::cout << std::setprecision(5) << realtimeFPS << std::endl;
            }
            startUp = true;

            // render
            gRenderManager.draw();
            /////////

            // update
            yellowsq->incAngleByRad(0.01);
            redsq->incAngleByRad(-0.05);
            redsq->incPos(0.2, 0.1, 0.0);
            /////////

            prevTime = curTime;
        }
    }

    gRenderManager.shutDown();
    return 0;
}
*/
