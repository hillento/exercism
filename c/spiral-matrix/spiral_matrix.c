#include "spiral_matrix.h"

spiral_matrix_t *spiral_matrix_create(int n){
	spiral_matrix_t *mat = calloc(1, sizeof(spiral_matrix_t));

	//if there's nothing to print just return a null
	if(n < 1){
		mat->matrix = NULL;
		return mat;
	}
	//set the size to n
	mat->size = n;

	//Allocate the memory of the outer array and then inner arrays
	mat->matrix = calloc(n, sizeof(int *));
	for(int i = 0; i < n; i++){
		mat->matrix[i] = calloc(n, sizeof(int));
		memset(mat->matrix[i], 0, sizeof(int) * n);
	}
	
	//Set initial boundaries
	int x_upper_lim = n-1;
	int x_lower_lim = 0;
	int y_upper_lim = n-1;
	int y_lower_lim = 0;

	//value to write in spiral
	int i = 1;

	//until the final number has been iterated, move in the same pattern each iteration
	while(i <= n*n){
		//move right
		for(int j = x_lower_lim; j <= x_upper_lim; j++){
			mat->matrix[y_lower_lim][j] = i++;
		}
		//Increment the lower limit here to acoud conflict when moving up
		++y_lower_lim;
		//move down
		for(int k = y_lower_lim; k <= y_upper_lim; k++){
			mat->matrix[k][x_upper_lim] = i++;
		}
		//move left
		for(int jj = x_upper_lim - 1; jj >= x_lower_lim; jj--){
			mat->matrix[y_upper_lim][jj] = i++;
		}
		//move up
		for(int kk = y_upper_lim - 1; kk >= y_lower_lim; kk--){
			mat->matrix[kk][x_lower_lim] = i++;
		}
		//move boundary
		x_lower_lim++;
		x_upper_lim--;
		y_upper_lim--;
	}
	return mat;
}

//free the previously allocated memory
void spiral_matrix_destroy(spiral_matrix_t* mat){
	for (int i = 0; i < mat->size; i++){
      		free(mat->matrix[i]);
	}
	
	free(mat->matrix);
	free(mat);
}
