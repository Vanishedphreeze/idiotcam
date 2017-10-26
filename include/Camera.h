#ifndef _CAMERA
#define _CAMERA

#include "Predeclare.h"

#include "RenderManager.h"

#pragma once

/*
    The WC is based on right-handed system.
    Z-axis's Positive direction is normal to the screen towards user.
    The observer is on position mWCEyePos.
    Anything whose Z-position is larger than observer's will not be shown.
*/

class Camera { // the camera can not rotate now
private:
    glm::vec3 mWCEyePos;
    float mZFar = -1000.0;
    float mWCWidth;
    int mViewportXPos = 0, mViewportYPos = 0; // In pixel. same as mWiewportWidth / Height
    int mViewportWidth = WINDOW_WIDTH, mViewportHeight = WINDOW_HEIGHT;
    glm::vec4 mBgColor;
    bool mIsActive = true;
    void _setupViewport();


public:
    Camera(glm::vec3 eyepos, float wcwidth);
    Camera(float xEye, float yEye, float zEye, float wcwidth);
    ~Camera();

    void clearCamera();

    void setBgColor(glm::vec4 color);
    void setBgColor(float r, float g, float b, float a);
    glm::vec4 getBgColor() const;

    void setWCEyePos(glm::vec3 pos);
    void setWCEyePos(float x, float y, float z);
    void incWCEyePos(glm::vec3 dPos);
    void incWCEyePos(float dx, float dy, float dz);
    void setZFarPlane(float zfar);
    float getZFarPlane() const;

    glm::vec3 getWCEyePos() const;

    void setWCWidth(float width);
    void incWCWidth(float dWidth);
    float getWCWidth() const;
    float getWCHeight() const;

    void setViewport(int x, int y, int width, int height);
    glm::ivec4 getViewportInfo() const;

    void setActivity(bool flag);
    bool getActivity() const;

    glm::mat4 getViewMatrix() const;
    glm::mat4 getProjMatrix() const;
};

#endif // _CAMERA
