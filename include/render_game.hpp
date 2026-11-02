#pragma once

#include "common.hpp"
#include "player.hpp"
#include "level.hpp"
#include "assets.hpp"

typedef struct MASTER_RENDER
{
    Rectangle src;
    Rectangle dst;
    RenderTexture2D master_texture;
} master_render;

namespace render_game
{
    void draw(Player &p) {
        DrawTexture(p.get_body_texture(), p.pos.x, p.pos.y, WHITE);
    }

    void draw(level_t &l) {
        DrawTexture(l.background, 0, 0, WHITE);
    }
    // master_render.master_texture = render_setup(internal_res.x, internal_res.y);
    master_render render_setup(const Vec2 internal_res, const Vec2 output_res)
    {
        master_render mr;
        mr.master_texture = LoadRenderTexture(internal_res.x, internal_res.y);
        mr.src = {
            .x = 0,
            .y = 0,
            .width = internal_res.x,
            .height = -internal_res.y};
        mr.dst = {
            .x = 0,
            .y = 0,
            .width = output_res.x,
            .height = output_res.y};
        return mr;
    }

inline void render_update(master_render &mr)
{
    EXTERNAL_RENDER_RESOLUTION_X = GetScreenWidth();
    EXTERNAL_RENDER_RESOLUTION_Y = GetScreenHeight();

    float scale = fminf(
        (float)GetScreenWidth()  / INTERNAL_RENDER_RESOLUTION.x,
        (float)GetScreenHeight() / INTERNAL_RENDER_RESOLUTION.y);

        // difference in 
    float dw = INTERNAL_RENDER_RESOLUTION.x * scale;
    float dh = INTERNAL_RENDER_RESOLUTION.y * scale;

    mr.dst = {
        (GetScreenWidth()  - dw) * 0.5f,
        (GetScreenHeight() - dh) * 0.5f,
        dw, 
        dh 
    };
}

    void render(master_render &mr, level_t &loaded_level, Player& player)
    {
        if(IsWindowResized()) 
        {
            render_update(mr);
        }
        // assemble/compose texture
        BeginTextureMode(mr.master_texture);
            draw(loaded_level);
            draw(player);
        EndTextureMode();

        // draw the renderingtexture2d
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(mr.master_texture.texture, mr.src, mr.dst, {0, 0}, 0, WHITE);
        EndDrawing();
    }
}