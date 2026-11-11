#pragma once
#include "common.hpp"
#include "assets.hpp"
#include <array>
#include <string>

static constexpr unsigned char NUM_STATS = 7;
static constexpr unsigned char NUM_STATES = 6;
static constexpr unsigned char NUM_ALLOWABLE_STATES = 2;

inline std::string PLAYER_NAME = "";

typedef enum STAT
{
    HEALTH,
    ENERGY,
    HAPPINESS,
    MONEY,
    LOVE,
    CONFIDENCE,
    AROUSAL
} Stat;

typedef enum STATE
{
    NORAML,
    MOTIVATED,
    DEPRESSED,
    TIRED,
    SAD,
    HORNY
} State;

typedef float Stat_t;

static constexpr unsigned char STATE_A = 0;
static constexpr unsigned char STATE_B = 1;

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

typedef struct PLAYER
{
    std::string name;
    Texture2D portrait;
    Texture2D body_texture;
    std::array<State, NUM_ALLOWABLE_STATES> states;
    std::array<Stat_t, NUM_STATS> stats;
    unsigned char frame_count;
    Vec2 pos;
} Player;

namespace player
{
    constexpr float body_scalar = 0.17f;
    constexpr float portrait_scalar = 0.25f;
    Vec2i player_size = INTERNAL_RES*body_scalar;
    Vec2i portrait_size = INTERNAL_RES*portrait_scalar;
    inline Player create(const std::string& name)
    {
        Player p;
        p.name = name;
        p.states.fill(NORAML);
        p.stats.fill(100.0f);
        p.portrait = LoadTexture(PORTRAIT, name, portrait_size.x, portrait_size.y);
        p.body_texture = LoadTexture(BODY, name, player_size.x, player_size.y);
        p.pos = {.x = INTERNAL_RES_X/2.0f, .y = INTERNAL_RES_Y/2};
        return p;
    }

    inline void destroy(Player& p)
    {
        UnloadTexture(p.portrait);
        UnloadTexture(p.body_texture);
    }

    inline void set_name(Player& p, const std::string& name)
    {
        p.name = name;
    }

    inline unsigned char get_current_frame(const Player& p)
    {
        return p.frame_count;
    }

    inline State get_state_val(const Player& p, unsigned char slot)
    {
        return p.states[slot];
    }

    inline Stat_t get_stat_val(const Player& p, Stat stat)
    {
        return p.stats[stat];
    }

    inline void set_state_val(Player& p, unsigned char slot, State value)
    {
        if (slot > NUM_ALLOWABLE_STATES - 1) return;
        p.states[slot] = value;
    }

    inline void set_stat_val(Player& p, Stat stat, Stat_t value)
    {
        if (stat > NUM_STATS - 1) return;
        p.stats[stat] = value;
    }

    inline void copy(Player& dst, const Player& src)
    {
        dst = src; // struct copy handles every field
    }
}