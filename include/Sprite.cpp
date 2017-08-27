#include "Sprite.h"


Sprite::Sprite() {
    this->pShaderProgram = gRenderManager.getDefaultShader();
    _spriteConstructor();
}

Sprite::Sprite(ShaderProgram* pShaderProgram) {
    this->pShaderProgram = pShaderProgram;
    _spriteConstructor();
}

void Sprite::_spriteConstructor() {
    mColor << 1, 1, 1, 1;
    mPos << 0, 0, 0;
    mWidth = 1;
    mHeight = 1;
    mIndex = gRenderManager.addSpriteToRenderQueue(this);
}

Sprite::~Sprite() {
    gRenderManager.removeSpriteFromRenderQueue(mIndex);
}

void Sprite::draw() {
    pShaderProgram->activate();
    Camera* curCam = gRenderManager.getDefaultCamera();

    GLint colorLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uPixelColor");
    GLint matrixLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uModelTransform");
    GLint VLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uViewTransform");
    GLint PLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uProjectTransform");
    glUniform4f(colorLocation, mColor(0), mColor(1), mColor(2), mColor(3));
    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, getTransformMatrix().data());
    glUniformMatrix4fv(VLocation, 1, GL_FALSE, curCam->getViewMatrix().data());
    glUniformMatrix4fv(PLocation, 1, GL_FALSE, curCam->getProjMatrix().data());
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    //Eigen::Vector4f pos4;
    //pos4 << 0.0, 0.0, 0.0, 1.0;
    //std::cout << View << std::endl;
    //std::cout << getTransformMatrix() << std::endl;
    //std::cout << Proj << std::endl;
    //std::cout << Proj * View * getTransformMatrix() * pos4 << std::endl;
}

void Sprite::setColor(Eigen::Vector4f color) { // this maybe useless.
    mColor = color;
}

void Sprite::setColor(float r, float g, float b, float a) {
    mColor << r, g, b, a;
}

Eigen::Vector4f Sprite::getColor() const {
    return mColor;
}

void Sprite::setPos(Eigen::Vector3f pos) {
    mPos = pos;
}

void Sprite::setPos(float x, float y, float z) {
    mPos << x, y, z;
}

void Sprite::incPos(Eigen::Vector3f dPos) {
    mPos += dPos;
}

void Sprite::incPos(float dx, float dy, float dz) {
    mPos(0) += dx;
    mPos(1) += dy;
    mPos(2) += dz;
}

Eigen::Vector3f Sprite::getPos() const {
    return mPos;
}

void Sprite::setScale(float width, float height) {
    mWidth = width;
    mHeight = height;
}

void Sprite::incScale(float dWidth, float dHeight) {
    mWidth += dWidth;
    mHeight += dHeight;
}

float Sprite::getWidth() const {
    return mWidth;
}

float Sprite::getHeight() const {
    return mHeight;
}

void Sprite::setAngleByRad(float rad) {
    mRotateRad = rad;
}

void Sprite::incAngleByRad(float dRad) {
    mRotateRad += dRad;
}

float Sprite::getAngleByRad() const {
    return mRotateRad;
}

void Sprite::setVisibility(bool flag) {
    mVisible = flag;
}

bool Sprite::getVisibility() const {
    return mVisible;
}

Eigen::Matrix4f Sprite::getTransformMatrix() {
    // translate
    Eigen::Matrix4f trans;
    trans.setIdentity();
    trans.block<3, 1>(0, 3) = mPos;

    // rotate
    Eigen::Matrix4f rot;
    rot.setIdentity();
    rot.block<2, 2>(0, 0) << cos(mRotateRad), -sin(mRotateRad), sin(mRotateRad), cos(mRotateRad);

    // scale
    Eigen::Matrix4f scale;
    scale.setIdentity();
    scale.block<2, 2>(0, 0) << mWidth, 0.0, 0.0, mHeight;

    return trans * rot * scale;
}


