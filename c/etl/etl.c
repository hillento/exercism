#include "etl.h"


int convert(const legacy_map *input, const size_t input_len, new_map **output){
   int totalLetters = 0;
   //initially determine number of letters we're dealing with to allocate memory
   for (size_t i = 0; i < input_len; i++) {
      totalLetters += strlen(input[i].keys);
   }
   //allocate
   *output = malloc(totalLetters * sizeof(new_map));
   //no need for a third loop but there is a need for a third stepping variable
   size_t outIndex = 0;
   //go over the input mpas
   for (size_t i = 0; i < input_len; i++) {
      //go over the string of the current map
      for (size_t j = 0; j < strlen(input[i].keys); j++, outIndex++) {
         //just map current score and letter to it's own new map
         (*output)[outIndex].key = tolower(input[i].keys[j]);
         (*output)[outIndex].value = tolower(input[i].value);
      }
   }
   //Make it alphabetical
   qsort(*output, totalLetters, sizeof(new_map), compare);
   return (int)totalLetters;
}

//sporting the new maps based on their letters to keep it alphabetical
int compare(const void *a, const void *b){
   return ((new_map*)a)->key - ((new_map*)b)->key;
}
