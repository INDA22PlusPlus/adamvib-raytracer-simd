#pragma once 

class alignas(32) Vector3
{
public:
    alignas(32) double x, y, z;
    Vector3();
    Vector3(double x, double y, double z);

    Vector3 operator+(const Vector3 &v) const;
    Vector3 operator-(const Vector3 &v) const;
    Vector3 operator*(const Vector3 &v) const;
    Vector3 operator*(double s) const;
    Vector3 operator/(double s) const;
    Vector3 operator-() const;

    double dot(const Vector3 &v) const;
    double length() const;
    Vector3 normalize() const;
    Vector3 cross(const Vector3 &v) const;
    Vector3 avarage(const Vector3 &v) const;
};