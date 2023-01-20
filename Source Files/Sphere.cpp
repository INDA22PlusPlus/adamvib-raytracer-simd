#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vector3 &center, double radius, const Material &material) : Object(material), center(center), radius(radius) {}

bool Sphere::intersect(const Ray &ray, Vector3 &point, Vector3 &normal) const
{
    Vector3 oc = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return false;
    double t = (-b - sqrt(discriminant)) / (2 * a);
    if (t < 0)
        return false;
    point = ray.origin + ray.direction * t;
    normal = (point - center).normalize();
    return true;
}