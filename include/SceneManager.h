#pragma once

#include "Object.h"
#include "BaseManager.h"

class SceneManager : public BaseManager {
public:
    std::map<std::string, Object*> *objectList;
    CameraObject *camera;

    SceneManager() {};
    ~SceneManager() {};

    void startUp () override {
        camera = new CameraObject;
        objectList = new std::map<std::string, Object*>;
    }

    void shutDown () override {
        delete camera;
        objectList->clear();
        delete objectList;
    }

    bool createObject(std::string objectName) { // true if successful
        if (objectList->find(objectName) != objectList->end()) return false; // object created before
        else {
            (*objectList)[objectName] = new Object;
            if ((*objectList)[objectName] == NULL) return false;
            else return true;
        }
    }

    bool deleteObject(std::string objectName) {
        if (objectList->erase(objectName)) return true;
        else return false;
    }
/*
    bool modify (std::string objectName) {
        if (objectList->find(objectName) == objectList->end()) return false;
        else {
            (*objectList)[objectName] = new Object;
            if ((*objectList)[objectName] == NULL) return false;
            else return true;
        }
    }
    */
};
