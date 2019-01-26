/************************************************************************************
//
//    NAME: Christina Chen
//
//    HOMEWORK: Project 1
//
//    CLASS: ICS 212
//
//    DATE: October 27, 2018
//
//    FILE: main.c
//
//    Description: Main for project proram; contains debugging.
//
*************************************************************************************/

#include "main.h"

int debugmode = 0;

/**************************************************************************************************
//
//  Function name: main
//
//  DESCRIPTION: Calls menu function and checks command-line arguments for debugging option.
//
//  Parameters: argc (int) : number of command-line arguments
//              argv (char **) : contains the command-line arguments
//
//  Return values: 0 : executed and terminated successfully
//
***************************************************************************************************/

int main(int argc, char *argv[ ])
{
    struct record * start = NULL;
    if (argc == 2 && strcmp(argv[0], "./project") == 0 && strcmp(argv[1], "debug") == 0)
    {
        readfile(&start, "readThese.txt");
        debugmode = 1;
        printf("\n*************************DEBUG*************************\nFunction name: main\nParameters:\n");
        printf("\tint argc: %d\n", argc);
        printf("\tchar * argv[ ]: %p\n", (void *) argv);
        printf("*******************************************************\n");
        userMenu(start);
        writefile(start, "empty.txt");
    }
    else if (argc == 1 && strcmp(argv[0], "./project") == 0)
    {
        readfile(&start, "readThese.txt");
        userMenu(start);
        writefile(start, "empty.txt");
    }
    else
    {
         printf("-bash: e: command not found\n");
    }

    return 0;
}
