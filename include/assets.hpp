#pragma once
#include "common.hpp"

#define TEXTURES_PATH "./resources/textures/"
#define PORTRAIT_PATH "./resources/textures/portraits/"
#define BODY_PATH "./resources/textures/bodies/"
#define LEVELS_PATH "./resources/textures/levels/"



inline const char* get_file_path_by_name(const char* file_path_define, std::string name, std::string file_ext)
{
    static std::string str = ((std::string)file_path_define+name+file_ext);
    return str.c_str();
}

inline Texture2D get_texture_by_name(const char* file_path_define, std::string name, std::string file_ext)
{
    return LoadTexture( ((std::string)file_path_define+name+file_ext).c_str() );
}

typedef enum ASSET
{
    BODY,
    PORTRAIT,
    LEVEL
} Asset_t;


static std::vector<std::string>  asset_t_ext = {"_body", "_portrait", "_level"};
static std::vector<std::string>  asset_t_path = {BODY_PATH, PORTRAIT_PATH, LEVELS_PATH};
inline const char* get_asset_by_name(Asset_t type, std::string name, std::string file_ext)
{
    return get_file_path_by_name(asset_t_path[type].c_str(), name+asset_t_ext[type], file_ext);
}
