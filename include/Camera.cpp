#include "Camera.h"

Camera::Camera(glm::vec3 eyepos, float wcwidth) {
    mWCEyePos = eyepos;
    mWCWidth = wcwidth;
    mBgColor = glm::vec4(0.8, 0.8, 0.8, 1.0);
    _setupViewport();
}


Camera::Camera(float xEye, float yEye, float zEye, float wcwidth) {
    mWCEyePos = glm::vec3(xEye, yEye, zEye);
    mWCWidth = wcwidth;
    mBgColor = glm::vec4(0.8, 0.8, 0.8, 1.0);
    _setupViewport();
}

void Camera::_setupViewport() {
    glViewport(mViewportXPos, mViewportYPos, mViewportWidth, mViewportHeight);
    glScissor(mViewportXPos, mViewportYPos, mViewportWidth, mViewportHeight);
}

void Camera::clearCamera() const {
    glClearColor(mBgColor.r, mBgColor.g, mBgColor.b, mBgColor.a);
    glEnable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    glDisable(GL_SCISSOR_TEST);
}

Camera::~Camera() {}

void Camera::setBgColor(glm::vec4 color) {
    mBgColor = color;
}

void Camera::setBgColor(float r, float g, float b, float a) {
    mBgColor = glm::vec4(r, g, b, a);
}

glm::vec4 Camera::getBgColor() const {
    return mBgColor;
}

void Camera::setWCEyePos(glm::vec3 pos) {
    mWCEyePos = pos;
}

void Camera::setWCEyePos(float x, float y, float z) {
    mWCEyePos = glm::vec3(x, y, z);
}

void Camera::incWCEyePos(glm::vec3 dPos) {
    mWCEyePos += dPos;
}

void Camera::incWCEyePos(float dx, float dy, float dz) {
    mWCEyePos.x += dx;
    mWCEyePos.y += dy;
    mWCEyePos.x += dz;
}

glm::vec3 Camera::getWCEyePos() const {
    return mWCEyePos;
}

/*
void Camera::setZFarPlane(float zfar) {
    mZFar = zfar;
}
*/

/*
float Camera::getZFarPlane() const {
    return mZFar;
}
*/

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
    _setupViewport();
}

glm::ivec4 Camera::getViewportInfo() const {
    glm::ivec4 temp;
    temp = glm::ivec4(mViewportXPos, mViewportYPos, mViewportWidth, mViewportHeight);
    return temp;
}

void Camera::setActivity(bool flag) {
    mIsActive = flag;
}

bool Camera::getActivity() const {
    return mIsActive;
}

glm::mat4 Camera::getViewMatrix() const {
    glm::mat4 view;
    //view = glm::mat4(1.0f);
    //view.block<3, 1>(0, 3) << -mWCEyePos(0), -mWCEyePos(1), 0;
    //view = glm::translate(view, glm::vec3(-mWCEyePos.xy, 0));

    view = glm::lookAt(mWCEyePos, glm::vec3(mWCEyePos.x, mWCEyePos.y, mWCEyePos.z - 1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    return view;
}

glm::mat4 Camera::getProjMatrix() const {
    glm::mat4 proj;
    /*
    float zNear = mWCEyePos(2);
    proj << 2.0 / mWCWidth,                 0.0,                    0.0,                                0.0,
                       0.0, 2.0 / getWCHeight(),                    0.0,                                0.0,
                       0.0,                 0.0, -2.0 / (mZFar - zNear), -(mZFar + zNear) / (mZFar - zNear),
                       0.0,                 0.0,                    0.0,                                1.0;
                       */

    proj = glm::ortho(-mWCWidth / 2.0f, mWCWidth / 2.0f, -getWCHeight() / 2.0f, getWCHeight() / 2.0f);
    //proj = glm::ortho(-mWCWidth / 2.0f, mWCWidth / 2.0f, -getWCHeight() / 2.0f, getWCHeight() / 2.0f, mWCEyePos.z, mZFar);
    // zNear & zFar?

    return proj;
}
