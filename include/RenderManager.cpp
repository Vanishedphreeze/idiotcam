#include "RenderManager.h"


void RenderManager::setupVertexBuffer() {
    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] = {
        -0.5f,  0.5f, 0.0f,
         0.5f,  0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };
    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(mVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind
    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)
}


void RenderManager::startUp() {

    mInfo.flags.all = 22;

    // that is equal to
    /*
    mInfo.flags.fullscreen=0;
    mInfo.flags.vsync=1;
    mInfo.flags.cursor=1;
    mInfo.flags.stereo=0;
    mInfo.flags.debug=1;
    */

    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    strcpy(mInfo.title, TITLE);
    mInfo.windowWidth = WINDOW_WIDTH;
    mInfo.windowHeight = WINDOW_HEIGHT;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, mInfo.majorVersion);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, mInfo.minorVersion);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_SAMPLES, mInfo.samples);
    glfwWindowHint(GLFW_STEREO, mInfo.flags.stereo ? GL_TRUE : GL_FALSE);

    mGameWindowHandle = glfwCreateWindow(mInfo.windowWidth, mInfo.windowHeight, mInfo.title, mInfo.flags.fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    if (mGameWindowHandle == NULL) {
        fprintf(stderr, "Failed to open window\n");
        return;
    }

    glfwMakeContextCurrent(mGameWindowHandle);
    glfwSetWindowTitle(mGameWindowHandle, mInfo.title);

    if (!mInfo.flags.cursor) {
        glfwSetInputMode(mGameWindowHandle, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    }

    glewInit();
    setupVertexBuffer();

    ShaderProgram* simpleShader = new ShaderProgram("shaders/simpleVS.vert", "shaders/simpleFS.frag");
    mShaderProgramPool.push_back(simpleShader);

    mDefaultCam = new Camera(0, 0, 1, 100);
}


void RenderManager::shutDown() {
    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &mVAO);
    glDeleteBuffers(1, &mVBO);

    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwDestroyWindow(mGameWindowHandle);
    glfwTerminate();
}

GLFWwindow* RenderManager::getWindowHandle() const {
    return mGameWindowHandle;
}

ShaderProgram* RenderManager::getDefaultShader() const {
    return mShaderProgramPool[0];
}

Camera* RenderManager::getDefaultCamera() const {
    return mDefaultCam;
}

int RenderManager::addSpriteToRenderQueue(Sprite* sprite) {
    mRenderQueue.insert(std::pair<int, Sprite*> (mSpriteIndexCounter, sprite));
    return mSpriteIndexCounter++;
}

void RenderManager::removeSpriteFromRenderQueue(int index) {
    mRenderQueue.erase(index);
}

void RenderManager::clearWindow() {
    glClearColor(0.7f, 0.7f, 0.7f, 1.0f); // set the background to light gray.
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderManager::draw() {
    // use glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) to draw wire frame.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) to set as default.

    // Render
    // Clear the colorbuffer
    clearWindow();
    (getDefaultCamera())->clearCamera();

    // what will happen if i don't unbind the VAO after draw?

    // Draw
    glBindVertexArray(mVAO);
    //(mShaderProgramPool[0])->activate(); // Optimize. if the shader program is the same as the former one, then THIS is not necessary.
    for (auto i=mRenderQueue.begin(); i!=mRenderQueue.end(); ++i) {
        if ((*i).second->getVisibility()) (*i).second->draw();
    }
    glBindVertexArray(0);

    // Swap the screen buffers
    glfwSwapBuffers(mGameWindowHandle);
}

RenderManager gRenderManager;
