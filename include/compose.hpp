#pragma once 
#include "common.hpp"
#include "player.hpp"

#include "level.hpp"


void draw_level(const Level level)
{
    DrawTexture(level.background, 0, 0, WHITE);
}
void draw_players(std::vector<Player> players)
{
    for(Player player : players)
    {
       DrawTexture(player.player_textures.at(player.animate()), player.pos.x, player.pos.y, WHITE);
    }
}
void draw_interface(const Texture2D portrait, const Player player, const Vec2 internal_res)
{
    // 0.833, 5/6, 500/600 
    DrawTexture(portrait, 0, (int)internal_res.y*(0.833f), WHITE);
    // draw text
    //DrawText(T)

}

void compose()
{

}