/*
Exercise:

Revise the main routine of the longest-line program so it will correctly print the length
of arbitrarily long input lines, and as much as possible of the text.
*/

#include <stdio.h>

int getlineLength();

int main() 
{
	int len;
	int lineCount;
	int textLength;
	
	lineCount = 0;
	textLength = 0;
	while ((len = getlineLength()) > 0) {
			++lineCount;
			textLength = textLength + len;
			printf("%6d line : %6d length\n", lineCount, len);
		}
		
	printf("\nText lenght : %6d", textLength);
	
	return 0;
}

int getlineLength()
{
	int c, i;
	
	for (i = 0; (c = getchar()) != EOF && c != '\n'; )
		++i;
	
	if (c == '\n')		
		++i;

	return i;
}