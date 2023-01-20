#pragma once
#include "Vector3.h"
#include "Material.h"
#include "Ray.h"
#include "Object.h"

class Plane : public Object
{
public:
    Vector3 point, normal;
    Plane(const Vector3 &point, const Vector3 &normal, const Material &material);
    bool intersect(const Ray &ray, Vector3 &intersectPoint, Vector3 &intersectNormal) const;
};