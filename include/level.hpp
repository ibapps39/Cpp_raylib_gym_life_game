#pragma once
#include "common.hpp"
#include <map>
typedef struct Level_type
{
    std::string level_name;
    Texture2D background;
} Level;

extern std::map<std::string, Level> Levels;

Level get_level(std::string level_name, std::map<std::string, Level> levels = Levels)
{
    return levels.at(level_name);
}
Texture2D get_level_background(std::string level_name, std::map<std::string, Level> levels)
{
    return levels.at(level_name).background;
}