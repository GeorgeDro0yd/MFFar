//
// Created by danydrain on 10.11.2026.
//

#ifndef HWADS_BUFFER_H
#define HWADS_BUFFER_H
#include <vector>
#include "3dObjects.h"
#include "cmath"

const int w = 110,h = 30;


class Buffer {
public:
    int width = w, height = h;
    void update(float t, float dt) {

    }

    std::vector<char> pixels = std::vector<char>(height * width  , 'a');
    std::vector<float> depth= std::vector<float>(height * width, 0.1);
private:

};

void Rasterize(Vector3D& a, Vector3D& b, Vector3D& c, char d = '#') {
    int x1 = std::floor(std::min(a.x, std::min(b.x, c.x)));
    int x2 = std::ceil (std::max(a.x, std::max(b.x, c.x)));
    int y1 = std::floor(std::min(a.y, std::min(b.y, c.y)));
    int y2 = std::ceil (std::max(a.y, std::max(b.y, c.y)));

    if (x2 < 0 || x1 >= w || y2 < 0 || y1 >= h) {
        // TO DO LOGGER
        return;
    }
    auto edge = [](const Vector3D& a, const Vector3D& b, float x, float y) -> float {
        return (b.x - a.x) * (y - a.y) - (b.y - a.y) * (x - a.x);
    };
    for (int y = y1; y <= y2; y++) {
        for (int x = x1; x <= x2; x++) {
            float e0 = edge(a, b, x + 0.5f, y + 0.5f);
            float e1 = edge(b, c, x + 0.5f, y + 0.5f);
            float e2 = edge(c, a, x + 0.5f, y + 0.5f);

            if ((e0 >= 0 && e1 >= 0 && e2 >= 0) || (e0 <= 0 && e1 <= 0 && e2 <= 0)) {

            }
        }
    }

}


#endif //HWADS_BUFFER_H