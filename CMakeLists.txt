cmake_minimum_required(VERSION 4.0)
project(hwads)

set(CMAKE_CXX_STANDARD 20)

add_executable(hwads main.cpp
        include/math.h
        source/math.cpp
        include/buffer.h
        include/3dObjects.h
        include/render.h
        include/import_obj.h
        include/3dPhysics.h
)
