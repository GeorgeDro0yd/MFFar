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
    return *this;
}

Vector3D Vector3D::operator/=(float s) {
    x/=s;
    y/=s;
    z/=s;
    return *this;
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

float d(const Vector3D& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

Vector3D Normalize(const Vector3D v) {
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

float &Matrix3D::operator()(int i, int j) {
    return (n[j][i]);
}

const float &Matrix3D::operator()(int i, int j) const {
    return (n[j][i]);
}


Vector3D &Matrix3D::operator[](int j) {
    return (*reinterpret_cast<Vector3D *>(n[j]));
}

const Vector3D &Matrix3D::operator[](int j) const {
    return *reinterpret_cast<const Vector3D*>(n[j]);
}


Matrix3D operator *(const Matrix3D& A, const Matrix3D& B) {
    return Matrix3D(
        A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
        A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
        A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),

        A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
        A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
        A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),

        A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
        A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
        A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)
    );
}

Vector3D operator *(const Matrix3D& M, const Vector3D& v) {
    return Vector3D(
        M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z,
        M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z,
        M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z
    );
}

float Dot(const Vector3D& a, const Vector3D& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3D Cross(const Vector3D& a, const Vector3D& b) {
    return Vector3D(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
        );
}

Vector3D Project(const Vector3D& a, const Vector3D& b) {
    return b * (Dot(a, b)/Dot(b,b));
}

Vector3D Reject(const Vector3D& a, const Vector3D& b) {
    return a - Project(a, b);
}

float Determinant(const Matrix3D& M) {
    return M(0,0) * (M(1,1) * M(2,2) - M(1,2) * M(2,1))
         + M(0,1) * (M(1,2) * M(2,0) - M(1,0) * M(2,2))
         + M(0,2) * (M(1,0) * M(2,1) - M(1,1) * M(2,0));
}

Matrix3D Inverse(const Matrix3D& M) {
    const Vector3D& a = M[0];
    const Vector3D& b = M[1];
    const Vector3D& c = M[2];

    Vector3D r0 = Cross(b, c);
    Vector3D r1 = Cross(c, a);
    Vector3D r2 = Cross(a, b);

    float invDet = 1.0f / Dot(r2, c);

    return Matrix3D(
        r0.x * invDet, r0.y * invDet, r0.z * invDet,
        r1.x * invDet, r1.y * invDet, r1.z * invDet,
        r2.x * invDet, r2.y * invDet, r2.z * invDet
    );

}

Vector4D::Vector4D(float a, float b, float c, float d): x(a),y(b),z(c),w(d) {
}

float& Vector4D::operator [](int i) {
    return ((&x)[i]);
}

const float& Vector4D::operator [](int i) const {
    return ((&x)[i]);
}

Vector4D &Vector4D::operator*=(float s) {
    x*=s;
    y*=s;
    z*=s;
    w*=s;
    return *this;
}

Vector4D &Vector4D::operator/=(float s) {
    x/=s;
    y/=s;
    z/=s;
    w/=s;
    return *this;
}

Vector4D &Vector4D::operator+=(const Vector4D &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    w += v.w;
    return *this;
}

Vector4D &Vector4D::operator-=(const Vector4D &v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    w -= v.w;
    return *this;
}

Vector4D operator*(const Vector4D &v, float s) {
    return (Vector4D(v.x * s, v.y * s, v.z * s, v.w * s));
}

Vector4D operator/(const Vector4D &v, float s) {
    return (Vector4D(v.x / s, v.y / s, v.z / s, v.w / s));
}

Vector4D operator-(const Vector4D &v) {
    return (Vector4D(-v.x, -v.y, -v.z, -v.w));
}

float d(const Vector4D& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z) + (v.w * v.w));
}

Vector4D Normalize(const Vector4D& v) {
    return v/d(v);
}

