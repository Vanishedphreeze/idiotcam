#include "StartScene.h"

#define PI 3.1415926535897932384626

void StartScene::loadScene() {
    redsq = new Sprite();
    yellowsq = new Sprite();
}

void StartScene::initialize() {
    addSpriteToRenderQueue(*redsq);
    addSpriteToRenderQueue(*yellowsq);

    redsq->setColor(1, 0, 0, 0);
    yellowsq->setColor(1, 1, 0, 0);

    redsq->setPos(-15, -5, 0);
    redsq->setScale(25, 40);
    redsq->setAngleByRad(PI / 6);

    yellowsq->setPos(20, 10, 0.1);
    yellowsq->setScale(30, 30);
    yellowsq->setAngleByRad(PI / 4);

    defaultCamera.setBgColor(0, 1, 0, 1);
    defaultCamera.setViewport(112, 84, 800, 600);
}

void StartScene::update() {
    yellowsq->incAngleByRad(0.01);
    redsq->incAngleByRad(-0.05);
    redsq->incPos(0.2, 0.1, 0.0);
    if (gInputManager.isKeyClicked(InputManager::KEYBOARD_W)) yellowsq->incPos( 0.0, 5.0, 0.0);
    if (gInputManager.isKeyReleased(InputManager::KEYBOARD_S)) yellowsq->incPos(0.0,-5.0, 0.0);
    if (gInputManager.isKeyPressed(InputManager::KEYBOARD_A)) yellowsq->incPos(-0.2, 0.0, 0.0);
    if (gInputManager.isKeyPressed(InputManager::KEYBOARD_D)) yellowsq->incPos( 0.2, 0.0, 0.0);
    if (gInputManager.isKeyPressed(InputManager::KEYBOARD_ESCAPE)) exitScene();
}

void StartScene::unloadScene() {
    // remove the object from render queue before delete
    removeSpriteFromRenderQueue(*redsq);
    removeSpriteFromRenderQueue(*yellowsq);
    delete redsq;
    delete yellowsq;
}

StartScene::~StartScene() {
    removeSpriteFromRenderQueue(*redsq);
    removeSpriteFromRenderQueue(*yellowsq);
    delete redsq;
    delete yellowsq;
}
