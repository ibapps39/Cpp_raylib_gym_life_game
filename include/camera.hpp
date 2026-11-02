#pragma once
#include "common.hpp"

typedef struct PLAYER_CAMERA
{
    Camera2D camera =
    { 
        .target = (Vec2){0,0},
        .offset = (Vec2){0,0},
        .rotation = 0.0f,
        .zoom = 1.0f
    };
} PlayerCam;


inline void update(PlayerCam& cam, Vec2 pos)
{
    cam.camera.target = pos;
    cam.camera.offset = pos;
}
