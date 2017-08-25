#include "Sprite.h"


Sprite::Sprite() {
    mColor << 1, 1, 1, 1;
    mPos << 0, 0, 0;
    mWidth = 1;
    mHeight = 1;
    this->pShaderProgram = gRenderManager.getDefaultShader();
    mIndex = gRenderManager.addSpriteToRenderQueue(this);
}

Sprite::Sprite(ShaderProgram* pShaderProgram) {
    mColor << 1, 1, 1, 1;
    mPos << 0, 0, 0;
    mWidth = 1;
    mHeight = 1;
    this->pShaderProgram = pShaderProgram;
    mIndex = gRenderManager.addSpriteToRenderQueue(this);
}

Sprite::~Sprite() {
    gRenderManager.removeSpriteFromRenderQueue(mIndex);
}

void Sprite::draw() {
    pShaderProgram->activate();
    GLint colorLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uPixelColor");
    GLint matrixLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uModelTransform");
    glUniform4f(colorLocation, mColor(0), mColor(1), mColor(2), mColor(3));
    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, getTransformMatrix().data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void Sprite::setColor(Eigen::Vector4f color) { // this maybe useless.
    mColor = color;
}

void Sprite::setColor(float r, float g, float b, float a) {
    mColor << r, g, b, a;
}

void Sprite::setPos(Eigen::Vector3f pos) {
    mPos = pos;
}

void Sprite::setPos(float x, float y, float z) {
    mPos << x, y, z;
}

void Sprite::setScale(float width, float height) {
    mWidth = width;
    mHeight = height;
}

void Sprite::setAngleByRad(float rad) {
    mRotateRad = rad;
}

Eigen::Matrix4f Sprite::getTransformMatrix() {
    // translate
    Eigen::Matrix4f trans4;
    trans4.setIdentity();
    trans4.block<3, 1>(0, 3) = mPos;

    // rotate
    Eigen::Matrix4f rot4;
    rot4.setIdentity();
    rot4.block<2, 2>(0, 0) << cos(mRotateRad), -sin(mRotateRad), sin(mRotateRad), cos(mRotateRad);

    // scale
    Eigen::Matrix4f scale4;
    scale4.setIdentity();
    scale4.block<2, 2>(0, 0) << mWidth, 0, 0, mHeight;

    return trans4 * rot4 * scale4;
}

// xxx getxxx(); void incxxx(xxx xxx);

