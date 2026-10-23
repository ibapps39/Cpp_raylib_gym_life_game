#pragma once
#include "common.hpp"
#include <string>

#define NUM_STATS 7
#define NUM_STATES 6
#define NUM_ALLOWABLE_STATES 2

char* PLAYER_NAME = "";


typedef enum STATS
{
    HEALTH,
    ENERGY,
    HAPPINESS,
    MONEY,
    LOVE,
    CONFIDENCE,
    AROUSAL
} Stats;

typedef enum STATE_T
{
    NORAML,
    MOTIVATED,
    DEPRESSED,
    TIRED,
    SAD,
    HORNY
} State_t;

typedef float Stat_t;

class Player
{
    private:
        std::string player_name;
        State_t states[NUM_ALLOWABLE_STATES];
        Stat_t stats[NUM_STATS];
        Vec2 pos;
        Texture2D player_texture;
    public:
        Player()
        {
            pos = (Vec2){0,0};
            player_name = "Ian";
            states[0] = NORAML;
            states[1] = MOTIVATED;
            stats[HEALTH] = 100;
            stats[ENERGY] = 100;
            stats[HAPPINESS] = 80;
            stats[MONEY] = 30;
            stats[LOVE] = 0;
            stats[CONFIDENCE] = 50;
            stats[AROUSAL] = 0;
        }
    void set_name(std::string name)
    {
        player_name = name;
    }
    
    
};