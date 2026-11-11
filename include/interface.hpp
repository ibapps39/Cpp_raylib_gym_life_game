#pragma once

#include "common.hpp"
#include "player.hpp"

// maybe using another rendertexture2d?
namespace interface
{
    using font_size = int;
    using fz = font_size;
    using icon = Texture2D;

    constexpr int height = INTERNAL_RES_Y / 4;
    constexpr int top = INTERNAL_RES_Y - height;
    constexpr int bottom = INTERNAL_RES_Y;
    constexpr int width = INTERNAL_RES_X;
    constexpr int midx = width / 2;
    constexpr int midy = height / 2;
    constexpr Vec2i mid = {midx, midy};
    constexpr int padding = 10; // or 1/15 of height

    const struct INTERFACE_WORKSPACE
    {
        const int x_min = padding; // 10
        const int x_max = INTERNAL_RES_X - padding; // 590
        const int y_min = top + padding; //  460
        const int y_max = bottom - padding; // 590
        const int h = y_max - y_min; // 130
        const int w = x_max - x_min; // 580
    } workspace;
    
    const Vec2i portrait_pos = {.x = workspace.x_min, .y = workspace.y_min};
    const int portrait_h = workspace.h*.80;
    const int portrait_w = portrait_h;
    const Vec2i portrait_size = {portrait_w, portrait_h};

    const fz name_size = portrait_size.x/4;
    // const Vec2 name_pos = {.x = portrait_pos.x + portrait_size.x + padding, .y = portrait_pos.y};

    // constexpr const char *icons_interface_path = "resources/icons/interface.png";
    // const icon health;
    // const icon wealth;
    // const icon energy;
    // const Vec2i icon_placement = {.x = portrait_pos.x + 10, .y = portrait_pos.y};

    // Level name

    // uses drawtexturepro since it's already loaded and resized.
    void draw(const Player& active_player)
    {
        const static Rectangle rb = {.x = 0, .y = top, .width = width, .height = height};
        DrawRectangleLines(rb.x, rb.y, rb.width, rb.height, BLUE);
        //dim of the original tex
        Rectangle rp_src = {
            .x = 1.0f*portrait_pos.x, 
            .y = 1.0f*portrait_pos.y, 
            .width = 1.0f*active_player.portrait.width, 
            .height = 1.0f*active_player.portrait.height
        };
        // scaled down
        Rectangle rp_dst = {
            .x = 1.0f*portrait_pos.x, 
            .y = 1.0f*portrait_pos.y, 
            .width = 1.0f*portrait_w, 
            .height = 1.0f*portrait_h
        };
        DrawTexturePro(active_player.portrait, rp_src, rp_dst, {0,0}, 0, WHITE);
        DrawText(active_player.name.c_str(), portrait_pos.x, portrait_pos.y+portrait_h, name_size, WHITE);
    }
    
    void update();

}