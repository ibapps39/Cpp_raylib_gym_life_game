#include "common.hpp"
#include "camera.hpp"
#include "game.hpp"
#include "render_game.hpp"


float CAMERA_MOVEMENT_SPEED = 100.0f;

int main(void)
{
    int window_w = 600;
    int window_h = 600;
    const char* title = "raylib [core] example - camera 3d";
    InitWindow(window_w, window_h, title);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    Game G;
    //RenderTexture2D GameRenderTexture = render_setup(window_w, window_h);
    while (!WindowShouldClose())
    {
        bool mov_key_down = IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D);
        DT = GetFrameTime();
        

    }
    CloseWindow();
    return 0;
}