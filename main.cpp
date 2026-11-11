#include <iostream>
#include <string>
#include <vector>
#include "math.h"
#include "include/math.h"
#include "include/render.h"


int main() {
    Vector3D a(0,0,5);
    Vector3D b(0, 15, 5);
    Vector3D c(30, 0, 5);
    Screen screen;
    Rasterize(a,b,c,screen.buffer);
    screen.update(1,2);

}
