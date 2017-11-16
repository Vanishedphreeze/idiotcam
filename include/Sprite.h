#ifndef _SPRITE
#define _SPRITE

#pragma once

#include "Predeclare.h"
#include "ShaderProgram.h"
#include "RenderManager.h"
#include "Camera.h"

class RenderManager;
class Camera;

extern RenderManager gRenderManager;

class Sprite {
private:
    ShaderProgram *pShaderProgram;
    glm::vec4 mColor;
    bool mVisible = true;
    float mRotateRad = 0;
    glm::vec3 mPos;
    float mWidth = 1, mHeight = 1;

    void _spriteConstructor();
    // int priority = 1;  Hint : use both map and multi-map.

public:
    // Using one sprite to Initiate another should be allowed.
    Sprite();
    Sprite(ShaderProgram* pShaderProgram);
    Sprite(const Sprite& sprite);
    ~Sprite();
    void draw(const Camera& camera) const;

    void setColor(glm::vec4 color);
    void setColor(float r, float g, float b, float a);
    glm::vec4 getColor() const;

    void setPos(glm::vec3 pos);
    void setPos(float x, float y, float z);
    void incPos(glm::vec3 dPos);
    void incPos(float dx, float dy, float dz);
    glm::vec3 getPos() const;

    void setScale(float width, float height);
    void incScale(float dWidth, float dHeight);

    float getWidth() const;
    float getHeight() const;

    void setAngleByRad(float rad);
    void incAngleByRad(float dRad);
    float getAngleByRad() const;

    void setVisibility(bool flag);
    bool getVisibility() const;

    glm::mat4 getTransformMatrix() const;
};

#endif // _SPRITE

