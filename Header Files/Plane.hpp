#pragma once
#include "Vector3.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include "Object.hpp"

class Plane : public Object
{
public:
    Vector3 point, normal;
    Plane(const Vector3 &point, const Vector3 &normal, const Material &material);
    bool intersect(const Ray &ray, Vector3 &intersectPoint, Vector3 &intersectNormal) const;
};