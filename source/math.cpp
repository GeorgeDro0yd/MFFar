#include "../include/math.h"

#include <cmath>

Vector3D::Vector3D(float a, float b, float c): x(a),y(b),z(c) {
}

float& Vector3D::operator [](int i) {
    return ((&x)[i]);
}

const float& Vector3D::operator [](int i) const {
    return ((&x)[i]);
}

Vector3D &Vector3D::operator*=(float s) {
    x*=s;
    y*=s;
    z*=s;
}

Vector3D Vector3D::operator/=(float s) {
    x/=s;
    y/=s;
    z/=s;
}

Vector3D operator*(const Vector3D &v, float s) {
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

Vector3D operator-(const Vector3D &v) {
    return (Vector3D(-v.x, -v.y , -v.z ));
}

Vector3D operator/(const Vector3D &v, float s) {
    return (Vector3D(v.x / s, v.y / s, v.z / s));
}

inline float d(const Vector3D& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z + v.z));
}

inline Vector3D Normalize(const Vector3D v) {
    return v/d(v);
}

Vector3D &Vector3D::operator+=(const Vector3D &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vector3D operator+(const Vector3D &a, const Vector3D &b) {
    return Vector3D(a.x +  b.x, a.y + b.y, a.z + b.z);
}
Vector3D operator-(const Vector3D &a, const Vector3D &b) {
    return Vector3D(a.x -  b.x, a.y - b.y, a.z - b.z);
}

std::ostream &operator<<(std::ostream &os, const Vector3D& v) {
    os<<'('<<v.x<<", "<<v.y<<", "<<v.z<<')';
    return os;
}



