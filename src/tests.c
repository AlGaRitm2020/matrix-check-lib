#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void test_matrix(Matrix* expected, Matrix* actual, const char* testName){
	if (!is_equal(expected, actual))
		printf("TEST %s FAILED. Expected: %s, actual: %s", "1", "you", "I");			
	else
		printf("TEST %s PASSED!");
}

void test_mul_matrix() {
	/* 
	 * This program test funtion multiply_matrix
	 *
	 */ 

	int **arr_b1 = (int **)malloc(10 * sizeof(int*));	
	for(int i = 0; i < 10; i++) {
		arr_b1[i] = (int *)malloc(10 * sizeof(int));
	}

	arr_b1[0][0] = 1; 
	arr_b1[0][1] = 2; 	
	arr_b1[0][2] = 1;
	arr_b1[1][0] = 0;
	arr_b1[1][1] = 1;
	arr_b1[1][2] = 2;

	Matrix* base_1 = create_matrix(2, 3,arr_b1 );

	int **arr_b2 = (int **)malloc(10 * sizeof(int*));	
	for(int i = 0; i < 10; i++) {
		arr_b1[i] = (int *)malloc(10 * sizeof(int));
	}

	arr_b2[0][0] = 1;
	arr_b2[0][1] = 2; 	
	arr_b2[1][0] = 1;
	arr_b2[1][1] = 0;
	arr_b2[2][0] = 1;
	arr_b2[2][1] = 2;

	Matrix* base_2 = create_matrix(3, 2,arr_b2);


	Matrix* actual = multiply_matrix(base_1, base_2);

	int **arr_exp = (int **)malloc(10 * sizeof(int*));	
	for(int i = 0; i < 10; i++) {
		arr_b1[i] = (int *)malloc(10 * sizeof(int));
	}

	arr_exp[0][0] = 2;
	arr_exp[0][1] = 3; 	
	arr_exp[1][0] = 2;
	arr_exp[1][1] = 3;

	Matrix* expected = create_matrix(2, 2,arr_exp);

	test_matrix(expected, actual,"test 1");
}

int main() {
	//test_mul_matrix();
	
	/*
	int **arr = (int **)malloc(3 * sizeof(int*));
	for(int i = 0; i < 3; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 3);
		for(int j = 0; j < 3; j++) {
			arr[i][j] = 0;
	}
	*/
	Matrix* a = create_from_scratch(2,2);
	//Matrix* c = create_matrix(3,3,arr);
	//Matrix* b = copy_matrix(c);

	print_matrix(a);

	
	int** arr_b1 = create_double_array(2,3);

	arr_b1[0][0] = 1; 
	arr_b1[0][1] = 2; 	
	arr_b1[0][2] = 1;
	arr_b1[1][0] = 0;
	arr_b1[1][1] = 1;
	arr_b1[1][2] = 2;

	Matrix* base_1 = create_matrix(2, 3,arr_b1 );

	print_matrix(base_1);

	int **arr_b2 = create_double_array(3, 2);

	arr_b2[0][0] = 1;
	arr_b2[0][1] = 2; 	
	arr_b2[1][0] = 1;
	arr_b2[1][1] = 0;
	arr_b2[2][0] = 1;
	arr_b2[2][1] = 2;

	Matrix* base_2 = create_matrix(3, 2,arr_b2);

	Matrix* actual = multiply_matrix(base_1, base_2);
		
	print_matrix(actual);

	return 0;
}
