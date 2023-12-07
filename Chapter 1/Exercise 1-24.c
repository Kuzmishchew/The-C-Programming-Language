/*
Exercise:

Write a program to check a C program for rudimentary syntax errors like unbalanced parenthleses, 
brackets and braces. Don't forget about quotes, both single and double, escape sequances and comments.
*/
#include <stdio.h>

#define	INCMNT		1
#define	OUTCMNT		0
#define	INPRNTL		1
#define	OUTPRNTL	0
#define	INQUOT		1
#define	OUTQOUT		0

#define	MAXCOUNT	1000

int getSymbolsSeq();
int check_symbols[2][MAXCOUNT];

int main()
{
		int count, c, i, j;
		
		char symb;
		
		for (i = 0; i < 2; ++i)
			for (j = 0; j < MAXCOUNT; ++j)
				check_symbols[i][j] = 0;
		
		getSymbolsSeq();
		
		j = 0;
		for (i = 0; i < 2; ++i) {			
			while (check_symbols[i][j] != 0) {
					symb = check_symbols[i][j];
					if (i == 0)
						putchar(symb);
					else
						printf("%d", check_symbols[i][j]);
					printf(" ");
					++j;
			}				
			printf("\n");
			j = 0;
		}
				
			
	
	return 0;
}

int getSymbolsSeq() {
	
	int count, i, c;
	
	count = i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '(' || c == ')' || 
			c == '[' || c == ']' || 
			c == '{' || c == '}' ||
			c == '\"' || c == '\'') {
				check_symbols[0][i] = c;
				check_symbols[1][i] = count;
				++i;
		}
		++count;
	}
	
	return 0;
}