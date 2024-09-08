#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int n)
{
    //Left shift operator (<<) used to get 1*(2^n) my understanding is this is faster than the pow function
    //bitwise & operator used to match the binary pattern of the allergy in question to the score.
    return n & 1<<allergen;
}

allergen_list_t get_allergens(int n)
{
    //initialize the list at 0s to avoid memory issues
    allergen_list_t l = {0};
    //start count at 0
    l.count = 0;
    //itterate all allergens using the is_allergic_to function to fill out list of allergens
    for(int i = ALLERGEN_EGGS; i < ALLERGEN_COUNT; i++)
    {
        l.allergens[i] = is_allergic_to(i, n);
        //if m contains the allergen add 1 to the count
        if(l.allergens[i])
        {
            l.count++;
        }
    }
    return l;
}
