#pragma once
#include "common.hpp"
#include <map>

using lvl_t = std::string;

typedef struct Level 
{
    lvl_t name;
    Texture2D tex;
} level;

namespace lvl
{
    void load(level& dst, lvl_t src_lvl_name)
    {
        dst.name = src_lvl_name;
        dst.tex = LoadTexture(LEVEL, src_lvl_name, INTERNAL_RES_X, INTERNAL_RES_Y);
    }
    void unload(level& l)
    {
        UnloadTexture(l.tex);
    }
}
