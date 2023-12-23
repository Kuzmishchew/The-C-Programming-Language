/*Exercise:

Write the function any(s1, s2) wich returns the first location in the string s1 
where any character from the string s2 occurs< or -1 if s1 contains no characters from s2.
*/
#include <stdio.h>

#define	MAXLENGTH	1000

void	reset(char s[]);
int		any(char s1[], char s2[]);
int		check_matches(char s2[], char symb);

int main()
{
	int result;
	int c, i, j;
	char s1[MAXLENGTH], s2[MAXLENGTH];
	
	i = j = 0;
	while ((c = getchar()) != EOF && j != 2) {
		if (c == '\n') {
			
			if (j == 0)
				s1[i] = '\0';
			else 
				s2[i] = '\0';
			
			i = 0;
			++j;
		} else {
			if (j == 0)
				s1[i] = c;
			else 
				s2[i] = c;
			++i;
		}
	}		
	
	result = any(s1, s2);
	
	if (result != -1)
		printf("Index first match:\t%i", result);
	else
		printf("NO_MATCHES");
	
	return 0;
}

int any(char s1[], char s2[])
{
	int i;
	
	i = 0;
	while (s1[i] != '\0') {
		if  (check_matches(s2, s1[i]) != 1)
			++i;
		else 
			return i;
	}
	
	return -1;
}

int check_matches(char s2[], char symb)
{
	int result, i;
	
	result = 0;
	
	for (i = 0; s2[i] != '\0'; i++)
		if (s2[i] == symb)
			result = 1;
		
	return result;
}