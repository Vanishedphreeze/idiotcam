#include <iostream>
#include <fstream>

#include "include/RenderManager.h"

// use a priority queue to initialize managers
RenderManager gRenderManager;

int main() {
    gRenderManager.startUp();

    // Gameloop
    while (!glfwWindowShouldClose(gRenderManager.gameWindowHandle)) {
        // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
        glfwPollEvents();
        gRenderManager.draw();
    }

    gRenderManager.shutDown();
    return 0;
}
