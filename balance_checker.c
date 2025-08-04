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

CLASS DESCRIPTION:      This is the balance checker. This serves as the main class and handles the input/output from the user

*/
#include <stdio.h>
#include <string.h>
#include "balance.h"
char getword(char word[], int limit){
	//inputs a single word from stdin (keyboard)
	char c;
	int i = 0;
	while(i < limit){
		c = getchar();
		if(c == EOF || c == ' ' || c == '\n' || c == '\t')
			break;
		word[i++] = c;
	}
	word[i] = '\0';//end of string
	return c;//last character
}
char get_line(char line[], int limit){
	char c;
	int i = 0;
	while(i < limit){
		c = getchar();
		if(c == EOF || c == '\n')
			break;
		line[i++] = c;
	}
	line[i] = '\0';//end of string
	return c;//last character
}
void main(void){
	char word[MAX_LEN];
	char line[MAX_LEN];
	strcpy(opening_symbol, "(");
	strcpy(closing_symbol, ")");
	while(getword(word, MAX_LEN) != EOF){
		if(strcmp(word, "quit") == 0)//if it is quit
			return;
		if(strcmp(word, "check") == 0){//checking
			get_line(line, MAX_LEN);
			printf("%sbalanced.\n",
				check(line)? "" : "not ");
		}else if(!strcmp(word, "pair")){
			//take care of pair
			get_line(line, MAX_LEN);
			pair(line);
		}else{
			printf("Error: undefined command %s. Use check, pair, or quit only!\n", word);
			return;
		}
	}
}