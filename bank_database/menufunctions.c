/***************************************************************************************************************
//
//    NAME: Christina Chen
//
//    HOMEWORK: Project 1
//
//    CLASS: ICS 212
//
//    DATE: October 27, 2018
//
//    FILE: menufunctions.c
//
//    Description: Contains functions for adding records to, deleting records, and printing records from list.
//
****************************************************************************************************************/

#include "functions.h"

extern int debugmode;

/**************************************************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION: Adds records to list.
//
//  Parameters: pbank (struct record **) : pointer to the address of a record object
//              uaccountno (int) : user's account number
//              uname (char[ ]) : user's name
//              uaddress (char[ ]) : user's address
//
//  Return values: none
//
***************************************************************************************************/

void addRecord(struct record ** pbank, int uaccountno, char uname[ ], char uaddress[ ])
{
    struct record * temp = malloc(sizeof(struct record)), * tempNext = *pbank, * tempPrev = NULL;
    int success = 0, accnoPosition = 0;

    if (debugmode == 1)
    {
        printf("\n*************************DEBUG*************************\nFunction name: addRecord\nParameters:\n");
        printf("\tstruct record ** pbank: %p\n", (void *) pbank);
        printf("\tint uaccountno: %d\n", uaccountno);
        printf("\tchar uname[ ]: %p\n", (void *) uname);
        printf("\tchar uaddress[ ]: %p\n", (void *) uaddress);
        printf("*******************************************************\n");
    }

    (*temp).accountno = uaccountno;
    strcpy((*temp).name, uname);
    strcpy((*temp).address, uaddress);
    (*temp).next = tempNext;

    if (tempNext == NULL)
    {
        *pbank = temp;
    }
    else
    {
        while (success == 0)
        {
            if (tempNext != NULL && ((*temp).accountno > (*tempNext).accountno))
            {
                tempPrev = tempNext;
                tempNext = (*tempNext).next;
                (*temp).next = tempNext; 
                accnoPosition++;
            }
            else
            {
                if (tempPrev != NULL)
                {
                    (*tempPrev).next = temp;
                    (*temp).next = tempNext;
                }
                success = 1;
            }
        }
        if (accnoPosition == 0)
        {
            *pbank = temp;
        }
    }    

    printf("\n\tSuccess Addition: Record with account number %d successfully added.\n", uaccountno);

}

/**************************************************************************************************
//
//  Function name: printRecord
//
//  DESCRIPTION: Prints record with desired account number.
//
//  Parameters: bank (struct record *) : record object
//              accountno (int) : account number of record to be printed
//
//  Return values: numRec (int) : number of records with desired account number found and printed.
//
***************************************************************************************************/

int printRecord(struct record * bank, int uaccountno)
{
    struct record * temp = bank;
    int numRec = 0;
    
    if (debugmode == 1)
    {
        printf("\n*************************DEBUG*************************\nFunction name: printRecord\nParameters:\n");
        printf("\tstruct record * bank: %p\n", (void *) bank);
        printf("\tint uaccountno: %d\n", uaccountno);
        printf("*******************************************************\n");
    }

    while (temp != NULL)
    {
        if ((*temp).accountno == uaccountno)
        {
            numRec++;
            printf("\n\tAccount number: %d\n\tName: %s\n\tAddress: %s\n", (*temp).accountno, (*temp).name, (*temp).address);
        }
        temp = (*temp).next;
    }

    if (numRec == 0)
    {
        printf("\n\tNot Found: Record with account number %d does not exist.\n", uaccountno);
    }

    return numRec;
}

/**************************************************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION: Prints all records in list.
//
//  Parameters: bank (struct record *) : record object
//
//  Return values: none
//
***************************************************************************************************/

void printAllRecords(struct record * bank)
{
    struct record * temp = bank;
    int notEmpty = 0;

    if (debugmode == 1)
    {
        printf("\n*************************DEBUG*************************\nFunction name: printAllRecords\nParameters:\n");
        printf("\tstruct record * bank: %p\n", (void *) bank);
        printf("*******************************************************\n");
    }

    while (temp != NULL)
    {
        notEmpty = 1;
        printf("\n\tAccount number: %d\n\tName: %s\n\tAddress: %s\n", (*temp).accountno, (*temp).name, (*temp).address);
        temp = (*temp).next;
    }

    if (notEmpty == 0)
    {
        printf("\n\tNo records exist.\n");
    }

}

/**************************************************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION: Deletes records from list.
//
//  Parameters: pbank (struct record**) : pointer to the address of a record object
//              accountno (int) : account number of the record to be deleted
//
//  Return values: 0 : executed and terminated successfully
//		   -1 : unsuccessful
//
***************************************************************************************************/

int deleteRecord(struct record ** pbank, int uaccountno)
{
    struct record * temp = *pbank, * tempNext, * tempPrev = NULL;
    int success = 0, found = 0;

    if (debugmode == 1)
    {
        printf("\n*************************DEBUG*************************\nFunction name: deleteRecord\nParameters:\n");
        printf("\tstruct record ** pbank: %p\n", (void *) pbank);
        printf("\tint uaccountno: %d\n", uaccountno);
        printf("*******************************************************\n");
    }
        
    while (temp != NULL)
    {
        tempNext = (*temp).next;
        if (tempNext != NULL && ((*temp).accountno < uaccountno))
        {
            tempPrev = temp;
            temp = tempNext;
            tempNext = (*temp).next;
        }
        else if ((*temp).accountno == uaccountno)
        {
            found++;
            free(temp);
            temp = tempNext;
            if (tempPrev != NULL)
            {
                (*tempPrev).next = temp;
            }              
            if (temp == NULL)
            {
                tempNext = NULL;
            }
            else
            {
                tempNext = (*temp).next;
            }
        }
        else 
        {
            temp = NULL;
        }
    }

    if (found > 0)
    {
        success = 0;
        printf("\n\tSuccess Deletion: Record with account number %d successfully deleted.\n", uaccountno);
    }
    else 
    {
        success = -1;
        printf("\n\tFailed Deletion: Record with account number %d was not deleted because it doesn't exist.\n", uaccountno);
    }

    return success;
}

