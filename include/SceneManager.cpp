#include "SceneManager.h"

void SceneManager::startUp() {
    StartScene* startScene = new StartScene;
    pPresScene.reset(startScene);
}

void SceneManager::shutDown() {
    if (pPresScene != NULL) delete pPresScene.release();
}

void SceneManager::runScene() {
    pPresScene->loadScene();
    pPresScene->initialize();
    pPresScene->_loopStart();
    pPresScene->unloadScene();
}

SceneManager gSceneManager;
