#include "Sprite.h"


Sprite::Sprite() {
    mColor << 1, 1, 1, 1;
    this->pShaderProgram = gRenderManager.getDefaultShader();
    gRenderManager.addSpriteToRenderQueue(this);
}

Sprite::Sprite (ShaderProgram* pShaderProgram) {
    mColor << 1, 1, 1, 1;
    this->pShaderProgram = pShaderProgram;
    gRenderManager.addSpriteToRenderQueue(this);
}

void Sprite::draw() {
    pShaderProgram->activate();
    GLint colorLocation = glGetUniformLocation(pShaderProgram->getShaderProgramLocation(), "uPixelColor");
    glUniform4f(colorLocation, mColor(0), mColor(1), mColor(2), mColor(3));
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}

void Sprite::setColor(Eigen::Vector4f color) {
    mColor = color;
}

void Sprite::setColor(float r, float g, float b, float a) {
    mColor << r, g, b, a;
}
