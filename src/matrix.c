#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

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

Matrix* mul_by_num(Matrix* self, int num) {
	
	Matrix* multiplyed_m = copy_matrix(self); 

	for(int i = 0; i < multiplyed_m->rows; i++)
		for(int j = 0; j < multiplyed_m->columns; j++)
			multiplyed_m->elements[i][j] *=  num;
	
	return multiplyed_m;
}

Matrix* fill_ascending(Matrix* self) {
	Matrix* filled_m = copy_matrix(self);

	for(int i = 0; i < filled_m->rows; i++)
		for(int j = 0; j < filled_m->columns; j++)
			filled_m->elements[i][j] = j + (filled_m->columns * i);

	return filled_m;

}

Matrix* fill_random(Matrix* self, int left_border, int right_border) {
	
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

