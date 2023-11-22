/*
Exercise:

Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a certical orientation is more challenging.

Solution:
It is solution for vertical histogram.
Input it is lines in cmd.
Output look like:

 19|
 18|
 17|
 16|
 15|
 14|
 13|           X
 12|           X
 11|  X        X
 10|  X  X     X
  9|  X  X     X
  8|  X  X     X
  7|  X  X     X
  6|  X  X     X
  5|  X  X  X  X
  4|  X  X  X  X                 X
  3|  X  X  X  X                 X
  2|  X  X  X  X                 X
  1|  X  X  X  X        X  X     X
===============================================================
      1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19

Where bottom numbers it is length, left number it is count.
"X" it is a part of histogram for each count.
*/
#include <stdio.h>

#define IN			1
#define OUT			0
#define MAXLENGTH	20
#define MAXCOUNT	20

int main() {
	int c, i, j, state, clength;
	int nlength[MAXLENGTH];
	int result[MAXCOUNT][MAXLENGTH];
	
	state = IN;
	clength = 0;
	
	//fill working array
	for (i = 0; i < MAXLENGTH; i++)
		nlength[i] = 0;
	
	for (i = 0; i < MAXCOUNT; i++)
		
		for (j = 0; j < MAXLENGTH; j++)
			if (i == 0)
				result[i][j] = j;
			else 
				result[i][j] = 0;
	
	//words length counting
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
	
	//fill array for each length
	for (i = 1; i < MAXLENGTH; ++i) {
		result[0][i] = i;
		if (nlength[i] != 0) {			
			for (j = 1; j <= nlength[i]; ++j) {
				result[j][i] = 1;
			}
		}
	}	
	
	//print rows header (counts) and build histogram, where "X" its one word with current length		
	for (i = MAXCOUNT - 1; i >= 1; --i) {
		for (j = 0; j < MAXLENGTH; j++)
			if (j == 0)
				printf("%3d|", i);//left border and rows header
			else if (result[i][j] == 1)
				printf("%3s", "X");
			else 
				printf("%3s", " ");
		printf("\n");
	}
	
	//print bottom underline and column header (length words)
	for (i = 0; i <= MAXCOUNT; ++i)
		printf("%3s", "===");//underline
	printf("\n");
	for (i = 0; i < MAXCOUNT; ++i)
		if (i == 0)
				printf("%4s", " ");//left corner
		else
			printf("%3d", i);//word length
	printf("\n");
}
