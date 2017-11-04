#ifndef _INPUTMANAGER
#define _INPUTMANAGER

#pragma once

#include "BaseManager.h"
#include "RenderManager.h"

extern RenderManager gRenderManager;

class InputManager : public BaseManager {
public:
    enum Keyboard_code {
        KEYBOARD_SPACE = 32,

        KEYBOARD_APOSTROPHE = 39, /* ' */

        KEYBOARD_COMMA = 44, /* , */
        KEYBOARD_MINUS, /* - */
        KEYBOARD_PERIOD, /* . */
        KEYBOARD_SLASH, /* / */
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

		KEYBOARD_SEMICOLON  = 59, /* ; */

		KEYBOARD_EQUAL = 61, /* = */

		KEYBOARD_A = 65,
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
        KEYBOARD_LEFT_BRACKET, /* [ */
        KEYBOARD_BACKSLASH, /* \ */
        KEYBOARD_RIGHT_BRACKET, /* ] */

        KEYBOARD_GRAVE_ACCENT = 96, /* ` */

        KEYBOARD_WORLD_1 = 161, /* non-US #1 */
        KEYBOARD_WORLD_2, /* non-US #2 */

        KEYBOARD_ESCAPE = 256,
        KEYBOARD_ENTER,
        KEYBOARD_TAB,
        KEYBOARD_BACKSPACE,
        KEYBOARD_INSERT,
        KEYBOARD_DELETE,
        KEYBOARD_RIGHT,
        KEYBOARD_LEFT,
        KEYBOARD_DOWN,
        KEYBOARD_UP,
        KEYBOARD_PAGE_UP,
        KEYBOARD_PAGE_DOWN,
        KEYBOARD_HOME,
        KEYBOARD_END,

        KEYBOARD_CAPS_LOCK = 280,
        KEYBOARD_SCROLL_LOCK,
        KEYBOARD_NUM_LOCK,
        KEYBOARD_PRINT_SCREEN,
        KEYBOARD_PAUSE,

        KEYBOARD_F1 = 290,
        KEYBOARD_F2,
        KEYBOARD_F3,
        KEYBOARD_F4,
        KEYBOARD_F5,
        KEYBOARD_F6,
        KEYBOARD_F7,
        KEYBOARD_F8,
        KEYBOARD_F9,
        KEYBOARD_F10,
        KEYBOARD_F11,
        KEYBOARD_F12,
        KEYBOARD_F13,
        KEYBOARD_F14,
        KEYBOARD_F15,
        KEYBOARD_F16,
        KEYBOARD_F17,
        KEYBOARD_F18,
        KEYBOARD_F19,
        KEYBOARD_F20,
        KEYBOARD_F21,
        KEYBOARD_F22,
        KEYBOARD_F23,
        KEYBOARD_F24,
        KEYBOARD_F25,

        KEYBOARD_KP_0 = 320,
        KEYBOARD_KP_1,
        KEYBOARD_KP_2,
        KEYBOARD_KP_3,
        KEYBOARD_KP_4,
        KEYBOARD_KP_5,
        KEYBOARD_KP_6,
        KEYBOARD_KP_7,
        KEYBOARD_KP_8,
        KEYBOARD_KP_9,
        KEYBOARD_KP_DECIMAL,
        KEYBOARD_KP_DIVIDE,
        KEYBOARD_KP_MULTIPLY,
        KEYBOARD_KP_SUBTRACT,
        KEYBOARD_KP_ADD,
        KEYBOARD_KP_ENTER,
        KEYBOARD_KP_EQUAL,

        KEYBOARD_LEFT_SHIFT = 340,
        KEYBOARD_LEFT_CONTROL,
        KEYBOARD_LEFT_ALT,
        KEYBOARD_LEFT_SUPER,
        KEYBOARD_RIGHT_SHIFT,
        KEYBOARD_RIGHT_CONTROL,
        KEYBOARD_RIGHT_ALT,
        KEYBOARD_RIGHT_SUPER,
        KEYBOARD_MENU,   // 348

        KEYBOARD_LAST = 348
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
    bool isKeyClicked(const Keyboard_code key) const; // beware of range
    bool isKeyPressed(const Keyboard_code key) const;
    bool isKeyReleased(const Keyboard_code key) const;
};

#endif // _INPUTMANAGER
