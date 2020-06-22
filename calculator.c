#include <stdio.h>
int main(void)
{
// Declare all variables
    int option; 
// Function 1: Three input numbers and average of them
    float n1, n2, n3, average;
// Function 2: The number of iteration required
    int iteration, i;
    double pi;
// Function 3: j is the input, k is the square root of j
    int j, k;
// while(1) will run this loop continuously until the user input "Exit"
    while (1)
    {
        // Print all the functions
        printf("Calculator\n");
        printf("1. Average\n");
        printf("2. Calculate π to the nth iteration\n");
        printf("3. Square root\n");
        printf("4. Exit\n");
        printf("Choose the number with the corresonding function above:");
        scanf("%d", &option);

        // If the user input a number are not shown in the list
        // Ask the user input again
        while (option != 1 && option != 2 && option != 3 && option != 4)
        {
            printf("Error, Please enter the correct the function number:");
            scanf("%d", &option);
        }
        // Use Switch statement
        switch (option)
        {
        // Calculate the average of three numbers
        case 1:
            printf("Please enter three numbers in the form xx,xx,xx:");
            scanf("%f,%f,%f", &n1, &n2, &n3);
            average = (n1 + n2 + n3) / 3;
            printf("Average = %f\n", average);
            break;

        // Iteration of pi
        case 2:
            printf("Please enter the presion of π(number of iteration):");
            scanf("%d", &iteration);
            pi = 0.000000;
            for (i = 1; i <= iteration; i++)
            {
                if (i % 2 != 0)
                {
                    pi = pi + (4.000000 / (2.000000 * i - 1.000000));
                }
                else
                {
                    pi = pi + (4.000000 / (-2.000000 * i + 1.000000));
                }
            }
            printf(" After %d iteration, the π = %lf\n", iteration, pi);
            break;

        // Use for loop to calculate the integer solution of the input
        case 3:
            printf("Please enter an integer:");
            scanf("%d,", &j);
            for (k = 0; k * k < j; k++)
                ;
            if (k * k == j)
            {
                printf("The square root of %d is %d\n", j, k);
            }
            else
            {
                printf("%d dose not have an integer solution\n", j);
            }
            break;
        }

        // Exit the calculator
        if (option == 4)
            break;
    }
    return 0;
}