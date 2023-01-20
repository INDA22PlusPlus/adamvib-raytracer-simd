#include "Camera.h"
#include <cmath>

#define PI 3.14159265

Camera::Camera(const Vector3 &position, const Vector3 &lookAt, double aspect, double fov) : position(position), forward((lookAt - position).normalize()), up(Vector3(0, 1, 0)), aspect(aspect), fov(fov) {}

Ray Camera::getRay(double x, double y)
{
    Vector3 right = forward.cross(up);
    double tanFov = tan(fov * PI / 180 / 2);
    Vector3 rayDirection = (forward + (right * (x - 0.5) * tanFov * aspect + up * (y - 0.5))).normalize();
    return Ray(position, rayDirection);
}