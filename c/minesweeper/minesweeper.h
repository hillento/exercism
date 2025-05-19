#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct coordinates {
	int row;
	int col;
}coordinates;

enum direction {
	NORTH,
	NORTHEAST,
	EAST,
	SOUTHEAST,
	SOUTH,
	SOUTHWEST,
	WEST,
	NORTHWEST,
};

typedef struct directions {
	enum direction dir;
	coordinates coor;
} directions;

char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation);

#endif
