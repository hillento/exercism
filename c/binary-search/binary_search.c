#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length)
{
    if(!arr) return NULL;
    int min = 0;
    int max = length-1;

    while(min <= max)
    {
        int mean = (min + max)/2;
        if( arr[mean] > value)
            max = mean - 1;
        if(arr[mean] < value)
            min = mean +1;
        if(arr[mean] == value)
            return &arr[mean];
    }
    return NULL;
}

