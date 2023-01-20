#pragma once 
#include <vector>
#include "Object.hpp"
#include "Light.hpp"
#include "Vector3.hpp"

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