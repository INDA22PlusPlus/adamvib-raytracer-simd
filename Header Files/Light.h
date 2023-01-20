#pragma once
#include "Vector3.h"

class Light
{
public:
    Vector3 position, color;
    Light(const Vector3 &position, const Vector3 &color);
};