#pragma once
#include "Vector3.h"

class Material
{
public:
    Vector3 color;
    double reflectivity;
    Material(const Vector3 &color, double reflectivity);
};