#pragma once
#include "common.hpp"


class PlayerCam
{
    public:
    Camera2D camera;
    PlayerCam()
    {
        camera.target = (Vec2){0,0};
        camera.offset = (Vec2){0,0};
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;
    }
    PlayerCam(Vec2 player_pos)
    {
        camera.target = player_pos;
        camera.offset = player_pos;
        camera.rotation = 0.0f;
        camera.zoom = 1.0f;
    }
    void update(Vec2 pos)
    {
        camera.target = pos;
        camera.offset = pos;
    }
    void zoom(float zoom)
    {
        camera.zoom = zoom;
    }
};