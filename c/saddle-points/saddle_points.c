#include "saddle_points.h"

bool valid_point(int i, int j, int rc, int cc, uint8_t matrix[rc][cc]){
	//make sure talles in row
	for(int k = 0; k < rc; k++){
		if(k != i && matrix[k][j] < matrix[i][j]){
			return false;
		}
	}
	//make sure shortest in column
	for(int k = 0; k < cc; k++){
		if(k != j && matrix[i][k] > matrix[i][j]){
	 		return false;
		}
	}
	return true;
}

saddle_points_t *saddle_points(int row_count, int col_count, uint8_t matrix[row_count][col_count]){
	//allocate the memory and initialzie the fields
	saddle_points_t* s_points = malloc(sizeof(saddle_points_t));
	s_points->points = NULL;
	s_points->count = 0;
	//if there aren't any points to consider, just return the blank
	if(matrix == NULL){
		return s_points;
	}
	//enough memory that each point could be valid
	s_points->points = malloc(sizeof(saddle_point_t) * row_count * col_count);

	//iterate the matrix, and check if it's a saddle point
	for(int i = 0; i < row_count; i++){
		for(int j = 0; j < col_count; j++){
			if(valid_point(i, j, row_count, col_count, matrix)){
				//add 1 to the count and add the point to point (+1 to account for base 0)
				s_points->points[s_points->count++] = (saddle_point_t){i+1, j+1};
			}
		}
	}
	return s_points;
}

void free_saddle_points(saddle_points_t* s_points){
	//if there are points, make sure they are freed
	if(s_points->points != NULL){
		free(s_points->points);
	}
	//free the rest of the struct
	free(s_points);
}
