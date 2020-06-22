#include<stdio.h>

int main(void)
{
    int year, month, days;
    printf("Enter year and month(YYYY,MM)\n"); 
    scanf("%d,%d", &year, &month); // input year and month
    while(year < 0 || month > 12 || month < 1 ) // detect whether input values are ture
{
    printf("Error! Please enter again(YYYY,MM)\n");
    scanf("%d,%d", &year, &month ); // if not ture, input again
}
    if(month == 4||month == 6||month == 9||month == 11)
    days = 30; // month 4, 6, 9, 11 have 30 days
   
    if(month == 2) // days in month 2 is different in leap years
{
    if((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0 && year % 3200 != 0)) // method to detect whether the input is a leap year
    days = 29; // In leap year, month 2 has 29 days
    else
    days = 28;
}
    else
    days = 31; // month except 2, 4, 6, 9, 11 have 31 days
   
    printf("days in this month = %d", days); // outcome
    return 0;
}