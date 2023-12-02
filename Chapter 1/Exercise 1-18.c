/*
Exercise:

Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.
*/

#include <stdio.h>

#define MAXLINE	1000

int getLine(char line[]);//assign line from prompt in arg and return line length. If EOF return -1
int removeBlanks(char line[], int length);

int main() 
{
	int		i;
	int		lineLength;
	char	line[MAXLINE];
	
	while ((lineLength = getLine(line)) != -1) 
		if (lineLength != 0 && removeBlanks(line, lineLength) != 0) {
			printf("%s", line);				
		} else if (removeBlanks(line, lineLength) != 0) {
			printf("\n");
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

int removeBlanks(char line[], int length)
{
	int i;
	int fLength;
	int result;
	
	fLength = length;
	i = fLength - 3;
	while (line[i] == '\t' || line[i] == ' ') {
		line[i] = '\n';
		line[i + 1] = '\0';
		
		fLength = fLength - 2;
		i = fLength - 3;
	}
	
	if (fLength == 2)
		result = 0;
	else 
		result = 1;
	
	return result;
}