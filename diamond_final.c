#include <stdio.h>
int main(void)
{
    int i, j, k, num;
    // i is the input
    // j is the row of the diamond
    // k is the position number of space and *
    // num is the input number minus
    printf("Input an integer to create a diamond:\n");
    scanf("%d", &i);
    // print the upper part of the diamond
    num = i - 1;
    for(j = 1; j <= i; j++)
    {
        for(k = 1; k <= num; k++) // print the space part
        printf(" ");
        num--;
        for(k = 1; k <= 2 * j - 1; k++) // print the * part 
        printf("*");
        printf("\n");
    }
    num = 1;
    for(j = 1; j <= i - 1; j++) 
    // print the remaining part of the diamond
    {
        for(k = 1; k <= num; k++) // print the space part
        printf(" ");
        num++;
        for(k = 1; k <= 2 * (i - j) - 1; k++) // print the * part
        printf("*");
        printf("\n");
    }
    return 0;
}