#pragma once 
#include <vector>
#include "Object.h"
#include "Light.h"
#include "Vector3.h"

class Scene
{
public:
    std::vector<Object *> objects;
    std::vector<Light> lights;
    Vector3 background;
    Scene(const Vector3 &background);
    void addObject(Object *object);
    void addLight(const Light &light);
    Vector3 trace(const Ray &ray, int depth);
};