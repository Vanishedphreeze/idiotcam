#include "include/RenderManager.h"
#include "include/Sprite.h"

#define PI 3.1415926535897932384626

extern RenderManager gRenderManager;

//glEnable(GL_DEPTH_TEST);  // this should be discussed later.

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

    // Gameloop
    while (!glfwWindowShouldClose(gRenderManager.getWindowHandle())) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        gRenderManager.draw();
    }

    gRenderManager.shutDown();
    return 0;
}
