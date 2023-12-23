/*Exercise:

Write an alternate version of squeeze(s1, s2) wich deletes each character in s1 
wich matches any character in the string s2.

squeeze(s, c) / delete all c from s /
char s[];
int c;
{
  int i,  j;

  for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
  s[j] = '\0';
}
*/
#include <stdio.h>

#define	MAXLENGTH	1000

void	reset(char s[]);
void	squeeze(char s1[], char s2[]);
int		check_matches(char s2[], char symb);

int main()
{
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
	
	squeeze(s1, s2);
	
	if (s1[0] != '\0')
		printf("Result:\t%s", s1);
	else
		printf("Result:\tEMPTY_STRING");
	
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j;
	
	for (i = j = 0; s1[i] != '\0'; i++)
        if (check_matches(s2, s1[i]) == 1)
            s1[j++] = s1[i];
	s1[j] = '\0';
}

int check_matches(char s2[], char symb)
{
	int result, i;
	
	result = 1;
	
	for (i = 0; s2[i] != '\0'; i++)
		if (s2[i] == symb)
			result = 0;
		
	return result;
}