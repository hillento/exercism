#include "series.h"

slices_t slices(char *input_text, unsigned int substring_length){

   //get full length of input
   size_t l = strlen(input_text);

   //make sure params are valid
   if (!substring_length || l < substring_length){
      return (slices_t){0};
   }

   //find how many substrings there are
   size_t outputSize = l - substring_length + 1;
   //make the output array and allocate the memory
  slices_t slices = { outputSize, malloc(outputSize * sizeof(char*))};

   //only step the number of time determined above
   for (size_t i = 0; i < outputSize; i++ ) {
      //allocate the membory for the string going into the array
      char *substr = calloc(substring_length + 1, sizeof(char));
      //use a sliding window to get the substring 
      slices.substring[i] = strncpy(substr, input_text + i, substring_length);
   }
   //return the slcies
   return slices;
}
