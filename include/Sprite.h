#ifndef _SPRITE
#define _SPRITE

#pragma once

#include "ShaderProgram.h"
#include "RenderManager.h"

#ifndef EIGEN
    #define EIGEN
    #include <Eigen/Eigen>
#endif // EIGEN

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

class RenderManager;

extern RenderManager gRenderManager;

class Sprite {
private:
    ShaderProgram *pShaderProgram;
    Eigen::Vector4f mColor;
    int mIndex;
    bool mVisible = true;

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW // this is pretty annoying.
    Sprite();
    Sprite(ShaderProgram* pShaderProgram);
    ~Sprite();
    void draw();
    void setColor(Eigen::Vector4f color);
    void setColor(float r, float g, float b, float a);
};

#endif // _SPRITE

