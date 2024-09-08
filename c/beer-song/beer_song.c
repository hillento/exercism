#include "beer_song.h"

void recite(uint8_t start_bottles, uint8_t take_down, char **song)
{
    int j = 0;
    for ( int i = start_bottles; i > ( start_bottles - take_down); i--)
    {
        switch (i)
        {
        case 2:
            sprintf(song[j++],"%d bottles of beer on the wall, %d bottles of beer.",i,i);
            sprintf(song[j++],"Take one down and pass it around, %d bottle of beer on the wall.", i-1);
            strcpy(song[j++],"");
            break;
        case 1:
            sprintf(song[j++],"%d bottle of beer on the wall, %d bottle of beer.",i,i);
            sprintf(song[j++], "Take it down and pass it around, no more bottles of beer on the wall.");
            strcpy(song[j++],"");
            break;

        case 0:
            sprintf(song[j++],"No more bottles of beer on the wall, no more bottles of beer.");
            sprintf(song[j++],"Go to the store and buy some more, 99 bottles of beer on the wall.");
            break;
        
        default:
            sprintf(song[j++], "%d bottles of beer on the wall, %d bottles of beer.",i,i);
            sprintf(song[j++], "Take one down and pass it around, %d bottles of beer on the wall.",i-1);
            strcpy(song[j++],"");
            break;
        }
    }
}
