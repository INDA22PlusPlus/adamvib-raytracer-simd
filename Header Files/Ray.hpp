#pragma once
#include "Vector3.hpp"

class Ray
{
public:
    Vector3 origin, direction;
    Ray(const Vector3 &origin, const Vector3 &direction);
};