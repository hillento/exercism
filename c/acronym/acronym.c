#include "acronym.h"

char *abbreviate(const char *phrase) {
  if (phrase == NULL)
    return NULL;
  if (strlen(phrase) == 0)
    return NULL;
  char buff[strlen(phrase)];
  int count = 0;
  int first = 1;

  for (int i = 0; phrase[i] != '\0'; i++) {
    if (isalpha(phrase[i]) && first == 1) {
      buff[count] = toupper(phrase[i]);
      count++;
      first = 0;
    }
    if (isspace(phrase[i]) || phrase[i] == '-') {
      first = 1;
    }
  }
  char *r = malloc(count * sizeof(char));
  strncpy(r, buff, count);
  r[count] = '\0';
  return r;
}
