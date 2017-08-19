#pragma once

#ifndef GLEW_BUILD
    #define GLEW_BUILD
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif // GLEW_BUILD

#ifndef STDLIBRARIES
    #define STDLIBRARIES
    #include<cstdio>
    #include<cstring>
    #include<vector>
    #include<string>
    #include<map>
#endif // STDLIBRARIES

class BaseManager {
public:
    BaseManager() {}
    virtual ~BaseManager() {}
    virtual void startUp() = 0;
    virtual void shutDown() = 0;
};
