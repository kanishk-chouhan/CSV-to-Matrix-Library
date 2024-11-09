#include<mlfw_matrix.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef struct __mlfw_matrix_double
{
	double **data;
	dimension_t rows;
	dimension_t columns;
}mlfw_matrix_double;

mlfw_matrix_double  * mlfw_create_matrix_double(dimension_t rows,dimension_t columns)
{
	index_t e,i;
	mlfw_matrix_double *matrix;
	if(rows<=1 || columns<=1) return NULL;
	matrix=(mlfw_matrix_double *)malloc(sizeof(mlfw_matrix_double));
	if(matrix==NULL) return NULL;
	matrix->data=(double **)malloc(sizeof(double *)*rows);
	if(matrix->data==NULL)
	{ 
		free(matrix);
		return NULL;
	}
	for(e=0;e<rows;e++)
	{
		matrix->data[e]=(double *)malloc(sizeof(double)*columns);
		if(matrix->data[e]==NULL)
		{
			for(i=0;i<e;i++)
			{
				free(matrix->data[i]);
			}
			free(matrix->data);
			free(matrix);
			return NULL;
		}
	}
	matrix->rows=rows;
	matrix->columns=columns;
	return matrix;
}
void mlfw_destroy_matrix_double(mlfw_matrix_double *matrix)
{
	index_t r;
	if(matrix==NULL) return;
	if(matrix->data==NULL)
	{
		free(matrix);
		matrix=NULL;
		return;
	}
	for(r=0;r<matrix->rows;r++)
	{
		free(matrix->data[r]);
	}
	free(matrix->data);
	free(matrix);
	matrix=NULL;
}

void mlfw_matrix_double_set(mlfw_matrix_double *matrix,index_t row,index_t column,double value)
{
	if(matrix==NULL || matrix->data==NULL) return;
	if(row<0 || row>=matrix->rows) return;
	if(column<0 || column>=matrix->columns) return;
	matrix->data[row][column]=value;
}
double mlfw_matrix_double_get(mlfw_matrix_double *matrix,index_t row,index_t column)
{
	double value=0.0;
	if(matrix==NULL || matrix->data==NULL) return value;
	if(row<0 || row>=matrix->rows) return value;
	if(column<0 || column>=matrix->columns) return value;
	return matrix->data[row][column];
}

dimension_t mlfw_matrix_double_get_row(mlfw_matrix_double *matrix)
{
	if(matrix==NULL || matrix->data==NULL) return 0;
	return matrix->rows;
}

dimension_t mlfw_matrix_double_get_column(mlfw_matrix_double *matrix)
{
	if(matrix==NULL || matrix->data==NULL) return 0;
	return matrix->columns;
}

void mlfw_matrix_double_get_dimensions(mlfw_matrix_double *matrix,dimension_t *row,dimension_t *column)
{
	if(matrix==NULL || matrix->data==NULL) return;
	*row=matrix->rows;
	*column=matrix->columns;
}
mlfw_matrix_double  * mlfw_matrix_double_from_csv(const char *fileName)
{
	index_t r,c,rows,columns;
	index_t i;
	// index_t e,f;
	char m;
	double value;
	FILE *file;

	// int size_of_fileName
	// char extension[5];
	// char file_extension[5];
	
	char double_value[1025];
	mlfw_matrix_double *matrix;

	if(fileName==NULL) return NULL;
	file=fopen(fileName,"r");
	if(file==NULL) return NULL;

	rows=0;
	columns=0;
	while(1)
	{
		m=fgetc(file);
		if(feof(file)) break;
		if(rows==0)
		{
			if(m==',') columns++;
		}
		if(m=='\n') rows++;
	}
	columns++;
	matrix=mlfw_create_matrix_double(rows,columns);
	if(matrix==NULL) return NULL;
	rewind(file);
	i=0;
	r=0;
	c=0;
	while(1)
	{
		m=fgetc(file);
		if(feof(file)) break;
		if(m==',' || m=='\n')
		{
			double_value[i]='\0';
			i=0;
			value=strtod(double_value,NULL);
			matrix->data[r][c]=value;
			c++;
			if(c==matrix->columns)
			{
				c=0;
				r++;
			}
		
		}
		else
		{
			double_value[i]=m;
			i++;
		}
	
	}
	fclose(file);
	return matrix;
}

