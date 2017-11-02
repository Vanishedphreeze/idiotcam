#include "InputManager.h"


bool InputManager::mKeyPrevState[GLFW_KEY_LAST + 1] = {false};
bool InputManager::mIsKeyPressed[GLFW_KEY_LAST + 1] = {false};
bool InputManager::mIsKeyClicked[GLFW_KEY_LAST + 1] = {false};
bool InputManager::mIsKeyReleased[GLFW_KEY_LAST + 1] = {false};


void InputManager::startUp() {
    for (int i = 0; i <= GLFW_KEY_LAST; i++) {
        mIsKeyPressed[i] = false;
        mKeyPrevState[i] = false;
    }
    glfwSetKeyCallback(gRenderManager.getWindowHandle(), _keyCallback);
}

void InputManager::_keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key >= 0 && key <= GLFW_KEY_LAST) {
        if (action == GLFW_PRESS) mIsKeyPressed[key] = true;
        else if (action == GLFW_RELEASE) mIsKeyPressed[key] = false;
    }
}

void InputManager::shutDown() {
    glfwSetKeyCallback(gRenderManager.getWindowHandle(), NULL);
}

void InputManager::updateKeyState() {
    for (int i = 0; i <= GLFW_KEY_LAST; i++) {
        mIsKeyClicked[i] = (!mKeyPrevState[i]) && mIsKeyPressed[i];
        mIsKeyReleased[i] = (!mIsKeyPressed[i]) && mKeyPrevState[i];
        mKeyPrevState[i] = mIsKeyPressed[i];
    }
}

bool InputManager::isKeyClicked(const int key) const {
    if (key >= 0 && key <= GLFW_KEY_LAST) return mIsKeyClicked[key]; else return false;
}

bool InputManager::isKeyPressed(const int key) const {
    if (key >= 0 && key <= GLFW_KEY_LAST) return mIsKeyPressed[key]; else return false;
}

bool InputManager::isKeyReleased(const int key) const {
    if (key >= 0 && key <= GLFW_KEY_LAST) return mIsKeyReleased[key]; else return false;
}

InputManager gInputManager;
