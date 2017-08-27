#ifndef _CAMERA
#define _CAMERA

#ifndef EIGEN
    #define EIGEN
    #include <Eigen/Eigen>
#endif // EIGEN

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
    Eigen::Vector3f mWCEyePos;
    float mZFar = -1.0;
    float mWCWidth;
    int mViewportXPos = 0, mViewportYPos = 0; // In pixel. same as mWiewportWidth / Height
    int mViewportWidth = WINDOW_WIDTH, mViewportHeight = WINDOW_HEIGHT;
    Eigen::Vector4f mBgColor;
    bool mIsActive = true;
    void _setupViewport();


public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    Camera(Eigen::Vector3f eyepos, float wcwidth);
    Camera(float xEye, float yEye, float zEye, float wcwidth);
    ~Camera();

    void clearCamera();

    void setBgColor(Eigen::Vector4f color);
    void setBgColor(float r, float g, float b, float a);
    Eigen::Vector4f getBgColor() const;

    void setWCEyePos(Eigen::Vector3f pos);
    void setWCEyePos(float x, float y, float z);
    void incWCEyePos(Eigen::Vector3f dPos);
    void incWCEyePos(float dx, float dy, float dz);
    void setZFarPlane(float zfar);
    float getZFarPlane() const;

    Eigen::Vector3f getWCEyePos() const;

    void setWCWidth(float width);
    void incWCWidth(float dWidth);
    float getWCWidth() const;
    float getWCHeight() const;

    void setViewport(int x, int y, int width, int height);
    Eigen::Vector4i getViewportInfo() const;

    void setActivity(bool flag);
    bool getActivity() const;

    Eigen::Matrix4f getViewMatrix() const;
    Eigen::Matrix4f getProjMatrix() const;
};

#endif // _CAMERA
