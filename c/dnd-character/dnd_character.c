#include "dnd_character.h"

int modifier(int score)
{
    return (int)floor((score - 10) / 2.0);
}

int ability(void)
{
    int stat = 0;
    int low = 0;
    srand(time(NULL));
    for(int i = 0; i < 4; i++)
    {
        int roll = (rand() % 6)+1;
        
        if( roll < low){
            low = roll;
        }

        stat += roll;
    }
    return stat-low;
}

dnd_character_t make_dnd_character(void)
{
    dnd_character_t character;
    character.strength = ability();
    character.dexterity = ability();
    character.constitution = ability();
    character.intelligence = ability();
    character.wisdom = ability();
    character.charisma = ability();
    character.hitpoints = 10 + modifier(character.constitution);

    return character;
}
