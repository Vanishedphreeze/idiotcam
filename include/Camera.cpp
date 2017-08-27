#include "Camera.h"

Camera::Camera(Eigen::Vector3f eyepos, float wcwidth) {
    mWCEyePos = eyepos;
    mWCWidth = wcwidth;
    _initialize();
}

Camera::Camera(float xEye, float yEye, float zEye, float wcwidth) {
    mWCEyePos << xEye, yEye, zEye;
    mWCWidth = wcwidth;
    _initialize();
}

void Camera::_initialize() {
    mBgColor << 0.8, 0.8, 0.8, 1.0;
//    glViewport(mViewportXPos, mViewportYPos, mViewportWidth, mViewportHeight);
//    glScissor(mViewportXPos, mViewportYPos, mViewportWidth, mViewportHeight);
//    glClearColor(mBgColor(0), mBgColor(1), mBgColor(2), mBgColor(3));
//    glEnable(GL_SCISSOR_TEST);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glDisable(GL_SCISSOR_TEST);
}

Camera::~Camera() {}

void Camera::setBgColor(Eigen::Vector4f color) {
    mBgColor = color;
}

void Camera::setBgColor(float r, float g, float b, float a) {
    mBgColor << r, g, b, a;
}

Eigen::Vector4f Camera::getBgColor() const {
    return mBgColor;
}

void Camera::setWCEyePos(Eigen::Vector3f pos) {
    mWCEyePos = pos;
}

void Camera::setWCEyePos(float x, float y, float z) {
    mWCEyePos << x, y, z;
}

void Camera::incWCEyePos(Eigen::Vector3f dPos) {
    mWCEyePos += dPos;
}

void Camera::incWCEyePos(float dx, float dy, float dz) {
    mWCEyePos(0) += dx;
    mWCEyePos(1) += dy;
    mWCEyePos(2) += dz;
}

Eigen::Vector3f Camera::getWCEyePos() const {
    return mWCEyePos;
}

void Camera::setZFarPlane(float zfar) {
    mZFar = zfar;
}

float Camera::getZFarPlane() const {
    return mZFar;
}

void Camera::setWCWidth(float width) {
    mWCWidth = width;
}

void Camera::incWCWidth(float dWidth)  {
    mWCWidth += dWidth;
}

float Camera::getWCWidth() const {
    return mWCWidth;
}

float Camera::getWCHeight() const {
    return mWCWidth / mViewportWidth * mViewportHeight;
}

void Camera::setViewport(int x, int y, int width, int height) {
    mViewportXPos = x, mViewportYPos = y;
    mViewportWidth = width, mViewportHeight = height;
}

Eigen::Vector4i Camera::getViewportInfo() const {
    Eigen::Vector4i temp;
    temp << mViewportXPos, mViewportYPos, mViewportWidth, mViewportHeight;
    return temp;
}

void Camera::setActivity(bool flag) {
    mIsActive = flag;
}

bool Camera::getActivity() const {
    return mIsActive;
}

//    float znear = 1.0, zfar = -1.0;
//    float W = 100, pixelW = 1024, pixelH = 768, posx = 10, posy = 5;
//    float H = (W / pixelW) * pixelH;
//
//    Eigen::Matrix4f transV;
//    transV.setIdentity();
//    transV.block<3, 1>(0, 3) << -posx, -posy, 0;
//
//
//    Eigen::Matrix4f View = transV;
//    Eigen::Matrix4f Proj;
//    Proj << 2.0 / W,     0.0,                   0.0,                              0.0,
//                0.0, 2.0 / H,                   0.0,                              0.0,
//                0.0,     0.0, -2.0 / (zfar - znear), -(zfar + znear) / (zfar - znear),
//                0.0,     0.0,                   0.0,                              1.0;

Eigen::Matrix4f Camera::getViewMatrix() const {
    Eigen::Matrix4f view;
    view.setIdentity();
    view.block<3, 1>(0, 3) << -mWCEyePos(0), -mWCEyePos(1), 0;
    return view;
}

Eigen::Matrix4f Camera::getProjMatrix() const {
    Eigen::Matrix4f proj;
    float zNear = mWCEyePos(2);
    proj << 2.0 / mWCWidth,                 0.0,                    0.0,                                0.0,
                       0.0, 2.0 / getWCHeight(),                    0.0,                                0.0,
                       0.0,                 0.0, -2.0 / (mZFar - zNear), -(mZFar + zNear) / (mZFar - zNear),
                       0.0,                 0.0,                    0.0,                                1.0;
    return proj;
}
