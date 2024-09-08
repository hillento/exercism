#include "hamming.h"

int compute(const char *lhs, const char *rhs)
{
    int d = 0;
    size_t len_l = strlen(lhs);
    size_t len_r = strlen(rhs);

    if(len_r != len_l)
    {
        return -1;
    }

    for(size_t i = 0; i < len_l; i++)
    {
        if(lhs[i] != rhs[i])
        {
            d++;
        }
    }
    return d;
}
