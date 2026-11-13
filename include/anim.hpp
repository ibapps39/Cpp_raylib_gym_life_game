#pragma once
#include "common.hpp"
#include "assets.hpp"

typedef enum ANIM_TYPES
{
    IDLE,
    WALK,
    RUN
} anim_t;

namespace anim
{
namespace sprite_sheet
{
    Texture2D LoadTexture(const std::string name)
    {
        return LoadTexture(SPRITE_SHEET, name, INTERNAL_RES_X, INTERNAL_RES_Y);
    }
}
}