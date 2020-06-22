#include <stdio.h>
#include <stdlib.h>
void add_matrices(int m1[100][100], int m2[100][100], int destination_matrix[100][100], int n_rows, int n_columns) // add_matrices function
{
    //elements in row
    for(int num1 = 0; num1 < n_rows; num1++)
    {
        //elements in column
        for(int num2 = 0; num2 < n_columns; num2++)
        {
            //sum
            *(destination_matrix + num1*n_columns + num2) = *(m1 + num1*n_columns + num2) + *(m2 + num1*n_columns + num2);
        }
    }    
}