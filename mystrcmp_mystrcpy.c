// Question1 my_strcmp
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int my_strcmp(char s1[], char s2[]) // create my_strcmp function
{
    int i = 0;
    while (s1[i]==s2[i])
    {
        if (s1[i]=='\0' || s2[i]=='\0')
            break;
        i++;
    }
    if ( s1[i]=='\0' && s2[i]=='\0')
        return 1;
    else
        return 0; // my_strcmp function returns to 1 and 0
}

// int main(void)
// {
// int j;
// char s1[50], s2[50];
// printf("Please enter two words(xxxx,xxxx):\n");
// scanf("%s,%s", &s1, &s2);
// j = my_strcmp(s1, s2);
// if (j == 0)
// {
// printf("These two words are not identical");
// }
// else
// {
// printf("These two words are identical");
// }
// }

// Question 1 my_strcpy
#include <stdio.h>
#include <string.h>

void my_strcpy(char s1[], char s2[]) // create my_strcpy function
{
int i = 0;
while (s1[i] != '\0')
{
s2[i] = s1[i];
i++;
}
}

int main(void)
{
char s1[50], s2[50];
printf("Please enter a word:\n"); // input the character string
scanf("%s", s1);
my_strcpy(s1, s2);
printf("The copy of this word is %s", s2);
return 0;
}