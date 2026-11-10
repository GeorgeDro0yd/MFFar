//
// Created by Apple on 10/11/2026.
//

#ifndef HWADS_MATH_H
#define HWADS_MATH_H
#include <iostream>

struct Vector3D {
    float x,y,z;

    Vector3D() = default;

    Vector3D(float a, float b, float c);

    float& operator [](int i);

    const float& operator [](int i) const;

    Vector3D& operator *=(float s);

    Vector3D operator /=(float s);

    Vector3D& operator +=(const Vector3D& v);

    Vector3D& operator -=(const Vector3D& v);

};

Vector3D operator *(const Vector3D& v, float s); //scalar product

Vector3D operator /(const Vector3D& v, float s); //also scalar product

Vector3D operator -(const Vector3D& v);

float d(const Vector3D& v); //Magnitude

Vector3D Normalize(const Vector3D v);

Vector3D operator +(const Vector3D& a, const Vector3D& b);

Vector3D operator -(const Vector3D& a, const Vector3D& b);

std::ostream& operator<<(std::ostream& os, const Vector3D&);

struct Matrix3D {
private:
    float n[3][3];
public:
    Matrix3D() = default;
    Matrix3D(float n00, float n01, float n02,
            float n10, float n11, float n12,
            float n20, float n21, float n22) {
        n[0][0] = n00; n[0][1] = n00; n[0][2] = n02;
        n[1][0] = n10; n[1][1] = n10; n[1][2] = n12;
        n[2][0] = n20; n[2][1] = n20; n[2][2] = n22;
    }
    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c) {
        n[0][0] = a.x; n[0][1] = b.x; n[0][2] = c.x;
        n[1][0] = a.y; n[1][1] = b.y; n[1][2] = c.y;
        n[2][0] = a.z; n[2][1] = b.z; n[2][2] = c.z;
    }

};






#endif //HWADS_MATH_H