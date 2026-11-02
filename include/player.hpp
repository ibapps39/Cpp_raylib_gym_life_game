#pragma once
#include "common.hpp"
#include "assets.hpp"
#include <string>

static constexpr unsigned char NUM_STATS = 7;
static constexpr unsigned char NUM_STATES = 6;
static constexpr unsigned char NUM_ALLOWABLE_STATES = 2;


std::string PLAYER_NAME = "";

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


// typedef struct PLAYER
// {
//     std::string name;
//     Texture2D portrait;
//     Texture2D body_texture;
//     std::array<State, NUM_ALLOWABLE_STATES> states;
//     std::array<Stat_t, NUM_STATS> stats;
//     unsigned char frame_count = 0;
// } Player;


class Player
{
private:
   
    std::string name;
    Texture2D portrait;
    Texture2D body_texture;
    std::array<State, NUM_ALLOWABLE_STATES> states;
    std::array<Stat_t, NUM_STATS> stats;
    unsigned char frame_count = 0;

public:
    Vec2 pos{0, 0};
    //std::vector<Texture2D> player_textures;

    Player(std::string name)

    {
        this->name = name;
        states.fill(NORAML);
        stats.fill(100.0f);
        portrait = LoadTexture(get_asset_by_name(PORTRAIT, name, ".png"));
        body_texture = LoadTexture(get_asset_by_name(BODY, name, ".png"));
    }

    void set_name(std::string name)
    {
        this->name = name;
    }
    // unsigned char animate()
    // {
    //     if(player_textures.size() <= 0) return 0;
    //     frame_count = (frame_count + 1) % player_textures.size();
    //     return frame_count;
    // }
    unsigned char get_current_frame()
    {
        return frame_count;
    }
    State get_state_val(State state)
    {
        return states[state];
    }
    Stat_t get_stat_val(Stat stat)
    {
        return stats[stat];
    }
    void set_state_val(unsigned char state, State state_v)
    {
        if(state > NUM_ALLOWABLE_STATES-1) return;
        states[state] = state_v;
    }
    void set_stat_val(Stat stat, Stat stat_val)
    {
        if(stat > NUM_STATS-1) return;
        stats[stat] = stat_val;
    }
    void copy(Player& dst, Player& p)
    {
        dst.name = p.name;
        dst.portrait = p.portrait;
        dst.body_texture = p.body_texture;
        dst.states = p.states;
        dst.stats = p.stats;
        dst.frame_count = p.frame_count;
    }
    Texture2D& get_portrait()
    {
        return portrait;
    }
    Texture2D& get_body_texture()
    {
        return body_texture;
    }
    ~Player()
    {
        UnloadTexture(portrait);
        UnloadTexture(body_texture);
    }
};