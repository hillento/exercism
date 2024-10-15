#include "pascals_triangle.h"

void free_triangle(uint8_t **triangle, size_t rows){
	for(size_t i = 0; i < rows; i++){
		free(triangle[i]);
	}
	free(triangle);
}
uint8_t **create_triangle(size_t rows){
	if(rows == 0){
		uint8_t **pt = calloc(1,sizeof(uint8_t *));
		pt[0] = calloc(1,sizeof(uint8_t));
		return pt;
	}
	
	uint8_t **pt = calloc(rows, sizeof(uint8_t *));
	for(size_t i = 0; i < rows; i++){
		pt[i] = calloc(rows, sizeof(uint8_t));

		if(i == 0){
			pt[0][0] = 1;
		}else{
			pt[i][0] = 1;
			pt[i][i] = 1;
			for(size_t j = 0; j < rows; j++){
				pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j];
			}
		}
	}
	return pt;
}
