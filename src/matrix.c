#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"


Matrix* ERROR = NULL;

int** create_double_array(int rows, int columns){
	int** array = (int **)malloc(sizeof(int*) * rows);

	for(int i = 0; i < rows; i++) {
		array[i] = (int *)malloc(sizeof(int) * columns);
		for(int j = 0; j < columns; j++) {
			array[i][j] = 0;
		}
	}

	return array;
}

Matrix* create_matrix(int rows, int columns, int** elems) {
	/* 
	 * Creates Marix sturct by passing size and double array 
	 */ 
	Matrix* matrix = (Matrix *)malloc(sizeof(Matrix));	
	matrix->elements = elems;
	matrix->rows = rows;
	matrix->columns = columns;

	return matrix;

}

Matrix* create_from_scratch(int rows, int columns) {
	// creating empty array rowsXcolumns
	
	int** zero_array = (int**)malloc(sizeof(int*) * rows);
	for(int i = 0; i < rows; i++){
		zero_array[i] = (int *)malloc(sizeof(int) * columns);
		for(int j = 0; j < columns; j++)
			zero_array[i][j] = 0;
	}
	

	// calling funtion that creates matrix from array
	Matrix* empty_m = create_matrix(rows, columns, zero_array);
	return empty_m; 

}

Matrix* copy_matrix(Matrix* self) {
	/* 
	 * Making deep copy of Matrix 
	 * Without dependensies
	 */ 
	int **copy_elems = (int **)malloc(self->rows * sizeof(int*));
	for(int i = 0; i < self->rows; i++) {
		copy_elems[i] = (int *)malloc(self->rows * sizeof(int*));
		for (int j = 0; j < self->columns; j++) 
			copy_elems[i][j] = self->elements[i][j];
	}

	Matrix* dest_m = create_matrix(self->rows, self->columns, copy_elems);
	return dest_m;

}
Matrix* print_matrix(Matrix* self) {
	printf("\nMatrix %dx%d {\n", self->rows, self->columns);

	for(int i = 0; i < self->rows; i++) {
		printf(" ");
		for(int j = 0; j < self->columns; j++) {
			printf("%d ", self->elements[i][j]);
		}
		printf("\n");
	}
	printf("}");
}




Matrix* mul_by_num(Matrix* self, int num) {
	
	Matrix* multiplyed_m = copy_matrix(self); 

	for(int i = 0; i < multiplyed_m->rows; i++)
		for(int j = 0; j < multiplyed_m->columns; j++)
			multiplyed_m->elements[i][j] *=  num;
	
	return multiplyed_m;
}


Matrix* multiply_matrix(Matrix* self_orig, Matrix* other_orig) {

	
	Matrix* self = create_matrix(self_orig->rows, self_orig->columns, self_orig->elements);
	Matrix* other = create_matrix(other_orig->rows, other_orig->columns, other_orig->elements);

	Matrix* result_m = create_from_scratch(self->rows, other->columns); 

	for(int i = 0; i < result_m->rows; i++) {
		for(int j = 0; j < result_m->columns; j++) {
			int chain = 0;
			for(int k = 0; k < self->rows; k++)
			{
				int chain_elem = 0;
				for(int l = 0; l < other->columns; l++) {
					chain_elem = self->elements[i][l] + other->elements[k][j];
				}
				chain += chain_elem;
			}

			result_m->elements[i][j] = chain;
		}

	}
	
	return result_m;	
}

Matrix* fill_ascending(Matrix* self) {
	Matrix* filled_m = copy_matrix(self);

	for(int i = 0; i < filled_m->rows; i++)
		for(int j = 0; j < filled_m->columns; j++)
			filled_m->elements[i][j] = j + (filled_m->columns * i);

	return filled_m;
	return 0;


}

Matrix* fill_random(Matrix* self, int left_border, int right_border) {
	srand(time(0));
	Matrix* rand_m = copy_matrix(self);

	for(int i = 0; i < rand_m->rows; i++)
		for(int j = 0; j < rand_m->columns; j++)
			rand_m->elements[i][j] = left_border + rand() % (right_border - left_border);
	
	return rand_m;
}


#define TRUE 1
#define FALSE 0
int is_equal(Matrix* self, Matrix* other) {
	if (self->rows != other->rows || self->columns != other-> columns)
		return FALSE;
	for(int i = 0; i < self->rows; i++) 
		for(int j = 0; j < self->columns; j++) 				
			if (self->elements[i][j] != other->elements[i][j]) 
				return FALSE;
			
	return TRUE;
} 




void delete_matrix(Matrix* self) {
	/*
	 * Removing all data from Matrix structure
	 * Firstly removing elements 
	 * Secondly Matrix itself 
	 */

	free(self->elements);
	free(self);
}

