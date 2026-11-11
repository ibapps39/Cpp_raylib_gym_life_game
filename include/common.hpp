#pragma once

#include "raylib.h"
#include "raymath.h"

// Type Aliases
typedef Vector3 Vec3;
typedef Vector2 Vec2;

typedef struct Vec2i
{
    int x;
    int y;
} Vec2i;

Vec2i& operator*=(Vec2i& v, int i)
{
    v.x = v.x * i;
    v.y = v.y * i;
    return v;
}

Vec2i operator*(Vec2i v, int i)
{
    return v *= i;
}

Vec2i& operator*=(Vec2i& v, float i)
{
    v.x = (int)(v.x*i);
    v.y = (int)(v.y*i);
    return v;
}

Vec2i operator*(Vec2i v, float i)
{
    v *= i; 
    return v;
}

// Constants
inline constexpr Vec2 UP = { 0.0f, -1.0f };

inline constexpr int INTERNAL_RES_X = 600;
inline constexpr int INTERNAL_RES_Y = 600;
inline constexpr int INTERNAL_X = INTERNAL_RES_X;
inline constexpr int INTERNAL_Y = INTERNAL_RES_Y;
inline constexpr Vec2i INTERNAL_RES = { INTERNAL_RES_X, INTERNAL_RES_Y };

inline constexpr int DEFAULT_EXTERNAL_RENDER_RESOLUTION_X = INTERNAL_RES_X;
inline constexpr int DEFAULT_EXTERNAL_RENDER_RESOLUTION_Y = INTERNAL_RES_Y;
inline constexpr Vec2i DEFAULT_EXTERNAL_RENDER_RESOLUTION = { DEFAULT_EXTERNAL_RENDER_RESOLUTION_X, DEFAULT_EXTERNAL_RENDER_RESOLUTION_Y };


extern int EXTERNAL_RESOLUTION_X;
extern int EXTERNAL_RESOLUTION_Y;
extern Vec2i EXTERNAL_RES;