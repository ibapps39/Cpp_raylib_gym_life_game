#pragma once
#include "common.hpp"
#include "assets.hpp"
#include <map>
#include <array>
#include <vector>
typedef enum ANIM_TYPES
{
    IDLE,
    WALK,
    RUN,
    BACK
} anim_t;
static const unsigned char n_anim = 4;

inline anim_t determine_animation()
{

        if(SHIFT_DOWN && WSAD_DOWN)
        {
            return RUN;
        }
        if(WSAD_DOWN)
        {
            return WALK;
        }
        return IDLE;
}
typedef struct FRAME_VECTOR
{
    float x_start;
    float x_end;
} fv;
typedef struct AnimSpriteSheet
{
    anim_t type;
    unsigned char n_frames;
    // x_start, x_end
    std::vector<fv> frames;
    float frame_timing;
    float row;
} AnimSpriteSheet;

typedef struct AnimState
{
    int   frame = 0;
    float timer = 0.0f;
} AnimState;

AnimSpriteSheet IAN_IDLE
{
    .type = IDLE,
    .n_frames = 8,
    .frames = {
        {21,47},
        {94,120},
        {147,168},
        {190,215},
        {317,342},
        {387,413},
        {433,456},
        {488,511}
    },
    .frame_timing = 0.12f,
    .row = 11
};
AnimSpriteSheet IAN_WALK
{
    .type = WALK,
    .n_frames = 8,
    .frames = {
        {21,47},
        {94,120},
        {147,168},
        {190,215},
        {317,342},
        {387,413},
        {433,456},
        {488,511}
    },
    .frame_timing = 0.12f,
    .row = 31
};
AnimSpriteSheet IAN_RUN 
{
    .type = RUN,
    .n_frames = 8,
    .frames = {
        {21,47},
        {94,120},
        {147,168},
        {190,215},
        {317,342},
        {387,413},
        {433,456},
        {488,511}
    },
    .frame_timing = 0.12f,
    .row = 51
};
AnimSpriteSheet IAN_RUN_BACK
{
    .type = RUN,
    .n_frames = 8,
    .frames = {
        {21,47},
        {94,120},
        {147,168},
        {190,215},
        {317,342},
        {387,413},
        {433,456},
        {488,511}
    },
    .frame_timing = 0.12f,
    .row = 11
};
typedef enum CHARACTERS
{
    IAN
} ppl;
constexpr unsigned char people_count = 1;
std::array<AnimSpriteSheet, n_anim> ian_animations_array = {IAN_IDLE, IAN_WALK, IAN_RUN, IAN_RUN_BACK};
std::array<std::array<AnimSpriteSheet, n_anim>, people_count> peeps_sheets = {ian_animations_array};
AnimSpriteSheet& get_person_anisheet(ppl person, anim_t type)
{
    return peeps_sheets[person][type];
}
namespace anim
{
    namespace sprite_sheet
    {
        Texture2D LoadTexture(const std::string name)
        {
            return LoadTexture(SPRITE_SHEET, name, INTERNAL_RES_X, INTERNAL_RES_Y);
        }
        // this is what moves the ssr
        void animate(Rectangle& r, AnimState& as, const AnimSpriteSheet& s, const float dt)
        {
            const float ft = s.frame_timing;
            as.timer+=dt;
            if(as.timer >= ft)
            {
                as.timer -= s.frame_timing;
                as.frame = (as.frame+1)%s.n_frames;
            }
            const fv frame = s.frames[as.frame];
            r.width = frame.x_end-frame.x_start;
            r.x = frame.x_start;
            r.y = s.row;
        }
    }
}