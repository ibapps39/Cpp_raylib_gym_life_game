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
        g.player.dir = movement::move_input();
        g.player.pos = movement::move(g.player.pos, g.player.dir, movement::speed, g.dt);
        g.player.current_animation = determine_animation();
        
        AnimSpriteSheet& sprite_sheet =  g.player.dir.y >= 0 ? get_person_anisheet(
            IAN, g.player.current_animation) : get_person_anisheet(
            IAN, BACK);
        
        anim::sprite_sheet::animate(g.player.ssr, g.player.frame_state, sprite_sheet, g.dt);
        render_game::update_ssr(g.player.ssr);

        render_game::render(g.mr, g.current_level, g.player);
    }
}