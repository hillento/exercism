#ifndef SPIRAL_MATRIX_H
#define SPIRAL_MATRIX_H

#include<stddef.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
   int size;
   int **matrix;
} spiral_matrix_t;

spiral_matrix_t *spiral_matrix_create(int n);
void spiral_matrix_destroy(spiral_matrix_t* mat);

#endif
