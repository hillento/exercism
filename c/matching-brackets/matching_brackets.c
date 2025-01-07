#include "matching_brackets.h"

bool is_paired(const char *input) {
  if (input == NULL || strlen(input) == 0)
    return 1;
  int count = 1;
  char *buff = (char *)malloc(strlen(input) / 2 + 1);
  while (*input) {
    if (*input == '{' || *input == '[' || *input == '(') {
      buff[count] = *input;
      count++;
    } else if (*input == '}') {
      if (buff[count - 1] != '{' || count - 1 < 1) {
        free(buff);
        return 0;
      }
      count--;
    } else if (*input == ']') {
      if (buff[count - 1] != '[' || count - 1 < 1) {
        free(buff);
        return 0;
      }
      count--;
    } else if (*input == ')') {
      if (buff[count - 1] != '(' || count - 1 < 1) {
        free(buff);
        return 0;
      }
      count--;
    }
    input++;
  }
  if (count > 1) {
    free(buff);
    return false;
  }
  free(buff);
  return true;
}
