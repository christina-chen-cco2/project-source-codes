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
//    FILE: record.h
//
//    Description: Header file record structure definition.
//
*************************************************************************************/

struct record
{
    int               accountno;
    char              name[25];
    char              address[80];
    struct record*    next;
};
