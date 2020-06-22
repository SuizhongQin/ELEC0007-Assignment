// Question 2 matrices adding
#include <stdio.h>
#include <stdlib.h>
void add_matrices(int m1[100][100], int m2[100][100], int destination_matrix[100][100], int n_rows, int n_columns) // add_matrices function
{
int num1, num2;
for (num1 = 0; num1 < n_rows; num1++)
{
for (num2 = 0; num2 < n_columns; num2++)
{
destination_matrix[num1][num2] = m1[num1][num2] + m2[num1][num2];
}
}
}

int main(void)
{
int m1[100][100], m2[100][100], destination_matrix[100][100], n_rows, n_columns, num1, num2; // declare all variables

printf("Please rows and columns of matrices:xx,xx:\n"); // input the size of matrices
scanf("%d,%d", &n_rows, &n_columns);

printf("Please enter the first matrix elements:\n"); // input the first matrix
for (num1 = 0; num1 < n_rows; num1++)
{
for (num2 = 0; num2 < n_columns; num2++)
{
scanf("%d", &m1[num1][num2]);
}
}
printf("Please enter the second matrix elements:\n"); // input the second matrix
for (num1 = 0; num1 < n_rows; num1++)
{
for (num2 = 0; num2 < n_columns; num2++)
{
scanf("%d", &m2[num1][num2]);
}
}
add_matrices(m1, m2, destination_matrix, n_rows, n_columns); // add two matrices
for (num1 = 0; num1 < n_rows; num1++)
{
for (num2 = 0; num2 < n_columns; num2++)
{
printf("%d", destination_matrix[num1][num2]); // print results
}
}
return 0;
}