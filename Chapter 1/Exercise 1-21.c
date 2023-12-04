/*
Exercise:

Write a program entab that replaces  strings of blanks by the 
minimum number of tabs and blanks to achieve the same spacing. 
Use the same tab stops as for detab.
*/

#include <stdio.h>

#define TABLN		8
#define	INBLANKS	1
#define	OUTBLANKS	0

void	printSpace(int count);

int main()
{
	int c, i;
	int pos;
	int count;

	pos		= 	OUTBLANKS;
	count	=	0;

	while ((c = getchar()) != EOF)
		if (c == ' ') {
			pos = INBLANKS;
			++count;
		} else if (pos == INBLANKS) {
			pos = OUTBLANKS;

			printSpace(count);
			count = 0;

			putchar(c);
		} else {
			putchar(c);
		}
	
	return 0;
}

void printSpace(int count)
{	
	int i;
	int c_blank;
	int c_tab;
	
	c_blank = count % TABLN;
	c_tab = (count - c_blank) / TABLN;

	for (i = c_tab; i > 0; --i)
		printf("%s", "########");

	for (i = c_blank; i > 0; --i)
		printf("%s", "_");
}
