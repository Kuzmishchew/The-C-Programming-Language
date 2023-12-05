/*
Exercise:

Write a program to remove all comments from a C program. 
Don't forget to handle quoted strings and character constants properly.
*/
#include <stdio.h>

#define	INQUOTES	1
#define INDQUOTES	2
#define	OUTQUOTES	0
#define	INCOMMENT	1
#define	OUTCOMMENT	0

int main()
{
		int cur_symb, prev_symb;
		int quote = OUTQUOTES;
		int comment_outer;//0 - dont print, !=0 - print
		int wait_nl;
		int pos = OUTCOMMENT;
		
		prev_symb = 0;
		comment_outer = 0;
		wait_nl = 0;
		
		while ((cur_symb = getchar()) != EOF ) {
			if (prev_symb == '/' && cur_symb == '*'  && pos == OUTCOMMENT && quote == OUTQUOTES) {
				pos = INCOMMENT;
				comment_outer = 0;
			}
			/*comment*/
			/*comment*///test
			if (prev_symb == '*' && cur_symb == '/'  && pos == INCOMMENT) {
				pos = OUTCOMMENT;
			} else if (pos == OUTCOMMENT) {
				
				if (prev_symb == '/' && cur_symb == '/' && quote == OUTQUOTES)
					wait_nl = 1;
				
				if (comment_outer != 0 && wait_nl != 1) {
						
					if (prev_symb == 34 && quote == OUTQUOTES) {
						quote = INDQUOTES;
					}
					else if (prev_symb == 39 && quote == OUTQUOTES)  {
						quote = INQUOTES;
					}
					else if (prev_symb == 34 && quote == INDQUOTES)  {
						quote = OUTQUOTES;
					}
					else if (prev_symb == 39 && quote == INQUOTES) {
						quote = OUTQUOTES;
					}
					
					putchar(prev_symb);
				}
				
				if (cur_symb == '\n')
					wait_nl = 0;
				
				comment_outer = 1;
			}/*comment*/
			/*comment*/
			prev_symb = cur_symb;/*comment*/			
		}
		/*comment*/
		
		printf("%s", "\n\nwooooooooow it's no comment like // or /*");
}