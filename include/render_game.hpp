#pragma once

#include "common.hpp"
#include "composer.hpp"

static constexpr int DEFAULT_INTERNAL_RENDER_RESOLUTION_X = 600;
static constexpr int DEFAULT_INTERNAL_RENDER_RESOLUTION_Y = 600;
static constexpr Vec2 DEFAULT_INTERNAL_RENDER_RESOLUTION = (Vec2){DEFAULT_INTERNAL_RENDER_RESOLUTION_X, DEFAULT_INTERNAL_RENDER_RESOLUTION_Y};

static constexpr int DEFAULT_EXTERNAL_RENDER_RESOLUTION_X = DEFAULT_INTERNAL_RENDER_RESOLUTION_X;
static constexpr int DEFAULT_EXTERNAL_RENDER_RESOLUTION_Y = DEFAULT_INTERNAL_RENDER_RESOLUTION_Y;
static constexpr Vec2 DEFAULT_EXTERNAL_RENDER_RESOLUTION = (Vec2){DEFAULT_EXTERNAL_RENDER_RESOLUTION_X, DEFAULT_EXTERNAL_RENDER_RESOLUTION_Y};

RenderTexture2D render_setup(const float render_w, const float render_h)
{
    RenderTexture2D render_tx = LoadRenderTexture(render_w, render_h);
    return render_tx;
}

void compose_master_render(const RenderTexture2D master_texture, Composer compose)
{
    BeginTextureMode(master_texture);
    ClearBackground(BLACK);
    
    EndTextureMode();
}

// renders whole game
void render_master_texture(const float render_w, const float render_h, const RenderTexture2D master_texture)
{
    const Rectangle src = {.x = 0, .y = 0, .width = master_texture.texture.width, .height = -(master_texture.texture.height)};
    const Rectangle dst = {.x = 0, .y = 0, .width = render_w, .height = render_h};
    DrawTexturePro(master_texture.texture, src, dst, (Vec2){0,0}, 0.0f, WHITE);
}

class GameRender
{
    private:
        RenderTexture2D master_render;
        const Vec2 internal_res = DEFAULT_INTERNAL_RENDER_RESOLUTION;
        Vec2 output_res = DEFAULT_EXTERNAL_RENDER_RESOLUTION;
    
        void change_res(const Vec2 new_res)
        {
            output_res = new_res;
        }
        void render()
        {
            render_master_texture(output_res.x, output_res.y, master_render);
        }
    public:
        GameRender() // assumes internal res!
        {
            output_res.x = internal_res.x;
            output_res.y = internal_res.y;
            master_render = render_setup(output_res.x, output_res.y);
        }
        GameRender(const float render_w, const float render_h)
        {
            output_res.x = render_w;
            output_res.y = render_h;
            master_render = render_setup(output_res.x, output_res.y);
        }
        ~GameRender()
        {
            UnloadRenderTexture(master_render);
        }
}