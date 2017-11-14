#include "Sprite.h"
#include "Scene.h"

Sprite::Sprite() {
    this->pShaderProgram = gRenderManager.getDefaultShader();
    _spriteConstructor();
}

Sprite::Sprite(ShaderProgram* pShaderProgram) {
    this->pShaderProgram = pShaderProgram;
    _spriteConstructor();
}

void Sprite::_spriteConstructor() {
    mColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
    mPos = glm::vec3(0.0f, 0.0f, 0.0f);
    mWidth = 1.0f;
    mHeight = 1.0f;
}

Sprite::~Sprite() {
    //gRenderManager.removeSpriteFromRenderQueue(mIndex);
}

void Sprite::draw(const Camera& camera) {
    pShaderProgram->activate();
    //Camera* camera = ??? //gRenderManager.getDefaultCamera();

    GLint colorLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uPixelColor");
    GLint matrixLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uModelTransform");
    GLint VLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uViewTransform");
    GLint PLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uProjectTransform");
    glUniform4f(colorLocation, mColor.r, mColor.g, mColor.b, mColor.a);

    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, &(getTransformMatrix()[0][0]));
    glUniformMatrix4fv(VLocation, 1, GL_FALSE, &(camera.getViewMatrix()[0][0]));
    glUniformMatrix4fv(PLocation, 1, GL_FALSE, &(camera.getProjMatrix()[0][0]));

    /*
    glm::mat4 model = getTransformMatrix();
    glm::mat4 view = camera->getViewMatrix();
    glm::mat4 proj = camera->getProjMatrix();
    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, &model[0][0]);
    glUniformMatrix4fv(VLocation, 1, GL_FALSE, &view[0][0]);
    glUniformMatrix4fv(PLocation, 1, GL_FALSE, &proj[0][0]);
    */

    // use glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) to draw wire frame.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL) to set as default.
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    //glm::vec4 pos4;
    //pos4 << 0.0, 0.0, 0.0, 1.0;
    //std::cout << View << std::endl;
    //std::cout << getTransformMatrix() << std::endl;
    //std::cout << Proj << std::endl;
    //std::cout << Proj * View * getTransformMatrix() * pos4 << std::endl;
}

void Sprite::setColor(glm::vec4 color) { // this maybe useless.
    mColor = color;
}

void Sprite::setColor(float r, float g, float b, float a) {
    mColor = glm::vec4(r, g, b, a);
}

glm::vec4 Sprite::getColor() const {
    return mColor;
}

void Sprite::setPos(glm::vec3 pos) {
    mPos = pos;
}

void Sprite::setPos(float x, float y, float z) {
    mPos = glm::vec3(x, y, z);
}

void Sprite::incPos(glm::vec3 dPos) {
    mPos += dPos;
}

void Sprite::incPos(float dx, float dy, float dz) {
    mPos.x += dx;
    mPos.y += dy;
    mPos.x += dz;
}

glm::vec3 Sprite::getPos() const {
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

glm::mat4 Sprite::getTransformMatrix() {
    glm::mat4 trans;
    trans = glm::mat4(1.0f);
    trans = glm::translate(trans, mPos);
    trans = glm::rotate(trans, mRotateRad,  glm::vec3(0.0, 0.0, 1.0));
    trans = glm::scale(trans, glm::vec3(mWidth, mHeight, 1.0f));
    return trans;
}




