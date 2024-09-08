#include "isogram.h"

bool is_isogram(const char phrase[])
{
    if(!phrase) return false;
    int counts[26] = {0};
    unsigned len = strlen(phrase) +1;

    for(unsigned i = 0; i < len; i++)
    {
        if(isalpha(phrase[i]))
        {
            char letter = tolower(phrase[i]);
            int index = letter - 'a';
            counts[index]++;
            if(counts[index] > 1) return false;
        }
    }
    
    return true;
}
