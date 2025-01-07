#include "secret_handshake.h"
#include <stdlib.h>

const char **commands(size_t number) {

   const char **hs = calloc(4, sizeof(char *));
   size_t len = 0;
   if((number & 16) == 16){
      if ((number & 8) == 8) hs[len++] = "jump";
      if ((number & 4) == 4) hs[len++] = "close your eyes";
      if ((number & 2) == 2) hs[len++] = "double blink";
      if ((number & 1) == 1) hs[len++] = "wink";
   }else{
      if ((number & 1) == 1) hs[len++] = "wink";
      if ((number & 2) == 2) hs[len++] = "double blink";
      if ((number & 4) == 4) hs[len++] = "close your eyes";
      if ((number & 8) == 8) hs[len++] = "jump";
   }

 return hs;
}
