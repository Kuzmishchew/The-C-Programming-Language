/*Exercise:

Write a loop equivalent to the for loop above without using &&.

for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;
*/
#include <stdio.h>

int main()
{
	int c, i;
	int lim = 100;
	char s[lim];
	
	for (i=0; i<lim-1; ++i) {
		if ((c = getchar()) == '\n' || c == EOF) {
			lim = 100;
		} else {	
			s[i] = c;
		}	
	}
		
	
	printf("%s", s);
 
	return 0;
}