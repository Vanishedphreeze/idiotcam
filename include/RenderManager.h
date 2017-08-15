// Because of an unknown problem, m_Info.flag.stereo should be 0.

#pragma once

#define TITLE         "Idiotcam Example"
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 600

#include "BaseManager.h"
#include "SceneManager.h"

class RenderManager : public BaseManager {
protected:
    struct APPINFO {
        char title[128];
        int windowWidth;
        int windowHeight;
        int majorVersion = 4;
        int minorVersion = 3;
        int samples;
        union {
            struct {
                unsigned int    fullscreen  : 1;
                unsigned int    vsync       : 1;
                unsigned int    cursor      : 1;
                unsigned int    stereo      : 1;
                unsigned int    debug       : 1;
            };
            unsigned int        all;
        } flags;
    } m_Info;
    public: GLFWwindow* window;


public:
    RenderManager() {};
    ~RenderManager() {};

    void startUp() override {

        m_Info.flags.all = 22;
        /*
        m_Info.flags.fullscreen=0;
        m_Info.flags.vsync=1;
        m_Info.flags.cursor=1;
        m_Info.flags.stereo=0;
        m_Info.flags.debug=1;
        */

        if (!glfwInit())
        {
            fprintf(stderr, "Failed to initialize GLFW\n");
            return;
        }
        //printf("%d\n",m_Info.majorVersion);

        strcpy(m_Info.title, TITLE);
        m_Info.windowWidth = WINDOW_WIDTH;
        m_Info.windowHeight = WINDOW_HEIGHT;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_Info.majorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_Info.minorVersion);

#ifdef _DEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif /* _DEBUG */
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_SAMPLES, m_Info.samples);
        glfwWindowHint(GLFW_STEREO, m_Info.flags.stereo ? GL_TRUE : GL_FALSE);


        window = glfwCreateWindow(m_Info.windowWidth, m_Info.windowHeight, m_Info.title, m_Info.flags.fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
        if (!window) {
            fprintf(stderr, "Failed to open window\n");
            return;
        }


        glfwMakeContextCurrent(window);
        glfwSetWindowTitle(window, m_Info.title);

        if (!m_Info.flags.cursor)
        {
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        }

        // m_Info.flags.stereo = (glfwGetWindowParam(GLFW_STEREO) ? 1 : 0);

        glewInit();

#ifdef _DEBUG
        fprintf(stderr, "VENDOR: %s\n", (char *)glGetString(GL_VENDOR));
        fprintf(stderr, "VERSION: %s\n", (char *)glGetString(GL_VERSION));
        fprintf(stderr, "RENDERER: %s\n", (char *)glGetString(GL_RENDERER));
#endif

    }

    void shutDown() override {
        glfwDestroyWindow(window);
        glfwTerminate();
    }
};
