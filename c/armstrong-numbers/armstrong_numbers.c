#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate)
{
    int decrement = candidate;
    int digit_count = 0;
    while( decrement > 0)
    {
        decrement /= 10;
        digit_count++;
    }
    
    int result = 0;
    decrement = candidate;
    for(int j = 0; j < digit_count; j++)
    {
        result += pow(decrement%10, digit_count);
        decrement /=10;
    }
    return candidate == result;
}

