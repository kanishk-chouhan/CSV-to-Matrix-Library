#ifndef __MLFW__MAT__DOUBLE__
#define __MLFW__MAT__DOUBLE__
struct __mlfw_matrix_double;
typedef struct __mlfw_matrix_double mlfw_matrix_double;
mlfw_matrix_double  * mlfw_create_matrix_double(dimension_t rows,dimension_t columns);
void mlfw_destroy_matrix_double(mlfw_matrix_double *matrix);
void mlfw_matrix_double_set(mlfw_matrix_double *matrix,index_t row,index_t column,double value);
double mlfw_matrix_double_get(mlfw_matrix_double *matrix,index_t row,index_t colmn);

dimension_t mlfw_matrix_double_get_row(mlfw_matrix_double *matrix);
dimension_t mlfw_matrix_double_get_column(mlfw_matrix_double *matrix);

void mlfw_matrix_double_get_dimensions(mlfw_matrix_double *matrix,dimension_t *row,dimension_t *column);

void mlfw_matrix_double_copy(mlfw_matrix_double *source,mlfw_matrix_double *target);

mlfw_matrix_double  * mlfw_matrix_double_from_csv(const char *fileName);

#endif
