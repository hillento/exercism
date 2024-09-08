#include "perfect_numbers.h"

kind classify_number(int number)
{
    if ( number <= 0)
    {
        return ERROR;
    }

    int sum = 0;

    for(int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum = sum + i;
        }
    }

    if(number - sum < 0)
    {
        return ABUNDANT_NUMBER;
    }
    if(number - sum > 0)
    {
        return DEFICIENT_NUMBER;
    }
    return PERFECT_NUMBER;
}
