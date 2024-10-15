#ifndef SADDLE_POINTS_H
#define SADDLE_POINTS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
	int row;
	int column;
} saddle_point_t;

typedef struct{
	int count;
	saddle_point_t* points;
} saddle_points_t;
	
bool valid_point(int i, int j, int rc, int cc, uint8_t matrix[rc][cc]);

saddle_points_t *saddle_points(int row_count, int col_count, uint8_t matrix[row_count][col_count]);

void free_saddle_points(saddle_points_t* points);

#endif
