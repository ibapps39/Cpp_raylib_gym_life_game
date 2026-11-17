#pragma once

#include "common.hpp"
#include "player.hpp"
#include "level.hpp"
#include "assets.hpp"
#include "interface.hpp"
#include "anim.hpp"

typedef struct MASTER_RENDER
{
    Rectangle src;
    Rectangle dst;
    RenderTexture2D master_texture;
} master_render;

namespace render_game
{
    inline signed char flip()
    {
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_S))
            return -1;
        return 1;
    }
    inline signed char flipf()
    {
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_S))
            return -1.0f;
        return 1.0f;
    }

    void draw(Player &p)
    {
        static signed char flip = flipf();
        // DrawTexture(p.body_texture, p.pos.x, p.pos.y, WHITE);
        Rectangle src = {};
        src.x = 0.0f;
        src.y = 0.0f;
        src.width = flip * p.body_texture.width;
        src.height = p.body_texture.height;
        Rectangle dst = {};
        dst.x = p.pos.x;
        dst.y = p.pos.y;
        dst.width = p.width;
        dst.height = p.height;
        DrawTexturePro(p.body_texture, src, dst, {0.0f, 0.0f}, 0, WHITE);
    }
    void draw(Level &l)
    {
        DrawTexture(l.tex, 0, 0, WHITE);
    }
    // uses sprite sheet rectangle, ssr
    void draw(Texture2D &sprite_sheet, Player &p)
    {
        Rectangle dst = {};
        dst.x = p.pos.x;
        dst.y = p.pos.y;
        dst.width = p.width;
        dst.height = p.height;

        DrawTexturePro(sprite_sheet, p.ssr, dst, {0, 0}, 0, WHITE);
    }
    master_render render_setup(const Vec2i internal_res, const Vec2i output_res = EXTERNAL_RES)
    {
        master_render mr;
        mr.master_texture = LoadRenderTexture(internal_res.x, internal_res.y);
        mr.src = {
            .x = 0,
            .y = 0,
            .width = internal_res.x * 1.0f,
            .height = -1.0f * internal_res.y};
        mr.dst = {
            .x = 0,
            .y = 0,
            .width = 1.0f * output_res.x,
            .height = 1.0f * output_res.y};
        return mr;
    }
    void update(master_render &mr)
    {
        EXTERNAL_RES = {GetScreenWidth(), GetScreenHeight()};
        mr.dst.width = EXTERNAL_RES.x;
        mr.dst.height = EXTERNAL_RES.y;
    }
    void render(master_render &mr, level &l, Player &player)
    {
        if (IsWindowResized())
            update(mr);
        static bool draw_interface = false;
        if (IsKeyPressed(KEY_I))
            draw_interface = !draw_interface;
        // assemble/compose texture
        BeginTextureMode(mr.master_texture);
        draw(l);
        //draw(player);
        draw(player.sprite_sheet, player);
        DrawText(TextFormat("ssr info: x-%.2f\n y-%.2f\n w-%.2f\n h-%.2f\n", player.ssr.x, player.ssr.y, player.ssr.width, player.ssr.height), 10, mr.dst.height/2, 30, RED);
        if (draw_interface)
            interface::draw(player);
        EndTextureMode();

        // draw the renderingtexture2d
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(mr.master_texture.texture, mr.src, mr.dst, {0, 0}, 0, WHITE);
        EndDrawing();
    }
}