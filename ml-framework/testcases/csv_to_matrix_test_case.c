#include<mlfw_matrix.h>
#include<stdio.h>
int main()
{
mlfw_matrix_double *matrix;
printf("Tes case for from csv\n");
matrix=mlfw_matrix_double_from_csv("Ice_Cream_Sales.csv");
if(matrix==NULL)
{
printf("Unable to load from csv file : Ice_Cream_Sales.csv\n");
return 0;
}
int rows,columns,r,c;

rows=mlfw_matrix_double_get_row(matrix);
columns=mlfw_matrix_double_get_column(matrix);

for(r=0;r<rows;r++)
{
for(c=0;c<columns;c++)
{
printf("%20.10lf  ",mlfw_matrix_double_get(matrix,r,c));
}
printf("\n");
}
mlfw_destroy_matrix_double(matrix);
return 0;
}