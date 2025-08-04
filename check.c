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

CLASS DESCRIPTION:      This is the check class. This class checks inputted strings to see if they are balanced, using the paired symbols as a reference. 

*/
#define BUFSIZE 1000
#include<string.h>
static char buf[BUFSIZE];//buffer for opening symbols

static int bufp;//next free position in buf

void push(char c){
	buf[bufp] = c;
	bufp++;
}
char pop(void){
	if(is_empty())
		return '\0';
	bufp--;
	return buf[bufp];
}
char peek (void){
	if(is_empty())
		return '\0';
	return buf[bufp - 1];
}
int is_empty(){
	return !bufp;//bufp == 0
}
int size(){
	return bufp;
}
int is_opening_symbol(char c){//linear search
	extern char opening_symbol[];
	int len = strlen(opening_symbol);
	for(int i = 0;i < len;i++)
		if(c == opening_symbol[i])
			return 1;
	return 0;
}
int is_closing_symbol(char c){//linear search
	extern char closing_symbol[];
	int len = strlen(closing_symbol);
	for(int i = 0;i < len;i++)
		if(c == closing_symbol[i])
			return 1;
	return 0;
}
int is_matched(char open, char close){
	int i, j;
	extern char opening_symbol[];
	extern char closing_symbol[];
	int len = strlen(closing_symbol);
	int len2 = strlen(opening_symbol);
	for(i = 0; i < len2; i++){
		if(open == opening_symbol[i])
			break;
	}
	for(j = 0; j < len; j++){
		if(close == closing_symbol[j])
			break;
	}
	if(i == j){
		return 1;
	}else{
		return 0;
	}
	/*
	if(open == is_opening_symbol && close == is_closing_symbol){
		return 1;
	}else{
		return 0;
	}*/
		
	
}
int check(char input[]){
	bufp = 0;//empty out the stack!
	int len = strlen(input);
	for(int i = 0; i < len;i++){
		if(is_opening_symbol(input[i]))
			push(input[i]);
		else if(is_closing_symbol(input[i])){
			//match operation: First pop c, then
			//find out whether c and input[i] match
			//if not matched, then return 0;//not balanced
			//else keep going
			char c = pop();
			if(!is_matched(c, input[i]))
				return 0;
		}else{
			continue;
		}
		/*switch(input[i]){
			case '(':case '[':
			push(input[i]);
			break;
			case ')':
			if(pop() != '(')
				return 0;//unbalanced
			break;
			case ']':
			if(pop() != '[')
				return 0;//unbalanced
			break;
			default:
			;
		}*/
	}
	return is_empty();
}