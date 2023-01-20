#pragma once
#include "Vector3.h"
#include "Material.h"
#include "Ray.h"

class Object
{
public:
    Material material;
    Object(const Material &material);
    virtual bool intersect(const Ray &ray, Vector3 &point, Vector3 &normal) const = 0;
};