#include "Vector3.hpp"
#include <cmath>

Vector3::Vector3() : x(0), y(0), z(0) {}
Vector3::Vector3(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3 &v) const { return Vector3(x + v.x, y + v.y, z + v.z); }
Vector3 Vector3::operator-(const Vector3 &v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
Vector3 Vector3::operator*(const Vector3 &v) const { return Vector3(x * v.x, y * v.y, z * v.z); }
Vector3 Vector3::operator*(double s) const { return Vector3(x * s, y * s, z * s); }
Vector3 Vector3::operator/(double s) const { return Vector3(x / s, y / s, z / s); }
Vector3 Vector3::operator-() const { return Vector3(-x, -y, -z); }

double Vector3::dot(const Vector3 &v) const { return x * v.x + y * v.y + z * v.z; }
double Vector3::length() const { return sqrt(x * x + y * y + z * z); }
Vector3 Vector3::normalize() const { return (*this) / length(); }
Vector3 Vector3::cross(const Vector3 &v) const { return Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
Vector3 Vector3::avarage(const Vector3 &v) const { return (*this + v) / 2; }