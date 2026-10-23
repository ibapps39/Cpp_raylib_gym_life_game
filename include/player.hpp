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

static constexpr Stat_t MAX_PLAYER_HEALTH = 100;
static constexpr Stat_t MAX_PLAYER_ENERGY = 100;
static constexpr Stat_t MAX_PLAYER_HAPPINESS = 100;
static constexpr Stat_t MAX_PLAYER_MONEY = 100;
static constexpr Stat_t MAX_PLAYER_LOVE = 100;
static constexpr Stat_t MAX_PLAYER_CONFIDENCE = 100;
static constexpr Stat_t MAX_PLAYER_AROUSAL = 100;

static constexpr Stat_t MIN_PLAYER_HEALTH = 0;
static constexpr Stat_t MIN_PLAYER_ENERGY = 0;
static constexpr Stat_t MIN_PLAYER_HAPPINESS = 0;
static constexpr Stat_t MIN_PLAYER_MONEY = 0;
static constexpr Stat_t MIN_PLAYER_LOVE = 0;
static constexpr Stat_t MIN_PLAYER_CONFIDENCE = 0;
static constexpr Stat_t MIN_PLAYER_AROUSAL = 0;


static Texture2D DEFAULT_PORTRAIT;

class Player
{
    private:
        std::string player_name;
        State_t states[NUM_ALLOWABLE_STATES];
        Stat_t stats[NUM_STATS];
        Texture2D player_portrait;
        unsigned char frame_count;
    public:
        Vec2 pos;
        std::vector<Texture2D> player_textures;
        Player()
        {
            pos = (Vec2){0,0};
            player_name = "Ian";
            states[0] = NORAML;
            states[1] = MOTIVATED;
            stats[HEALTH] = MAX_PLAYER_HEALTH;
            stats[ENERGY] = MAX_PLAYER_ENERGY;
            stats[HAPPINESS] = MAX_PLAYER_HAPPINESS;
            stats[MONEY] = MAX_PLAYER_MONEY;
            stats[LOVE] = MAX_PLAYER_LOVE;
            stats[CONFIDENCE] = MAX_PLAYER_CONFIDENCE;
            stats[AROUSAL] = MAX_PLAYER_AROUSAL;
            frame_count = 0;
            player_portrait = DEFAULT_PORTRAIT;
        }
    void set_name(std::string name)
    {
        player_name = name;
    }
    unsigned char animate()
    {
        frame_count = (frame_count + 1) % player_textures.size();
        return frame_count;
    }
};