//
// Created by danydrain on 11.11.2026.
//

#ifndef HWADS_RENDER_H
#define HWADS_RENDER_H
#include "buffer.h"
#include <iostream>
struct Screen {
    Buffer buffer;
    void update(float t, float dt) {
        buffer.update(t, dt);

        std::string frame = "\x1b[H";
        for (int i = 0; i < buffer.height; i++) {
            for (int j = 0; j < buffer.width; j++) {
                frame += buffer.pixels[i * buffer.width + j];
            }
            frame += '\n';
        }
        std::cout << frame << std::flush;
    }
};


#endif //HWADS_RENDER_H