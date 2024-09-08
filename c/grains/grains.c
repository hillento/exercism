#include "grains.h"


uint64_t square(uint8_t index)
{
    int i = index-1;
    if(index > 1 || index < 64){
        return pow(2, i);
    }
    return 0;
}
uint64_t total(void)
{
    int r = 0;
    for (int i = 0; i < 64; i++)
    {
        r += square(i);
    }
    return r;
}
