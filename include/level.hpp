#pragma once
#include "common.hpp"
#include <map>
typedef struct Level_type
{
    std::string level_name;
    Texture2D background;
} Level;

std::map<std::string, Level> Levels;

Level load_level(std::string level_name, std::unique_ptr<std::map<std::string, Level>> levels)
{
    return levels->at(level_name);
}