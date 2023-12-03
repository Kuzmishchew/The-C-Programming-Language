/*
Exercise:

Write a program "detab" that that replaces tabs in the input with the proper number of blanks
to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.

In solution blank replace on #, for good visualisation.
*/

#include <stdio.h>

#define TABLN	8

int main()
{
	int c, i;
	int count;
	int cspace;
	
	count = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			cspace = TABLN - (count % TABLN);
			for (i = 0; i < cspace; ++i) {
				putchar('#');
				++count;
			}
		} else {
			++count;
			if (c == '\n') {
				count = 0;
			}
			putchar(c);
		}
	}
	
	return 0;
}