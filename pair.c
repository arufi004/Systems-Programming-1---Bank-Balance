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

CLASS DESCRIPTION:      This is the pair class. This takes the symbols set a pairs, such as (,) or [,] and places them in an array. 

*/
#include <stdio.h>
#include <string.h>

#define MAXSIZE 51


char opening_symbol[51];
char closing_symbol[51];
#include <string.h>
void pair(char list[]){//e.g. list = "(,) [,] {,} a,b"
	int i;//counter for opening and closing symbols...
	int j;//counter for the chars stored in array list
	int len = strlen(list);
	for(i = 0, j = 0;j < len;i++,j += 4){
		opening_symbol[i] = list[j];
		closing_symbol[i] = list[j + 2];
	}
	opening_symbol[i] = closing_symbol[i] = '\0';
}
