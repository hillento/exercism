#include "collatz_conjecture.h"

int steps(int start)
{
    int c = 0;
    int n = start;

    if(n < 1)
    {
        return -1;
    }

    while (n > 1)
    {
        switch (n % 2)
        {   
        case 0: 
            n = n/2;
            c++;
            break;
        default:
            n = 3*n+1;
            c++;
            break;
        }
    }
    return c;
}
