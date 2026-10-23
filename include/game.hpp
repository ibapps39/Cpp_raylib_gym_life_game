#pragma once
#include "common.hpp"
#include "camera.hpp"
#include "movement.hpp"
#include "player.hpp"
#include "render_game.hpp"
#include <map>



class Game
{
private:
    Texture2D portrait;
    Texture2D map;
    char *player_name;
    Camera2D cam;
    Vec2 last_spawned_pt;
    PlayerCam p_cam;
    
public:
    Player player;
    Game()
    {
        // Player player = new Player; // maybe in the future
        player = Player();
        p_cam = PlayerCam((Vec2){0,0});
    }
    Game(char *name)
    {
        // Player player = new Player; // maybe in the future
        player = Player();
        p_cam = PlayerCam((Vec2){0,0});
        
    }

}