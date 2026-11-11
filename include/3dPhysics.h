//
// Created by danydrain on 11.11.2026.
//

#ifndef HWADS_3DPHYSICS_H
#define HWADS_3DPHYSICS_H

const float Gravity = 9.81f;

struct Rigidbody {
    float a_x = 0, a_y = -Gravity, a_z = 0;
    float v_x = 0, v_y = 0, v_z = 0;
    float mass;
    void update(float dt) {
        v_x += a_x * dt;
        v_y += a_y * dt;
        v_z += a_z * dt;
    }

};

#endif //HWADS_3DPHYSICS_H