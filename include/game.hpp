#pragma once
#include "common.hpp"
#include "camera.hpp"
#include "movement.hpp"
#include "player.hpp"
#include "render_game.hpp"
#include "level.hpp"


typedef struct GAME
{
    Player player;
    level current_level;
    MASTER_RENDER mr;
    float dt;
} Game;

namespace game 
{
    void run(Game& g) 
    {
        static float idle_timer = 0.0f;
        if(WSAD_DOWN) idle_timer = 0.0f;
        else idle_timer += g.dt;
        if(idle_timer > 1.0f) 
        {
            g.player.current_animation = IDLE;
            anim::sprite_sheet::animate(g.player.ssr, g.player.frame_state, IAN_IDLE, g.dt);
        }
        EXTERNAL_RES = {GetScreenWidth(), GetScreenHeight()};
        g.dt = GetFrameTime();
        g.player.pos = movement::move(g.player.pos, movement::move_input(), movement::speed, g.dt);
        render_game::render(g.mr, g.current_level, g.player);
    }
}

