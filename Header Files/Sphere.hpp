#pragma once
#include "Vector3.hpp"
#include "Material.hpp"
#include "Ray.hpp"
#include "Object.hpp"

class Sphere : public Object
{
public:
    Vector3 center;
    double radius;
    Sphere(const Vector3 &center, double radius, const Material &material);
    bool intersect(const Ray &ray, Vector3 &point, Vector3 &normal) const;
};