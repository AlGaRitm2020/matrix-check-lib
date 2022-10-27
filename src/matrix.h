#define __matrix_h_


#define MAX_SIZE 10 


typedef struct {
	unsigned int rows;
	unsigned int columns;
	int ** elements;

} Matrix; 

Matrix* create_matrix(int rows, int columns, int **elems);
Matrix* copy_matrix(Matrix* self);
Matrix* mul_by_num(Matrix* self, int num);
Matrix* fill_ascending(Matrix* self);
void delete_matrix(Matrix* self);


