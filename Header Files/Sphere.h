#pragma once
#include "Vector3.h"
#include "Material.h"
#include "Ray.h"
#include "Object.h"

class Sphere : public Object
{
public:
    Vector3 center;
    double radius;
    Sphere(const Vector3 &center, double radius, const Material &material);
    bool intersect(const Ray &ray, Vector3 &point, Vector3 &normal) const;
};