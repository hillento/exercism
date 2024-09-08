#include "darts.h"

int score(coordinate_t coords)
{
    float r = sqrt(pow(coords.x, 2)+pow(coords.y, 2));

    if( r > 10)
    {
        return 0;
    }
    if(r > 5)
    {
        return 1;
    }
    if(r > 1)
    {
        return 5;
    }
    return 10;
}
