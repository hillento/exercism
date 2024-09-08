#include "resistor_color_duo.h"

int color_code (resistor_band_t bands[])
{
    char s[20];

    sprintf(s,"%d%d", bands[0], bands[1]);

    int n = atoi(s);

    return n;
}
