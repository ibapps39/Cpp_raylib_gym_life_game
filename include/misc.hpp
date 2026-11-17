#include <common.hpp>
#include <vector>


inline Texture2D ldtx(Asset_t ast, std::string name, int sx, int sy)
{
    assert( IsImageValid( LoadImage(get_path(SPRITE_SHEET, "ian", ".png")) ) == true );
    Image img = LoadImage(get_path(ast, name, ".png"));
    ImageResize(&img, sx, sy);
    Texture2D t = LoadTextureFromImage(img);
    UnloadImage(img);
    return t;
}


void draw_track_photo(Texture2D t=ldtx(SPRITE_SHEET, "ian", INTERNAL_RES_X, INTERNAL_RES_Y))
{
    const Vector2 mv = GetMousePosition();
    static Vec2 pt = {0};
    std::string pt_str = std::to_string(pt.x) + ", " + std::to_string(pt.y);
    static Vec2 pt2 = {0};
    std::string pt2_str = std::to_string(pt2.x) + ", " + std::to_string(pt2.y);
    static unsigned char click = 0;
    static std::vector<Vec2> points;
    static std::vector<std::string> points_s;
    static int click_n = 0;
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        click_n++;
        if(click == 0)
        {
            pt = mv;
            pt_str = std::to_string(pt.x) + ", " + std::to_string(pt.y);
            click = 1;
        }
        else
        {
            pt2 = mv;
            pt2_str = std::to_string(pt2.x) + ", " + std::to_string(pt2.y);
            click = 0;
        }
    }
    if(click_n % 2 == 0)
    {
        points.push_back(pt);
        points.push_back(pt2);
        points_s.push_back(pt_str);
        points_s.push_back(pt2_str);
    }
    if(IsKeyDown(KEY_U) && points.size() > 0)
    {
        click_n--;
        points.pop_back();
        points.pop_back();
        points_s.pop_back();
        points_s.pop_back();
    }
    BeginDrawing();
    ClearBackground(DARKGRAY);
    DrawTexture(t, 0, 0, WHITE);

    DrawLine(0, (int)mv.y, GetScreenWidth(), (int)mv.y, RED);
    DrawLine((int)mv.x, 0, (int)mv.x, GetScreenHeight(), RED);
    float tx = mv.x > GetScreenWidth()/2 ? mv.x-100 : mv.x+10;
    Vec2 txt_pos = {
        tx, 
        mv.y+10
    };
    DrawText(TextFormat("x:%d y:%d", (int)mv.x, (int)mv.y),
             (int)txt_pos.x, (int)txt_pos.y, 20, YELLOW);
    DrawCircle((int)pt.x, (int)pt.y, 10, RED);
    DrawCircle((int)pt2.x, (int)pt2.y, 10, GREEN);
    for(auto s : points_s)
    {
        int y = (GetScreenHeight()*0.2f)+20*i;
        DrawText(points_s[i].c_str(), 10, y, 20, WHITE);
    }
    EndDrawing();
}