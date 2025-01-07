#include "anagram.h"

void find_anagrams(const char *subject, struct candidates *candidates) {
   
   int alpha[26] = {0};
   int l = strlen(subject);
   char *sub = (char*) calloc(l+1, sizeof(char));

   for (int i = 0; i < l; i++) {
      int index = tolower(subject[i]) - 97;
      alpha[index]++;
      sub[i] = (char) index;
   }
   
   for (size_t i = 0; i < candidates->count; i++) {
      int candidate[26] = {0};
      struct candidate *curr = &candidates->candidate[i];
      curr->is_anagram = IS_ANAGRAM;

      int cLen = strlen(curr->word);
      char *can = (char*) calloc(cLen+1, sizeof(char));
      
      for (int j = 0; j < cLen; j++) {
         int index = tolower(curr->word[j]) - 97;
         candidate[index]++;
         can[j] = (char) index;
      }

      int comp = strcmp(sub, can);
      free(can);

      if (comp == 0){
         candidates->candidate[i].is_anagram = NOT_ANAGRAM;
         continue;
      }

      for ( int j = 0; j < 26; j++) {
         if (alpha[j] != candidate[j]) {
            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
            break;      
         }
      }
   }
   free(sub);
}