Vector4D operator+(const Vector4D &a, const Vector4D &b) {
    return Vector4D(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
}

Vector4D operator-(const Vector4D &a, const Vector4D &b) {
    return Vector4D(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
}

float Dot(const Vector4D& a, const Vector4D& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vector4D Project(const Vector4D& a, const Vector4D& b) {
    return b * (Dot(a, b)/Dot(b,b));
}

Vector4D Reject(const Vector4D& a, const Vector4D& b) {
    return a - Project(a, b);
}

std::ostream &operator<<(std::ostream &os, const Vector4D& v) {
    os<<'('<<v.x<<", "<<v.y<<", "<<v.z<<", "<<v.w<<')';
    return os;
}

float &Matrix4D::operator()(int i, int j) {
    return (n[j][i]);
}

const float &Matrix4D::operator()(int i, int j) const {
    return (n[j][i]);
}

Vector4D &Matrix4D::operator[](int j) {
    return (*reinterpret_cast<Vector4D *>(n[j]));
}

const Vector4D &Matrix4D::operator[](int j) const {
    return *reinterpret_cast<const Vector4D*>(n[j]);
}

Matrix4D operator *(const Matrix4D& A, const Matrix4D& B) {
    return Matrix4D(
        A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0) + A(0,3) * B(3,0),
        A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1) + A(0,3) * B(3,1),
        A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2) + A(0,3) * B(3,2),
        A(0,0) * B(0,3) + A(0,1) * B(1,3) + A(0,2) * B(2,3) + A(0,3) * B(3,3),

        A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0) + A(1,3) * B(3,0),
        A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1) + A(1,3) * B(3,1),
        A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2) + A(1,3) * B(3,2),
        A(1,0) * B(0,3) + A(1,1) * B(1,3) + A(1,2) * B(2,3) + A(1,3) * B(3,3),

        A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0) + A(2,3) * B(3,0),
        A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1) + A(2,3) * B(3,1),
        A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2) + A(2,3) * B(3,2),
        A(2,0) * B(0,3) + A(2,1) * B(1,3) + A(2,2) * B(2,3) + A(2,3) * B(3,3),

        A(3,0) * B(0,0) + A(3,1) * B(1,0) + A(3,2) * B(2,0) + A(3,3) * B(3,0),
        A(3,0) * B(0,1) + A(3,1) * B(1,1) + A(3,2) * B(2,1) + A(3,3) * B(3,1),
        A(3,0) * B(0,2) + A(3,1) * B(1,2) + A(3,2) * B(2,2) + A(3,3) * B(3,2),
        A(3,0) * B(0,3) + A(3,1) * B(1,3) + A(3,2) * B(2,3) + A(3,3) * B(3,3)
    );
}

Vector4D operator *(const Matrix4D& M, const Vector4D& v) {
    return Vector4D(
        M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z + M(0,3) * v.w,
        M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z + M(1,3) * v.w,
        M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z + M(2,3) * v.w,
        M(3,0) * v.x + M(3,1) * v.y + M(3,2) * v.z + M(3,3) * v.w
    );
}

float Determinant(const Matrix4D& M) {
    const Vector3D& a = reinterpret_cast<const Vector3D&>(M[0]);
    const Vector3D& b = reinterpret_cast<const Vector3D&>(M[1]);
    const Vector3D& c = reinterpret_cast<const Vector3D&>(M[2]);
    const Vector3D& d = reinterpret_cast<const Vector3D&>(M[3]);

    const float& x = M(3,0);
    const float& y = M(3,1);
    const float& z = M(3,2);
    const float& w = M(3,3);

    Vector3D s = Cross(a, b);
    Vector3D t = Cross(c, d);
    Vector3D u = a * y - b * x;
    Vector3D v = c * w - d * z;

    return Dot(s, v) + Dot(t, u);
}

Matrix4D Inverse(const Matrix4D& M) {
    const Vector3D& a = reinterpret_cast<const Vector3D&>(M[0]);
    const Vector3D& b = reinterpret_cast<const Vector3D&>(M[1]);
    const Vector3D& c = reinterpret_cast<const Vector3D&>(M[2]);
    const Vector3D& d = reinterpret_cast<const Vector3D&>(M[3]);

    const float& x = M(3,0);
    const float& y = M(3,1);
    const float& z = M(3,2);
    const float& w = M(3,3);

    Vector3D s = Cross(a, b);
    Vector3D t = Cross(c, d);
    Vector3D u = a * y - b * x;
    Vector3D v = c * w - d * z;

    float invDet = 1.0F / (Dot(s, v) + Dot(t, u));
    s *= invDet;
    t *= invDet;
    u *= invDet;
    v *= invDet;

    Vector3D r0 = Cross(b, v) + t * y;
    Vector3D r1 = Cross(v, a) - t * x;
    Vector3D r2 = Cross(d, u) + s * w;
    Vector3D r3 = Cross(u, c) - s * z;

    return (Matrix4D(r0.x, r0.y, r0.z, -Dot(b, t),
                     r1.x, r1.y, r1.z,  Dot(a, t),
                     r2.x, r2.y, r2.z, -Dot(d, s),
                     r3.x, r3.y, r3.z,  Dot(c, s)));
}