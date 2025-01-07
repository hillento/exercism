#include "roman_numerals.h"

typedef struct {
  char *symbol;
  unsigned int value;
} Roman_numeral_t;

const Roman_numeral_t numerals[] = {
    {"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100},
    {"XC", 90},  {"L", 50},   {"XL", 40}, {"X", 10},   {"IX", 9},
    {"V", 5},    {"IV", 4},   {"I", 1},
};

char *to_roman_numeral(unsigned int number) {
  int buffer_size = sizeof(numerals) / sizeof(numerals[0]);
  char *rns = calloc(10, sizeof(char));

  for (int i = 0; i < buffer_size; i++) {
    while (number >= numerals[i].value) {
      strcat(rns, numerals[i].symbol);
      number -= numerals[i].value;
    }
  }
  return rns;
}
