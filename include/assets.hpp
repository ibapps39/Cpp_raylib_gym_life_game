#pragma once
#include "common.hpp"


#include <string>
#include <array>

#define TEXTURES_PATH "./resources/textures/"
#define PORTRAIT_PATH "./resources/textures/portraits/"
#define BODY_PATH "./resources/textures/bodies/"
#define LEVELS_PATH "./resources/textures/levels/"
#define SPRITE_SHEET_PATH "./resources/textures/sprite_sheets/"

typedef enum ASSET
{
    BODY,
    PORTRAIT,
    LEVEL,
    SPRITE_SHEET
} Asset_t;


static std::array<std::string, 4> asset_t_ext = {"_body", "_portrait", "_level", "_sprite_sheet"};
static std::array<const char *, 4> asset_t_path = {BODY_PATH, PORTRAIT_PATH, LEVELS_PATH, SPRITE_SHEET_PATH};

inline std::string path_result;

inline const char *get_file_path_by_name(const char *file_path_define, const std::string name, const std::string file_ext)
{
    path_result = file_path_define + name + file_ext;
    return path_result.c_str();
}

inline const char *get_path(Asset_t type, std::string name, std::string file_ext)
{
    return get_file_path_by_name(asset_t_path[type], name + asset_t_ext[type], file_ext);
}

inline Texture2D LoadTexture(Asset_t ast, std::string name, int sx, int sy)
{
    Image img = LoadImage(get_path(ast, name, ".png"));
    ImageResize(&img, sx, sy);
    Texture2D t = LoadTextureFromImage(img);
    UnloadImage(img);
    return t;
}

