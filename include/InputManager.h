#ifndef _INPUTMANAGER
#define _INPUTMANAGER

#pragma once

#include "BaseManager.h"
#include "RenderManager.h"

extern RenderManager gRenderManager;

class InputManager : public BaseManager {
public:
    enum Keyboard_code {
        KEYBOARD_SPACE      = 32,

        KEYBOARD_APOSTROPHE = 39,

        KEYBOARD_COMMA      = 44,
        KEYBOARD_MINUS,
        KEYBOARD_PERIOD,
        KEYBOARD_SLASH,
        KEYBOARD_0,
        KEYBOARD_1,
        KEYBOARD_2,
        KEYBOARD_3,
        KEYBOARD_4,
        KEYBOARD_5,
        KEYBOARD_6,
        KEYBOARD_7,
        KEYBOARD_8,
        KEYBOARD_9,

		KEYBOARD_SEMICOLON  = 59,

		KEYBOARD_EQUAL      = 61,

		KEYBOARD_A          = 65,
		KEYBOARD_B,
        KEYBOARD_C,
        KEYBOARD_D,
        KEYBOARD_E,
        KEYBOARD_F,
        KEYBOARD_G,
        KEYBOARD_H,
        KEYBOARD_I,
        KEYBOARD_J,
        KEYBOARD_K,
        KEYBOARD_L,
        KEYBOARD_M,
        KEYBOARD_N,
        KEYBOARD_O,
        KEYBOARD_P,
        KEYBOARD_Q,
        KEYBOARD_R,
        KEYBOARD_S,
        KEYBOARD_T,
        KEYBOARD_U,
        KEYBOARD_V,
        KEYBOARD_W,
        KEYBOARD_X,
        KEYBOARD_Y,
        KEYBOARD_Z,
    };

private:
    static bool mKeyPrevState[GLFW_KEY_LAST + 1];
    static bool mIsKeyPressed[GLFW_KEY_LAST + 1];
    static bool mIsKeyClicked[GLFW_KEY_LAST + 1];
    static bool mIsKeyReleased[GLFW_KEY_LAST + 1];
    static void _keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

public:
    InputManager() {}
    ~InputManager() {}
    void startUp() override;
    void shutDown() override;
    void updateKeyState();
    bool isKeyClicked(int key) const; // beware of range
    bool isKeyPressed(int key) const;
    bool isKeyReleased(int key) const;
};

#endif // _INPUTMANAGER
