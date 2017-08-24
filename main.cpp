#include "include/RenderManager.h"
#include "include/Sprite.h"

extern RenderManager gRenderManager;

int main() {
    gRenderManager.startUp();

    Sprite* testSprite = new Sprite(gRenderManager.getDefaultShader());
    Eigen::Vector4f color;
    color << 1, 0, 0, 0;

    double timetick;

    // initialization
    timetick = glfwGetTime();
    testSprite->setColor(color);

    // Gameloop
    while (!glfwWindowShouldClose(gRenderManager.getWindowHandle())) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();

        if (glfwGetTime() - timetick > 3.0) {
            delete testSprite;
        }
        if (glfwGetTime() - timetick > 5.0) {
            testSprite = new Sprite(gRenderManager.getDefaultShader());
            testSprite->setColor(1, 1, 0, 0);
        }
        gRenderManager.draw();
    }

    gRenderManager.shutDown();
    return 0;
}
