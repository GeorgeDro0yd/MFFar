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
    bool running = true;

    Screen screen;
    auto t = 0.0;

    while (running) {
        screen.update(t,2);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/60));
        t+= 1/fps;
    }


}
