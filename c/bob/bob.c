#include "bob.h"

char *hey_bob(char *greeting)
{
   //flags to help in the end
   int yellFlag = 0;
   int questionFlag = 0;
   int noise = 0;
   
   //Get the length for looping
   int l = strlen(greeting);

   if (greeting == NULL || l ==0) {
      return "Fine. Be that way!";
   }
  
   char lastNoSpace = ' ';
   int alpha = 0;
   int upper = 0;
   for (int i = 0; i < l; i++) {
      if (isalpha(greeting[i])){
         alpha++;
      }
      if (isupper(greeting[i])){
         upper++;
      }
      if (!isspace(greeting[i])) {
         lastNoSpace = greeting[i];
      }
   }

   if(alpha == upper && alpha > 0) {
      yellFlag = 1;
   }

   if(lastNoSpace == '?') {
      questionFlag = 1;
   }

   for (int i = 0; i < l; i++) {
      if (!isspace(greeting[i])){
         noise = 1;
      }
   }

   if (yellFlag == 1 && questionFlag == 1) {
      return "Calm down, I know what I'm doing!";
   }else if (yellFlag == 1) {
      return "Whoa, chill out!";
   }else if (questionFlag == 1) {
      return "Sure.";
   }else if (noise == 0) {
      return "Fine. Be that way!";
   }
      return "Whatever.";

}
