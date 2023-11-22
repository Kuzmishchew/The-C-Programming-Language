/*
Exercise:

Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a certical orientation is more challenging.

Solution:

It is solution for horisontal histogram.
Input it is lines in cmd.
Output look like:

	1: 0000
	2: 00000
	3: 000000000000000
	4: 0
	6: 00
	7: 0
   12: 0

Where number before ":" it is length or words, and "0" its bar of histogram fo each count of length. 
*/
#include <stdio.h>

#define IN			1
#define OUT			0
#define MAXLENGTH	100

int main() {
	int c, i, j, state, clength;
	int nlength[MAXLENGTH];
	
	state = IN;
	clength = 0;
	
	for (i = 0; i < MAXLENGTH; i++)
		nlength[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') {
			state = IN;
			++clength;
		} else if (state == IN) {
			state = OUT;
			if (clength < MAXLENGTH)
				++nlength[clength];
			clength = 0;
		}
	}
	
	for (i = 1; i < MAXLENGTH; ++i) {
		if (nlength[i] != 0) {	
			printf("%3d: ", i);
			for (j = 0; j < nlength[i]; ++j)
				printf("0");
			printf("\n");
		}
	}
}