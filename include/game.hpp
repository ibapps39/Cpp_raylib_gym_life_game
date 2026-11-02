#pragma once
#include "common.hpp"
#include "camera.hpp"
#include "movement.hpp"
#include "player.hpp"
#include "render_game.hpp"
#include "level.hpp"
#include <map>


typedef struct GAME
{
    Player player;
    level_t current_level;
    MASTER_RENDER mr;
    float dt;
} Game;


