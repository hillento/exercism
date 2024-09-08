#include "pangram.h"

bool is_pangram(const char *sentence)
{
    if(!sentence) return false;

    int letter_count = 0;
    bool letters[26] = {0};
    for(unsigned i = 0; i < strlen(sentence)+1; i++)
    {
        if(isalpha(sentence[i]))
        {
            char letter = tolower(sentence[i]);
            int index = letter - 'a';
            if(!letters[index])
            {
                letter_count++;
                letters[index] = true;

            }
        }
    }
    return letter_count == 26;
}
