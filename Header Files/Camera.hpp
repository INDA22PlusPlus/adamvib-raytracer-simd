#pragma once
#include "Vector3.hpp"
#include "Ray.hpp"

class Camera
{
public:
    Vector3 position, forward, up;
    double fov, aspect;
    Camera(const Vector3 &position, const Vector3 &lookAt, double aspect, double fov);
    Ray getRay(double x, double y);
};