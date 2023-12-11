/*Exercise:
Write a program to check a C program for rudimentary syntax errors like unbalanced parenthleses, 
brackets and braces. Don't forget about quotes, both single and double, escape sequances and comments.

This code could be simpler. But in the future I want to conduct a more detailed analysis of errors in the code. I'll come back later..
*/
#include <stdio.h>

#define	INLNCMNT	2
#define INCMNT		1
#define	OUTCMNT		0

#define INDBQOUTE	2
#define	INQUOTE		1
#define	OUTQOUTE	0

#define	MAXCOUNT	1000

int getSymbolsSeq();
int checkCommentPos(int comment_pos, int prev_symb, int cur_symb);
int checkQuotePos(int qoute_pos, int prev_symb, int cur_symb);
int checkUnmatch();

int check_symbols[2][MAXCOUNT];
int count_prnth, count_brckt, count_brcs;

int main()
{
		int count, c, i, j;		
		char symb;
		
		for (i = 0; i < 2; ++i)
			for (j = 0; j < MAXCOUNT; ++j)
				check_symbols[i][j] = 0;
		
		getSymbolsSeq();
		checkUnmatch();
		
		if (count_prnth != 0)
			printf("Unmatched Parenthesis\n");
		if (count_brckt != 0)
			printf("Unmatched Brackets\n");
		if (count_brcs != 0)
			printf("Unmatched Braces\n");	
		
		if (count_prnth == 0 && count_brckt == 0 && count_brcs == 0)
			printf("No rudimentary syntax errors");
		
	return 0;
}

int getSymbolsSeq() 
{
	
	int c;
	int count, i;
	int comment_pos;
	int quote_pos;
	int prev_symb, cur_symb;
	
	comment_pos = OUTCMNT;
	quote_pos = OUTQOUTE;
	
	prev_symb = 0;
	count = i = 0;
	while ((c = getchar()) != EOF) {
		++count;
		
		cur_symb = c;
		comment_pos = checkCommentPos(comment_pos, prev_symb, cur_symb);
		
		if (comment_pos == OUTCMNT)
			quote_pos = checkQuotePos(quote_pos, prev_symb, cur_symb);
		
		if (comment_pos == OUTCMNT && quote_pos == OUTQOUTE)			
			if (c == '(' || c == ')' || 
				c == '[' || c == ']' || 
				c == '{' || c == '}') {
					check_symbols[0][i] = c;
					check_symbols[1][i] = count;
					++i;
			}
		
		if (c == '\n')
			++count;
		
		//check for back slash in quote
		if (prev_symb == '\\' && cur_symb == '\\')
			prev_symb = 0;
		else 
			prev_symb = c;
		
	}
	
	return 0;
}

int checkCommentPos(int comment_pos, int prev_symb, int cur_symb)
{
	if (comment_pos == OUTCMNT) {
		
		if (prev_symb == '/' && cur_symb == '*')
			comment_pos = INCMNT;
		else if (prev_symb == '/' && cur_symb == '/')
			comment_pos = INLNCMNT;
	}
	else if (comment_pos == INLNCMNT) {

		if (cur_symb == '\n')
			comment_pos = OUTCMNT;
	}
	else if (comment_pos == INCMNT) {
	
		if (prev_symb == '*' && cur_symb == '/')
			comment_pos = OUTCMNT;
	}
	
	return comment_pos;
}

int checkQuotePos(int qoute_pos, int prev_symb, int cur_symb)
{
	if (qoute_pos == OUTQOUTE) {
		
		if (cur_symb == '\"')
			qoute_pos = INDBQOUTE;
		else if (cur_symb == '\'') 
			qoute_pos = INQUOTE;
		
	} else if (qoute_pos == INDBQOUTE) {
		
		if (prev_symb != '\\' && cur_symb == '\"') 
			qoute_pos = OUTQOUTE;
		
	} else if (qoute_pos == INQUOTE) {
		
		if (prev_symb != '\\' && cur_symb == '\'') 
			qoute_pos = OUTQOUTE;
	}
	
	return qoute_pos;
}

int checkUnmatch()
{
	extern int count_prnth, count_brckt, count_brcs;
	int j, symb;
	
	j = 0;
	count_prnth = count_brckt = count_brcs = 0;		
	while (check_symbols[0][j] != 0) { 
		symb = check_symbols[0][j];
		
		if (symb == '(')
			++count_prnth;
		
		if (symb == '[')
			++count_brckt;
		
		if (symb == '{')
			++count_brcs;
		
		if (symb == ')')
			--count_prnth;
		
		if (symb == ']')
			--count_brckt;
		
		if (symb == '}')
			--count_brcs;
		
		++j;
	}	
	
	return 0;
}