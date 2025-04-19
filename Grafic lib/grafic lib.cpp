#include "glfwbgi.h"
using namespace Graph;

struct s_star
{
    Point coord;

    int radius;
    int ray_height;
    unsigned int color;
};

void DrawStar2(const s_star & star)
{
    FillEllipseSector(star.coord.x, star.coord.y, star.radius, star.radius, 0, 360, star.color);
    for (int angle = 0; angle < 360; angle += 40)
    {
        FillEllipseSector(
            star.coord.x,
            star.coord.y,
            star.radius + star.ray_height,
            star.radius + star.ray_height,
            angle, angle + 10,
            star.color);
    }
}

void GraphWindow ()
{
    InitGraph(1200, 1000, "");
    ClearDevice(Color::Black);
    s_star stars[8];
    s_star TheSun = { 300, 300, 50, 30, Color::Yellow };
    stars[0] = TheSun;

    stars[1] = TheSun;
    stars[1].coord.y += 320;

    stars[2] = { 600, 300, 150, 10, Color::DarkRed };
    stars[3] = { 900, 700, 60, 100, Color::Aquamarine };
    stars[4] = stars[3];

    stars[4].coord.x = 0;
    stars[4].coord.y = 0;
    stars[5].color = Color::NavajoWhite;
    stars[5].radius = 10;
    stars[6].radius = 333;
    stars[7] = stars[2];
    
    for (int i = 0; i < 9; i++)
    {
        DrawStar2(stars[i]);
    }

    SwapBuffers();
    ReadKey();
    CloseGraph();

}
int main()
{
    GraphWindow();


    return 0;
}
