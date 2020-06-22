struct library //struct a library
{
    char userName[20]; // declare all variables
    int friend[50];
    int userNumber;
    int numberOfFriends;
};

int main(void)
{
    struct library *lib;
    int breakWhile = 0;
    int option;
    int UserNumber = 0;
    int i, j;
    char name1[40];
    char name2[40];
    int lib_n1;
    int lib_n2;

    while (1)
    {
        printf("Simple social network\n"); //print all options
        printf("1.Introduce new user\n");
        printf("2.Introduce social relationship\n");
        printf("3.Print report of all users\n");
        printf("4.Exit\n");
        scanf("%d", &option);
        // If the user input a number are not shown in the list
        // Ask the user input again
        while (option != 1 && option != 2 && option != 3 && option != 4)
    }
    printf("Error, Please enter the correct the function number:");
    scanf("%d", &option);
}
// Use Switch statement
switch (option)
{
case 1:
    j = 1;
    while (j > 0)
    {
        printf("Please enter the user name:");
        scanf("%s", name1);
        for (i = 0; i < numberUser; i++)
        {
            if (strcmp(&(lib + i)->userName, name1) == 0)
            {
                j = 2;
            }
        }
        //record the user to the library
        strcpy(&(lib + UserNumber)->userName, name1);
        (lib + UserNumber)->UserNumber = UserNumber + 1; // introduce the user number
        (lib + UserNumber)->numberOfFriends = 0;
        UserNumber++;
        break;

    case 2:
        printf("Please input two names: \n"); // input two names
        scanf("%s", name1);
        scanf("%s", name2);
        lib_n1 = -1;
        lib_n2 = -1;

        for (i = 0; i < numberOfUser; i++) // find the name
        {
            if (strcmp((*(lib + i)).userName, name1) == 0)
            {
                lib_n1 = i;
            }

            if (strcmp((*(lib + i)).userName, name2) == 0)
            {
                lib_n2 = i;
            }
        }

        if (lib_n1 == -1 || lib_n2 == -1)
        {
            printf("No data"); //detect whether the names are in the library
            break;
        }

        if (j == 1)
        {
            printf("This relationship has been recorded in the library.\n");
        }

        break;

    case 3:
        printf("Users' report:\n"); // print report
        for (i = 0; i < numberOfUser; i++)
        {
            printf("User Name: %s \n", lib[i].userName);
            printf("User Number: %d \n", lib[i].userNumber);
            printf("Relationships (user number):");
            for (j = 0; j < lib[i].numberOfFriends; j++)
            {
                printf("%d\n", lib[i].friend[j]);
            }
        }
        break;

        if (option == 4) // exit the programme
            break;
    }
    return 0;
}