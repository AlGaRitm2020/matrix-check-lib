#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
/*
int main() {
	int **arr = (int **)malloc(10 * sizeof(int*));	
	for(int i = 0; i < 10; i++) {
		arr[i] = (int *)malloc(10 * sizeof(int));
		for(int j=0; j< 10;j++) 
			arr[i][j] = 12;
	}
	arr[0][0] = 0;

	int n=4, m=4;
	
	Matrix* some = create_matrix(n, m, arr);

	printf("%d\n", some->rows);
	printf("%d\n", some->columns); 

	
	int number = 2;
	printf("Copied matrix: \n");
	Matrix* newm = copy_matrix(some);
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			printf("%d ", newm->elements[i][j]);
		printf("\n");
	}

	printf("Multiplyed matrix: \n");
	Matrix* mulm = mul_by_num(some, number);
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			printf("%d ", mulm->elements[i][j]);
		printf("\n");
	}


	printf("Filled ascending matrix: \n");
	Matrix* fill_abs = fill_ascending(some);
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			printf("%d ", fill_abs->elements[i][j]);
		printf("\n");
	}

	delete_matrix(fill_abs);

	printf("test copyed matrix\n");
	Matrix* other = copy_matrix(some);
	if (is_equal(some, other) == 1)
		printf("This matrices are equeal\n");
	else
		printf("This matrices are different\n");
	printf("Filled ascending matrix: \n");

	Matrix* filled = fill_ascending(some);
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			printf("%d ", fill_abs->elements[i][j]);
		printf("\n");
	}


	return 0;
}
*/
