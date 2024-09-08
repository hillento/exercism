#include "binary.h"

int convert(const char *input)
{
    size_t exponent = strlen(input);
    int n = 0;

    for(size_t i = 0; i < exponent; i++)
    {
        if(input[i] == '1')
        {
            n += pow(2, exponent-i-1);
        }
        if(input[i] != '1' && input[i] != '0')
        {
            return -1;
        }
    }
    return n;
}