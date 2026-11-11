#include "common.hpp"
#include "camera.hpp"
#include "game.hpp"
#include "render_game.hpp"
#include "assets.hpp"


float CAMERA_MOVEMENT_SPEED = 100.0f;
int EXTERNAL_RESOLUTION_X = INTERNAL_RES_X;
int EXTERNAL_RESOLUTION_Y = INTERNAL_RES_Y;
Vec2i EXTERNAL_RES = { EXTERNAL_RESOLUTION_X, EXTERNAL_RESOLUTION_Y };

int main(void)
{
    const char* title = "MyLife";
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(EXTERNAL_RESOLUTION_X, EXTERNAL_RESOLUTION_Y, title);
    
    
    Player player = player::create("ian");
    
    lvl_t TEST_LEVEL = "test";
    level test_level;

    Game INSTANCE = 
    {
        .player = player,
        .current_level = test_level,
        .mr = render_game::render_setup(INTERNAL_RES, EXTERNAL_RES),
        .dt = 0.0f
    };
    // have to call to load the texture properly
    lvl::load(INSTANCE.current_level, TEST_LEVEL);
    while (!WindowShouldClose())
    {

        if(IsKeyPressed(KEY_ESCAPE)) break;
        game::run(INSTANCE);
    }
    CloseWindow();
    return 0;
}