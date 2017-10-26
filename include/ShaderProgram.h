#ifndef _SHADERPROGRAM
#define _SHADERPROGRAM

#pragma once

#include "Predeclare.h"

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


