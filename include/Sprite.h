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
    float mRotateRad = 0;
    Eigen::Vector3f mPos;
    float mWidth = 1, mHeight = 1;
    void _spriteConstructor();

public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW // this is pretty annoying.
    //Eigen::Matrix4f mTransformMatrix; // this will be removed later.
    Sprite();
    Sprite(ShaderProgram* pShaderProgram);
    ~Sprite();

    void draw();

    void setColor(Eigen::Vector4f color);
    void setColor(float r, float g, float b, float a);
    Eigen::Vector4f getColor() const;

    void setPos(Eigen::Vector3f pos);
    void setPos(float x, float y, float z);
    void incPos(Eigen::Vector3f dPos);
    void incPos(float dx, float dy, float dz);
    Eigen::Vector3f getPos() const;

    void setScale(float width, float height);
    void incScale(float dWidth, float dHeight);

    float getWidth() const;
    float getHeight() const;

    void setAngleByRad(float rad);
    void incAngleByRad(float dRad);
    float getAngleByRad() const;

    void setVisibility(bool flag);
    bool getVisibility() const;

    Eigen::Matrix4f getTransformMatrix();
};

#endif // _SPRITE

