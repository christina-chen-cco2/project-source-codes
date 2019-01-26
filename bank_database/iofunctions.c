/****************************************************************************************************************************************
//
//    NAME: Christina Chen
//
//    HOMEWORK: Project 1
//
//    CLASS: ICS 212
//
//    DATE: October 27, 2018
//
//    FILE: iofunctions.c
//
//    Description: Functions for reading records from a file and storing them in a list and writing records from a list to a text file.
//
*****************************************************************************************************************************************/

#include "functions.h"

extern int debugmode;

/*****************************************************************************************************************
//
// Function name: writefile
//
// DESCRIPTION: writes the values of the fields of the records stored in an array to the passed file
//
// Parameters: bank (struct record *) : list to write records from text file to
//	       filename (char[ ]) : name of text file to write records from list to 
//
// Return values: numWrote (int) : number of records written
//
******************************************************************************************************************/

int writefile(struct record * bank, char filename[ ])
{
    FILE * content = fopen(filename, "w");
    struct record * temp = bank;
    int numWrote = 0;

    if (debugmode == 1)
    {
        printf("\n\n\n*************************DEBUG*************************\nFunction name: writefile\nParameters:\n");
        printf("\tstruct record * bank: %p\n", (void *) bank);
        printf("\tchar filename[ ]: %p\n", (void *) filename);
        printf("*******************************************************\n\n\n\n");
    }

    while (temp != NULL)
    {
        fprintf(content, "%d\n", (*temp).accountno);
        fprintf(content, "%s\n", (*temp).name);
        fprintf(content, "%s\n\n", (*temp).address);
        numWrote++;
        temp = (*temp).next;
    }

    fclose(content);
    return numWrote;

}

/***************************************************************************************************************
//
// Function name: readfile
//
// DESCRIPTION: reads a passed file and stores the data in the field values of the records stored in an array
//
// Parameters: pbank (struct record **) : holds location of list to read from
//              filename (char[ ]) : the file to read the data from that gets stored
//
// Return values: number of records whose fields were updated;
//              also indicates if function successfully executed and terminated
//
****************************************************************************************************************/

int readfile(struct record ** pbank, char filename[ ])
{
    FILE * content = fopen(filename, "r");
    int numRead = 0, accountno, j;
    char name[25], address[80], addressChar, nameChar;

    if (debugmode == 1)
    {
        printf("\n*************************DEBUG*************************\nFunction name: readfile\nParameters:\n");
        printf("\tstruct record ** pbank: %p\n", (void *) pbank);
        printf("\tchar filename[ ]: %p\n", filename);
        printf("*******************************************************\n");
    }

    if (content != NULL)
    {
        while(feof(content) == 0)
        {
            fscanf(content, "%d", &accountno);
            if (feof(content) == 0)
            {
                fgetc(content);
                fgets(name, 25, content);
                j = 0;
                nameChar = name[j];
                while (nameChar != '\n')
                {
                    j++;
                    nameChar = name[j];
                }
                name[j] = name[j + 1];
                j = 0;
                addressChar = fgetc(content);
                while (addressChar != '\n')
                {
                    address[j] = addressChar;
                    j++;
                    addressChar = fgetc(content);
                }
                address[j + 1] = '\0';
                fgetc(content);
                numRead++;
                addRecord(pbank, accountno, name, address);
            }
        }
        fclose(content);
    }

    return numRead;
}
