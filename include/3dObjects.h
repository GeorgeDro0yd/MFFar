//
// Created by danydrain on 10.11.2026.
//

#ifndef HWADS_3DOBJECTS_H
#define HWADS_3DOBJECTS_H
#include <vector>

#include "math.h"

struct Mesh {
    std::vector<Vector3D> vertices;
    std::vector<int> indices;
    std::vector<char> color;
    Mesh(std::vector<Vector3D> vertices, std::vector<int> indices, std::vector<char> color) {
        this->vertices = std::move(vertices);
        this->indices = std::move(indices);
        this->color = std::move(color);
    }
};



const float len = 20.0f;      // длина ребра
const float H = len / 2;      // половина, координаты вершин

const Mesh Cube(
    {
        {-H, -H, -H},   // 0
        { H, -H, -H},   // 1
        { H,  H, -H},   // 2
        {-H,  H, -H},   // 3
        {-H, -H,  H},   // 4
        { H, -H,  H},   // 5
        { H,  H,  H},   // 6
        {-H,  H,  H}    // 7
    },
    {
        4, 5, 6,   4, 6, 7,   // z = +h
        1, 0, 3,   1, 3, 2,   // z = -h
        5, 1, 2,   5, 2, 6,   // x = +h
        0, 4, 7,   0, 7, 3,   // x = -h
        3, 7, 6,   3, 6, 2,   // y = +h
        0, 1, 5,   0, 5, 4    // y = -h
    },
    {
        '^', '^',
        '#', '#',
        '%', '%',
        'A', 'A',
        '-', '-',
        ':',':',
        'f','f',
        '?','?'



    }
);



struct Object {
    const Mesh*    mesh;

    Vector3D position;
    float    angle;
    explicit Object(const Mesh* mesh = &Cube, Vector3D position = {0,0,len + 10}, float angle = 0) :
    mesh(mesh), position(position), angle(angle)  {

    }
};


Matrix4D MakeTransform(const Object& o) {
    Matrix3D r = MakeRotationY(o.angle);
    const Vector3D& p = o.position;

    return Matrix4D(r(0,0), r(0,1), r(0,2), p.x,
                    r(1,0), r(1,1), r(1,2), p.y,
                    r(2,0), r(2,1), r(2,2), p.z,
                    0,      0,      0,      1);
}




#endif //HWADS_3DOBJECTS_H