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
        EXTERNAL_RES = {GetScreenWidth(), GetScreenHeight()};
        g.dt = GetFrameTime();
        g.player.pos = movement::move(g.player.pos, movement::move_input(), movement::speed, g.dt);
        render_game::render(g.mr, g.current_level, g.player);
    }
}

