#ifndef _SHADERPROGRAM
#define _SHADERPROGRAM

#pragma once

#ifndef GLEW_BUILD
    #define GLEW_BUILD
    #include <GL/glew.h>
    #include <GLFW/glfw3.h>
#endif // GLEW_BUILD

#ifndef STDLIBRARIES
    #define STDLIBRARIES
    #include <iostream>
    #include <fstream>
    #include <cstdio>
    #include <cstring>
    #include <vector>
    #include <string>
    #include <map>
#endif // STDLIBRARIES

class ShaderProgram {
private:
    GLuint mShaderProgramLocation;

    void loadAndCompileShader(GLuint &targetShader, const char* shaderFile, const GLuint shaderType);

public:
    ShaderProgram(const char* vertexShaderFile, const char* fragmentShaderFile);
    void activate();
    GLuint getShaderProgramLocation();
};

#endif // _SHADERPROGRAM


