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
//    FILE: getaddress.c
//
//    Description: Asks user for multi-line address and stores it in an array.
//
*************************************************************************************/

#include "getaddress.h"

extern int debugmode;

/**************************************************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION: Asks user for multi-line address and stores it in a single array that's passed.
//
//  Parameters: address (char[ ]) : array to store the user's address in
//              accountno (int) : user's account number 
//
//  Return values: none
//
***************************************************************************************************/

void getaddress(char address[ ], int accountno)
{
    char character;
    int i = 0;

    if (debugmode == 1)
    {
        printf("\n*************************DEBUG*************************\nFunction name: getaddress\nParameters:\n");
        printf("\tchar address[ ]: %p\n", (void *) address);
        printf("\tint accountno: %d\n", accountno);
        printf("*******************************************************\n");
    }

    printf("\tAddress:\n\t(Press ENTER after each line. Type * before ENTER at the end of the last line.)\n\t\t");

    character = fgetc(stdin);

    do
    {
        address[i] = character;
        i++;
        character = fgetc(stdin);
        printf("\r\t\t");
    }
    while (character != '*');

    getchar();

    address[i] = '\0';

}
