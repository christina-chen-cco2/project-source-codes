/**********************************************************************************************************************************************************
//
//    NAME: Christina Chen
//
//    HOMEWORK: Project 1
//
//    CLASS: ICS 212
//
//    DATE: October 27, 2018
//
//    FILE: userMenu.c
//
//    Description: Lists the options of adding, deleting, and printing records for user to choose and to enter the appropriate information when prompted.
//
***********************************************************************************************************************************************************/

#include "userMenu.h"

extern int debugmode;

/*******************************************************************************************************************************************************************
//
//  Function name: menu
//
//  DESCRIPTION: Lists the options of adding, deleting, and printing records for user to choose, asks the user's information, and calls the appropriate functions.
//
//  Parameters: bank (struct record *) : list to use 
//
//  Return values: none
//
*******************************************************************************************************************************************************************/

void userMenu(struct record * bank)
{
    char menuChoice[30], name[100], address[100], * pmenuChoiceNewline;
    int accountno, i = 0;
    char searchNewline;

    if (debugmode == 1)
    {
        printf("\n*************************DEBUG*************************\nFunction name: menu\nParameters: \n");
        printf("\tstruct record * bank: %p\n", (void *) bank);
        printf("*******************************************************\n");
    }

    while (strcmp(menuChoice, "Exit") != 0)
    {
        printf("\n\n\nMENU SELECTION\n*\tAdd a Record\n*\tPrint a Record\n*\tPrint All Records\n*\tDelete a Record\n*\tExit\nPlease type your selection from the menu:    ");
    
        fgets(menuChoice, 30, stdin);

        pmenuChoiceNewline = strchr(menuChoice, '\n');
 
        *pmenuChoiceNewline = '\0';

        if (strcmp(menuChoice, "Add a Record") == 0)
        {
            printf("\nMENU SELECTION --> ADD A RECORD\n\tName:    ");
            fgets(name, 100, stdin);
            searchNewline = name[i];
            while (searchNewline != '\n')
            {
                searchNewline = name[i];
                i++;
            }
            name[i] = '\0';
            i = 0;
            printf("\tAccount number:    ");
            scanf("%d", &accountno);
            getchar();
            getaddress(address, accountno);
            addRecord(&bank, accountno, name, address);
        }
        else if (strcmp(menuChoice, "Print All Records") == 0)
        {
            printf("\nMENU SELECTION --> PRINT ALL RECORDS");
            printAllRecords(bank);
        }
        else if (strcmp(menuChoice, "Print a Record") == 0)
        {
            printf("\nMENU SELECTION --> PRINT A RECORD");
            printf("\n\tAccount number:    ");
            scanf("%d", &accountno);
            getchar();
            printRecord(bank, accountno);
        }
        else if (strcmp(menuChoice, "Delete a Record") == 0)
        {
            printf("\nMENU SELECTION --> DELETE A RECORD");
            printf("\n\tAccount number:    ");
            scanf("%d", &accountno);
            getchar();            
            deleteRecord(&bank, accountno);
        }
        else
        {
            if (strcmp(menuChoice, "Exit") != 0) 
            {
                printf("Not available choice or incorrect spelling. Please try again.\n");
            }
        }
    }    

}

