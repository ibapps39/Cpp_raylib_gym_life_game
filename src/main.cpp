#include "common.hpp"
#include "camera.hpp"
#include "game.hpp"
#include "render_game.hpp"
#include "assets.hpp"


float CAMERA_MOVEMENT_SPEED = 100.0f;


int main(void)
{
    int window_w = 600;
    int window_h = 600;
    EXTERNAL_RENDER_RESOLUTION_X = window_w;
    EXTERNAL_RENDER_RESOLUTION_Y = window_h;
    Vec2 res = (Vec2){1.0f*window_w, 1.0f*window_h};
    const char* title = "raylib [core] example - camera 3d";
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(window_w, window_h, title);
    

    level_t test_level;
    test_level.level_info.level_name = "test";
    test_level.level_info.file_path = get_asset_by_name(LEVEL, test_level.level_info.level_name, ".png");
    
    Player player = Player("ian");
    PlayerCam p_cam;
    
    Game g = 
    {
        .player = player,
        .current_level = test_level,
        .dt = 0.0f,
        .mr = render_game::render_setup(res, res)
    };
    level::load_level(test_level);
    level::load_level(g.current_level, test_level);

    while (!WindowShouldClose())
    {
        // bool mov_key_down = IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D);
        //  g.dt = GetFrameTime();
         if(IsKeyPressed(KEY_ESCAPE)) break;
        render_game::render(g.mr, g.current_level, g.player);
    }
    CloseWindow();
    return 0;
}