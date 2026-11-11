// #pragma once
// #include "common.hpp"


// using uchar = unsigned char;

// typedef struct Vec2i {
//     int x; 
//     int y;
// } Vec2i;

// typedef enum ANIM_TYPES
// {
//     IDLE,
//     WALK,
//     RUN
// } anim_t;

// typedef struct ANIM_2D
// {
//     anim_t type;
//     union {

//         std::vector<Texture2D> tex_frames;
//         Texture2D sprite_sheet;
//     };
//     uchar frame_count;
//     uchar fd;
// } Anim2D;

// namespace anim
// {
//      void update(unsigned char& fd, uchar& frame_count)
//     {
//         fd += 1;
//         fd %= frame_count;
//     }
//     Texture2D& get_frame(uchar index, std::vector<Texture2D>& frames)
//     {
//         return frames[index];
//     }
//     void update(uchar fd, Texture2D& sheet, Vec2i size)
//     {
        
           
//     }
// }