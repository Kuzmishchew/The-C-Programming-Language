/*
Exercise:

Write a function reverse(s) that reverses the character string s. 
Use it to write a program that reverses its input a line at a time.
*/

#include <stdio.h>

#define MAXLINE	1000

int getLine(char line[]);//assign line from prompt in arg and return line length. If EOF return -1
int reverse(char line[], char reverseLine[], int length);

int main() 
{
	int		i;
	int		lineLength;
	char	line[MAXLINE];
	char	reverseLine[MAXLINE];
	
	while ((lineLength = getLine(line)) != -1) 
		if (lineLength != 0) {
			reverse(line, reverseLine, lineLength - 3);//lineLength - 3 because two last char its \n and \0
			printf("%s", reverseLine);	
		} 
	
	return 0;
}

int getLine(char line[]) 
{
	int c, i;
	
	for (i = 0; i < MAXLINE; ++i)
		line[i] = '\0';
	
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	
	if (c == '\n') {
		++i;
		line[i] = c;
		++i;
		line[i] = '\0';
	}
		
	if (c == EOF)
		i = -1;
	
	return i;
}

int reverse(char line[], char reverseLine[], int length)
{
	int i;
	
	for (i = 0; i < MAXLINE; ++i)
		reverseLine[i] = '\0';
	
	for (i = length; i >= 0; --i)
		reverseLine[length - i] = line[i];
	
	reverseLine[length + 1] = '\n';
	reverseLine[length + 2] = '\0';
	
	return 0;
}