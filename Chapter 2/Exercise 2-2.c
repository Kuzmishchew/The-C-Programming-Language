/*Exercise:

Write the function htoi(s), which converts a s of hexadecimal digits into its equivalent integer value. 
The allowable digits are 0 through 9, a through f, and A throught F.

*/
#include <stdio.h>

#define	MAXLENGTH	1000

void	reset(char s[]);
int		htoi(char s[]);

int main()
{
	int c, i;
	int h;
	char s[MAXLENGTH];
	
	printf("%s\t%s\n", "Decimal", "Hexadecimal");
	
	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			h = htoi(s);
			printf("%7i\t%11x\n", h, h);
			i = 0;
			reset(s);
		} else {
			s[i] = c;
			++i;
		}
	}		
 
	return 0;
}

void reset(char s[])
{
	int i;
	
	for (i = 0; i < MAXLENGTH; ++i)
		s[i] = -1;
}

int htoi(char s[])
{
	int i, h;
	
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		i = 2;
	else 
		i = 0;
	
	h = 0;
	for (i; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i) {
		h = h*16;
		
		if (s[i] >= '0' && s[i] <= '9') {
			h = h + s[i] - '0';
		} else if (s[i] >= 'a' && s[i] <= 'f') {
			h = h + (s[i] - 'a' + 10);
		} else if (s[i] >= 'A' && s[i] <= 'F') {
			h = h + (s[i] - 'A' + 10);
		}
	}
	
	return h;
}