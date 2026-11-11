#include <iostream>
#include <string>
#include <vector>
#include "math.h"
#include "include/math.h"
#include "include/render.h"
#include <chrono>
#include <thread>


auto fps = 120.0;

int main() {
    using clock = std::chrono::steady_clock;
    const float targetFps = 60.0f;

    Screen screen;
    float t = 0.0f;
    auto prev = clock::now();

    while (true) {
        auto now = clock::now();
        float dt = std::chrono::duration<float>(now - prev).count(); // секунды
        prev = now;
        if (dt > 0.1f) dt = 0.1f; // чтобы лаг не давал огромный шаг

        t += dt;
        screen.update(t, dt);

        std::this_thread::sleep_for(std::chrono::duration<float>(1.0f / targetFps));
    }
}