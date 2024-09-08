#include "eliuds_eggs.h"

int egg_count(int d)
{
    int i = 0;

    while(d > 0)
    {
        if(d % 2 == 1)
        {
            i++;
        }
        d = d/2;
    }
    return i;
}
