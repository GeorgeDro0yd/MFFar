//
// Created by danydrain on 10.11.2026.
//

#ifndef HWADS_BUFFER_H
#define HWADS_BUFFER_H
#include <vector>
#include "3dObjects.h"
#include "cmath"
#include "3dPhysics.h"

const int w = 200,h = 60;

class Scene {
    public:

    std::vector<Object> objects_ = {Object()};
    Scene() {
        objects_[0].rigidbody = true;
    }
    void update(float t, float dt) {
       // objects_[0].rotY = t*10;
        if (objects_[0].rigidbody) {
            objects_[0].rb.update(dt);
            auto x = objects_[0].rb.v_x * dt;
            auto y = objects_[0].rb.v_y * dt;
            auto z = objects_[0].rb.v_z * dt;
            Vector3D move = {x,y,z};
            objects_[0].position += move;
        }



    }

};



class Buffer {
public:
    int width = w, height = h;

    void clear() {
        for (auto& x : pixels) {
            x = ' ';
        }
        for (auto& y : depth) {
            y = std::numeric_limits<float>::infinity();
        }
    }
    std::vector<char> pixels = std::vector<char>(height * width  , ' ');
    std::vector<float> depth= std::vector<float>(height * width, std::numeric_limits<float>::infinity());
private:

};

inline void Rasterize(const Vector3D& a, const Vector3D& b, const Vector3D& c, Buffer& buffer, char d = '#') {
    const int w = buffer.width, h = buffer.height;

    int x1 = std::floor(std::min(a.x, std::min(b.x, c.x)));
    int x2 = std::ceil (std::max(a.x, std::max(b.x, c.x)));
    int y1 = std::floor(std::min(a.y, std::min(b.y, c.y)));
    int y2 = std::ceil (std::max(a.y, std::max(b.y, c.y)));

    x1 = std::max(x1, 0);      x2 = std::min(x2, w - 1);
    y1 = std::max(y1, 0);      y2 = std::min(y2, h - 1);

    Vector3D n = Cross(b - a, c - a);
    if (n.z == 0) return;   // triangle is edge-on

    auto edge = [](const Vector3D& a, const Vector3D& b, float x, float y) -> float {
        return (b.x - a.x) * (y - a.y) - (b.y - a.y) * (x - a.x);
    };

    auto depthAt = [&](float x, float y) -> float {   // use the plane equation to find z
        return a.z - (n.x * (x - a.x) + n.y * (y - a.y)) / n.z;
    };

    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            float px = x + 0.5f, py = y + 0.5f;

            float e0 = edge(a, b, px, py);
            float e1 = edge(b, c, px, py);
            float e2 = edge(c, a, px, py);

            if ((e0 >= 0 && e1 >= 0 && e2 >= 0) || (e0 <= 0 && e1 <= 0 && e2 <= 0)) {
                float z = depthAt(px, py);
                int i = y * w + x;
                if (z > 0 && z < buffer.depth[i]) {
                    buffer.pixels[i] = d;
                    buffer.depth[i] = z;
                }
            }
        }
    }
}


inline Vector4D toVector4D(const Vector3D& a) {
    return Vector4D(a.x, a.y, a.z, 1.0);
}

inline void drawPov(const Scene& scene, Buffer& buffer) {
    for (auto& x : scene.objects_) {
        for (int i = 0; i<x.mesh->indices.size()/3; i++) {
            auto Global = MakeTransform(x);
            auto a = Global * toVector4D(x.mesh->vertices[x.mesh->indices[3 * i]]);
            auto b = Global * toVector4D(x.mesh->vertices[x.mesh->indices[3 * i + 1]]);
            auto c = Global * toVector4D(x.mesh->vertices[x.mesh->indices[3 * i + 2]]);

            auto d = x.mesh->color[i];
            //NOW PROJECT TO CAMERA; camera is basically a rectangle which center is located on (0,0,0) as first version
            float f = 40.0f;  // focus distance
            auto camA = Vector3D(buffer.width/2.0 + 2.0f * f * a.x / a.z,
                                 buffer.height/2.0 - f * a.y / a.z,
                                 a.z);
            auto camB = Vector3D(buffer.width/2.0 + 2.0f * f * b.x / b.z,
                                 buffer.height/2.0 - f * b.y / b.z,
                                 b.z);
            auto camC = Vector3D(buffer.width/2.0 + 2.0f * f * c.x / c.z,
                                 buffer.height/2.0 - f * c.y / c.z,
                                 c.z);
            Rasterize(camA, camB, camC, buffer,d);


        }

    }
    
};


#endif //HWADS_BUFFER_H