#pragma once

class Vec2 {
    double pos[3];
    double &x = pos[0], &y = pos[1], &w = pos[2]; // w refers to homogeneous ratio

public:
    Vec2 () {
        x = y = 0;
        w = 1;
    }

    Vec2 (int tempx, int tempy, int tempw = 1) {
        x = tempx;
        y = tempy;
        w = tempw;
    }

    static Vec2 one () {
        return Vec2(1, 1);
    }

    static Vec2 zero () {
        return Vec2(0, 0);
    }

    Vec2 operator = (const Vec2 &temp) {
        x = temp.x; y = temp.y; w = temp.w; // attention if variables are modified
        return temp;
    }

    Vec2 operator + (const Vec2 &temp) {
        return Vec2(x + temp.x, y + temp.y, w + temp.w);
    }
};

class Object {
public:
    Vec2 position;
    Vec2 scale;
    int layer;     // object with lower layer gains higher priority.
                   // the renderer should not render the object if layer < camera layer.

    // any other things ...

public:
    Object () {
        position = Vec2::zero();
        scale = Vec2::one();
        layer = 0;
    }

    virtual ~Object() {}
};

class CameraObject : public Object{
};
