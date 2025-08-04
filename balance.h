/*  
PROGRAMMER:             Anthony Rufin
PANTHER ID:				6227314

CLASS:    				COP4338 
SECTION:                U02
SEMESTER:               Spring 2023
CLASSTIME:              M/W 3:30-4:45 pm

PROJECT:                Programming Assignment 1
DUE:                    January 30, 2023

CERTIFICATION:          I understand FIU’s academic policies, and I certify that this work is my 
                        own and that none of it is the work of any other person.

CLASS DESCRIPTION:      This is the balance.h file. This holds certail global variables and arrays meant to be used in the various files.

*/
#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000
int check(char input[]);
void pair(char list[]);
extern char opening_symbol[];
extern char closing_symbol[];
