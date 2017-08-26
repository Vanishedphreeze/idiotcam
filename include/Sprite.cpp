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

    ///////////////////////////////////////////////////
    float znear = 1.0, zfar = -1.0;
    float W = 100, pixelW = 1024, pixelH = 768, posx = 10, posy = 5;
    float H = (W / pixelW) * pixelH;

    Eigen::Matrix4f transV;
    transV.setIdentity();
    transV.block<3, 1>(0, 3) << -posx, -posy, 0;


    Eigen::Matrix4f View = transV;
    Eigen::Matrix4f Proj;
    Proj << 2.0 / W,     0.0,                   0.0,                              0.0,
                0.0, 2.0 / H,                   0.0,                              0.0,
                0.0,     0.0, -2.0 / (zfar - znear), -(zfar + znear) / (zfar - znear),
                0.0,     0.0,                   0.0,                              1.0;
    ///////////////////////////////////////////////////

    GLint colorLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uPixelColor");
    GLint matrixLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uModelTransform");
    GLint VLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uViewTransform");
    GLint PLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uProjectTransform");
    glUniform4f(colorLocation, mColor(0), mColor(1), mColor(2), mColor(3));
    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, getTransformMatrix().data());
    glUniformMatrix4fv(VLocation, 1, GL_FALSE, View.data());
    glUniformMatrix4fv(PLocation, 1, GL_FALSE, Proj.data());
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
    scale4.block<2, 2>(0, 0) << mWidth, 0.0, 0.0, mHeight;

    return trans4 * rot4 * scale4;
}


