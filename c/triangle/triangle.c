#include "triangle.h"


bool is_valid(triangle_t sides)
{
    if(sides.a + sides.b > sides.c && sides.a + sides.c > sides.b && sides.b + sides.c > sides.a)
    {
        return true;
    }
    return false;
}


bool is_equilateral(triangle_t sides)
{
    if( is_valid(sides) && sides.a == sides.b && sides.b == sides.c)
    {
        return true;
    }
    return false;
}


bool is_isosceles(triangle_t sides)
{
    if( is_valid(sides) && (sides.a == sides.b || sides.a == sides.c || sides.b == sides.c))
    {
        return true;
    }
    return false;
}


bool is_scalene(triangle_t sides)
{
    if( is_valid(sides) && sides.a != sides.b && sides.a != sides.c && sides.b != sides.c)
    {
        return true;
    }
    return false;
}
