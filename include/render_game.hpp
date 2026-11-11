#pragma once

#include "common.hpp"
#include "player.hpp"
#include "level.hpp"
#include "assets.hpp"
#include "interface.hpp"

typedef struct MASTER_RENDER
{
    Rectangle src;
    Rectangle dst;
    RenderTexture2D master_texture;
} master_render;

namespace render_game
{
    void draw(Player &p) {
        static signed char flip = 1;
        //DrawTexture(p.body_texture, p.pos.x, p.pos.y, WHITE);
        if (IsKeyDown(KEY_A)) flip = -1.0f;
        if (IsKeyDown(KEY_D)) flip = 1.0f;
        Rectangle src = {};
        src.x = 0.0f;
        src.y = 0.0f;
        src.width = flip*p.body_texture.width;
        src.height = p.body_texture.height;
        Rectangle dst = {};
        dst.x = p.pos.x;
        dst.y = p.pos.y;
        dst.width = p.body_texture.width;
        dst.height = p.body_texture.height;
        DrawTexturePro(p.body_texture, src, dst, {0.0f,0.0f}, 0, WHITE);
    }
    void draw(Level& l)
    {
        DrawTexture(l.tex, 0,0, WHITE);
    }
    master_render render_setup(const Vec2i internal_res, const Vec2i output_res=EXTERNAL_RES)
    {
        master_render mr;
        mr.master_texture = LoadRenderTexture(internal_res.x, internal_res.y);
        mr.src = {
            .x = 0,
            .y = 0,
            .width = internal_res.x*1.0f,
            .height = -1.0f*internal_res.y
        };
        mr.dst = {
            .x = 0,
            .y = 0,
            .width = 1.0f*output_res.x,
            .height = 1.0f*output_res.y};
        return mr;
    }
    void update(master_render &mr) 
    {
        EXTERNAL_RES = {GetScreenWidth(), GetScreenHeight()};
        mr.dst.width = EXTERNAL_RES.x;
        mr.dst.height = EXTERNAL_RES.y;
    }
    void render(master_render &mr, level& l, Player& player)
    {
        if(IsWindowResized()) update(mr);
        static bool draw_interface = false;
        if(IsKeyPressed(KEY_I)) draw_interface = !draw_interface;
        // assemble/compose texture
        BeginTextureMode(mr.master_texture);
            draw(l);
            draw(player);
            if(draw_interface) interface::draw(player);
        EndTextureMode();

        // draw the renderingtexture2d
        BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(mr.master_texture.texture, mr.src, mr.dst, {0, 0}, 0, WHITE);
        EndDrawing();
    }
}