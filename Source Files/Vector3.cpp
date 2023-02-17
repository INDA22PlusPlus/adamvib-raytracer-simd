#include "Vector3.hpp"
#include <cmath>
#include <immintrin.h>

constexpr int SHUFFLE_MASK_0 = _MM_SHUFFLE(0, 2, 1, 0);
constexpr int SHUFFLE_MASK_1 = _MM_SHUFFLE(0, 0, 2, 1);

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
Vector3 Vector3::cross(const Vector3 &v) const {
    __m256d vec0 = _mm256_set_pd(x, y, z, 0);
    __m256d vec1 = _mm256_set_pd(v.x, v.y, v.z, 0);

    __m256d a_yzx = _mm256_shuffle_pd(vec0, vec0, SHUFFLE_MASK_0);
    __m256d b_yzx = _mm256_shuffle_pd(vec1, vec1, SHUFFLE_MASK_0);

    __m256d a_zxy = _mm256_shuffle_pd(vec0, vec0, SHUFFLE_MASK_1);
    __m256d b_zxy = _mm256_shuffle_pd(vec1, vec1, SHUFFLE_MASK_1);

    __m256d result = _mm256_sub_pd(_mm256_mul_pd(a_yzx, b_zxy), _mm256_mul_pd(b_yzx, a_zxy));

    return Vector3(result[0], result[1], result[2]);
}
Vector3 Vector3::avarage(const Vector3 &v) const { return (*this + v) / 2; }