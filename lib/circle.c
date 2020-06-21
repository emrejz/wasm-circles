#include <stdlib.h>
#include <time.h>
#define total 500
struct Circle
{
    int x;
    int y;
    int r;
    int cr;
    int cg;
    int cb;
};
struct AnimatedCircle
{
    int vx;
    int vy;
    int dx;
    int dy;
};

struct Circle circles[total];
struct AnimatedCircle animatedCircles[total];
int getRand(int limit)
{
    return rand() % limit;
};

void generateCircles()
{
    srand(time(NULL));
    for (int i = 0; i < total; i++)
    {
        int radius = getRand(50);
        circles[i].x = getRand(700) + radius;
        circles[i].y = getRand(700) + radius;
        circles[i].r = radius;
        circles[i].cr = getRand(255);
        circles[i].cg = getRand(255);
        circles[i].cb = getRand(255);
        animatedCircles[i].vx = getRand(10);
        animatedCircles[i].vy = getRand(10);
        animatedCircles[i].dx = getRand(2) == 0 ? -1 : 1;
        animatedCircles[i].dy = getRand(2) == 0 ? -1 : 1;
    }
};
struct Circle *getCircles(canvasWei, canvasHei)
{

    for (int i = 0; i < total; i++)
    {
        if (animatedCircles[i].dx == 1)
        {
            if (circles[i].x + animatedCircles[i].vx + circles[i].r >= canvasWei)
            {
                animatedCircles[i].dx = -1;
            }
        }
        if (animatedCircles[i].dx == -1)
        {
            if (circles[i].x - animatedCircles[i].vx - circles[i].r <= 0)
            {
                animatedCircles[i].dx = 1;
            }
        }
        if (animatedCircles[i].dy == 1)
        {
            if (circles[i].y + animatedCircles[i].vy + circles[i].r >= canvasHei)
            {
                animatedCircles[i].dy = -1;
            }
        }
        if (animatedCircles[i].dy == -1)
        {
            if (circles[i].y - animatedCircles[i].vy - circles[i].r <= 0)
            {
                animatedCircles[i].dy = 1;
            }
        }
        circles[i].x = circles[i].x + animatedCircles[i].vx * animatedCircles[i].dx;
        circles[i].y = circles[i].y + animatedCircles[i].vy * animatedCircles[i].dy;
    }
    return circles;
};
