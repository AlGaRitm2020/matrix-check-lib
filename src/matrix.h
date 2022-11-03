#define __matrix_h_


#define MAX_SIZE 10 


typedef struct {
	unsigned int rows;
	unsigned int columns;
	int ** elements;

} Matrix; 

Matrix* create_matrix(int rows, int columns, int **elems);
Matrix* create_from_scratch(int rows, int columns);
Matrix* copy_matrix(Matrix* self);
Matrix* multiply_matrix(Matrix* self, Matrix* other);

Matrix* print_matrix(Matrix* self);
Matrix* mul_by_num(Matrix* self, int num);
Matrix* fill_ascending(Matrix* self);
int** create_double_array(int rows, int columns);
void delete_matrix(Matrix* self);
int is_equal(Matrix* some, Matrix* other);

