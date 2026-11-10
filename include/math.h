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

float Dot(const Vector3D& a, const Vector3D& b);

Vector3D Cross(const Vector3D& a, const Vector3D& b);

Vector3D Project(const Vector3D& a, const Vector3D& b);

Vector3D Reject(const Vector3D& a, const Vector3D& b);

std::ostream& operator<<(std::ostream& os, const Vector3D&);

struct Matrix3D {
private:
    float n[3][3];
public:
    Matrix3D() = default;
    Matrix3D(float n00, float n01, float n02,
            float n10, float n11, float n12,
            float n20, float n21, float n22) {
        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
    }
    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c) {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
    }

    float& operator ()(int i , int j);

    const float& operator ()(int i , int j) const;

    Vector3D& operator [] (int j);

    const Vector3D& operator[](int j) const;



};




Matrix3D operator *(const Matrix3D& A, const Matrix3D& B);

Vector3D operator *(const Matrix3D& M, const Vector3D& v);

float Determinant(const Matrix3D& M);

Matrix3D Inverse(const Matrix3D& M);
struct Vector4D {
    float x,y,z,w;

    Vector4D() = default;

    Vector4D(float a, float b, float c, float d);

    float& operator [](int i);

    const float& operator [](int i) const;

    Vector4D& operator *=(float s);

    Vector4D& operator /=(float s);

    Vector4D& operator +=(const Vector4D& v);

    Vector4D& operator -=(const Vector4D& v);

};

Vector4D operator *(const Vector4D& v, float s);

Vector4D operator /(const Vector4D& v, float s);

Vector4D operator -(const Vector4D& v);

float d(const Vector4D& v); //Magnitude

Vector4D Normalize(const Vector4D& v);

Vector4D operator +(const Vector4D& a, const Vector4D& b);

Vector4D operator -(const Vector4D& a, const Vector4D& b);

float Dot(const Vector4D& a, const Vector4D& b);

Vector4D Project(const Vector4D& a, const Vector4D& b);

Vector4D Reject(const Vector4D& a, const Vector4D& b);

std::ostream& operator<<(std::ostream& os, const Vector4D&);

struct Matrix4D {
private:
    float n[4][4];
public:
    Matrix4D() = default;
    Matrix4D(float n00, float n01, float n02, float n03,
             float n10, float n11, float n12, float n13,
             float n20, float n21, float n22, float n23,
             float n30, float n31, float n32, float n33) {
        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
        n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
    }
    Matrix4D(const Vector4D& a, const Vector4D& b, const Vector4D& c, const Vector4D& d) {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; n[0][3] = a.w;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; n[1][3] = b.w;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; n[2][3] = c.w;
        n[3][0] = d.x; n[3][1] = d.y; n[3][2] = d.z; n[3][3] = d.w;
    }

    float& operator ()(int i, int j);

    const float& operator ()(int i, int j) const;

    Vector4D& operator [](int j);

    const Vector4D& operator [](int j) const;
};

Matrix4D operator *(const Matrix4D& A, const Matrix4D& B);

Vector4D operator *(const Matrix4D& M, const Vector4D& v);

float Determinant(const Matrix4D& M);

Matrix4D Inverse(const Matrix4D& M);

Matrix3D MakeRotationX(float t);

Matrix3D MakeRotationY(float t);

Matrix3D MakeRotationZ(float t);

Matrix3D MakeRotation(float t, const Vector3D& a);


#endif //HWADS_MATH_H