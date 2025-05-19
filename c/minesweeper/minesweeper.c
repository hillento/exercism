#include "minesweeper.h"

static size_t lastrow = 0;

char **annotate(const char **minefield, const size_t rows){
   if(minefield == NULL){
         return NULL;
   }

   lastrow = rows;

   size_t rowlen = strlen(minefield[0]);

   char **result = calloc(rows, sizeof(char*));

   for (size_t i = 0; i < rows; i++){
      result[i] = calloc(rowlen + 1, sizeof(char*));
      for (size_t j = 0; j < rowlen; j++){
         result[i][j] = '0';
      }
      result[i][rowlen] = '\0';
   }
   for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < rowlen; j++) {
         if (minefield[i][j] == '*'){
            result[i][j] = '*';
            //up
            if( i > 0 ) {
               if(j > 0 && minefield[i - 1][j - 1] != '*'){
                  result[i - 1][j - 1]++;
               }
               if(minefield[i - 1][j] != '*'){
                  result[i - 1][j]++;
               }
               if( j + 1 < rowlen && minefield[i - 1][j + 1] != '*'){
                  result[i - 1][j + 1]++;
               }
            }
            if (j > 0 && minefield[i][j - 1] != '*'){
               result[i][j - 1]++;
            }
            if (j + 1 < rowlen && minefield[i][j + 1] != '*') {
               result[i][j+1]++;
            }
            //down
            if( i + 1 < rows) {
               if (j > 0 && minefield[i + 1][j - 1] != '*') {
                  result[i + 1][j - 1]++;
               }
               if ( minefield[i +1][j] != '*') {
                  result[i + 1][j]++;
               }
               if (j + 1 < rowlen && minefield[i + 1][j + 1] != '*') {
                  result[i + 1][j + 1]++;
               }
            }
         }
      }
      for(size_t i = 0; i < rows; i++){
         for(size_t j = 0; j < rowlen; j++){
            if(result[i][j] == '0'){
               result[i][j] = ' ';
            }
         }
      }
   }
   return result;
}

void free_annotation(char **annotation){
   if(annotation != NULL){
   for(size_t i = 0; i < lastrow; i++){
      free(annotation[i]); 
      }
      free(annotation); 
   }
}
