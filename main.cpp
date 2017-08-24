#include "include/RenderManager.h"
#include "include/Sprite.h"

extern RenderManager gRenderManager;

int main() {
    gRenderManager.startUp();

    Sprite* testSprite = new Sprite(gRenderManager.getDefaultShader());
    Eigen::Vector4f color;
    color << 1, 0, 0, 0;

    // Gameloop
    while (!glfwWindowShouldClose(gRenderManager.getWindowHandle())) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        testSprite->setColor(color);
        gRenderManager.draw();
    }

    gRenderManager.shutDown();
    return 0;
}
