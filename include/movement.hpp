#pragma once
#include "common.hpp"
namespace movement
{
inline Vec2 move_input()
{
    Vec2 dir = {0};

    if (IsKeyDown(KEY_W)) dir = dir+UP;
    if (IsKeyDown(KEY_S)) dir = dir-UP;
    if (IsKeyDown(KEY_D)) dir = dir+(Vec2){1,0};
    if (IsKeyDown(KEY_A)) dir = dir+(Vec2){-1,0};
    return dir;
}

inline Vec2 move(const Vec2 pos, const Vec2 direction_unit_vector, const float speed, const float dt)
{
    return pos + (direction_unit_vector*(speed*dt));
}

}