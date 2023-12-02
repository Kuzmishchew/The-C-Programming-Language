/*
Exercise:

Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLENGTH	1000

void printLine(char line[]);

int main() 
{
	int c, i, clength;
	char line[MAXLENGTH];
	
	for (i = 0; i < MAXLENGTH; ++i)
		line[i] = 0;	
	
	i = 0;
	while((c = getchar())!= EOF) 
		if (c != '\n') {
			line[i] = c;
			++i;
		} else {
			line[i] = '\0';
			if (i > 79) {
				printLine(line);
			}
			for (i = 0; i < MAXLENGTH; ++i)
					line[i] = 0;
			i = 0;
		} 	
}

void printLine(char line[])
{
	int i;
	
	i = 0;
	while (line[i] != '\0') {
		putchar(line[i]);
		++i;
	}
	
	printf("\n");
}