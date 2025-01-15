#include "diamond.h"

char **make_diamond(const char letter)
{
    int size = (letter - 'A') * 2 + 1;
    int mid = size / 2;
    char **diamond = malloc(size * sizeof(char *));
    for (int i = 0; i < size; i++)
    { 
      diamond[i] = malloc(size + 1 * sizeof(char));
      //Set all characters to space
      memset(diamond[i], ' ', size);
      //Add terminator
      diamond[i][size] = '\0';
    }
    for (int i = 0; i <= mid; i++){
      //Gets the approprate letter 0 = A 1 = B...
      char symb = 'A' + i;
      //Mirrored position as i. (-1 to include terminator)
      int j = size - i - 1;
      diamond[i][mid - i] = symb;
      diamond[i][mid + i] = symb;
      diamond[j][mid - i] = symb;
      diamond[j][mid + i] = symb;
    }
    return diamond;
}

void free_diamond(char **diamond)
{
    free(diamond);
    diamond = NULL;
}
