#include "Plane.h"
#include <cmath>

Plane::Plane(const Vector3 &point, const Vector3 &normal, const Material &material) : Object(material), point(point), normal(normal) {}

bool Plane::intersect(const Ray &ray, Vector3 &intersectPoint, Vector3 &intersectNormal) const
{
    double denom = this->normal.dot(ray.direction);
    if (fabs(denom) > 1e-6)
    {
        double t = (point - ray.origin).dot(this->normal) / denom;
        if (t >= 0)
        {
            intersectPoint = ray.origin + ray.direction * t;
            intersectNormal = this->normal;
            return true;
        }
    }
    return false;
}