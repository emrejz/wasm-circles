#include <stdlib.h>
#include <time.h>

struct Circle
{
    int x;
    int y;
    int r;
    int cr;
    int cg;
    int cb;
};
struct Circle *circle;
int getRand(int limit)
{
    return rand() % limit;
};
struct Circle *getCircle(itr)
{
    srand(time(NULL));
    for (int i = 0; i < itr; i++)
    {
        int radius = getRand(50);
        circle[i].x = getRand(1000) + radius;
        circle[i].y = getRand(600) + radius;
        circle[i].r = radius;
        circle[i].cr = getRand(255);
        circle[i].cg = getRand(255);
        circle[i].cb = getRand(255);
    }
    return circle;
};
