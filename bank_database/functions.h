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
//    FILE: functions.h
//
//    Description: Header file for menufunctions.c, userMenu.c, and iofunctions.c.
//
*************************************************************************************/

#include <stdlib.h>
#include "record.h"
#include <stdio.h>
#include <string.h>

void addRecord(struct record **, int, char[ ], char[ ]);
int printRecord(struct record *, int);
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int writefile(struct record *, char[ ]);
int readfile(struct record **, char[ ]);

