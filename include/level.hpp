#pragma once
#include "common.hpp"
#include <map>

typedef struct LEVEL_INFO
{
    std::string level_name;
    std::string file_path;
} level_i;

typedef struct LEVEL
{
    level_i level_info;
    Texture2D background;
} level_t;

using lvl = level_t;

namespace level
{

    void load_level(lvl &dst)
    {
        Image i = LoadImage(dst.level_info.file_path.c_str());
        ImageResize(&i, INTERNAL_RENDER_RESOLUTION_X, INTERNAL_RENDER_RESOLUTION_Y);
        Texture2D t = LoadTextureFromImage(i);
        dst.background = t;
        UnloadImage(i);
    }
    void load_level(lvl &dst, lvl &src)
    {
        dst = src;
    }
    void unload_level(lvl& l)
    {
        UnloadTexture(l.background);
    }
}