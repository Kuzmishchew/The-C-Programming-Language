/*
Exercise:

Write a program to print a histogram of the frequencies of different characters in its input.

Solution:
Input it is lines in cmd.
Output look like:
    h : =========================
    i : ==================================
    j : ===
    k : ====
    l : ================
    m : =======================
    n : ==========================================
    o : =================================================
    p : ==========
    r : ==================================================
    s : ========================================
    t : ==================================================
    u : =====================
    v : ======
    w : =======
    x : =
    y : ==========
	
Count for each charcter from input.
*/
#include <stdio.h>

int main() {
	int c, i, j;
	int nchar[218];
	
	for (i = 0; i <= 218; ++i)
			nchar[i] = 0;
	
	while ((c = getchar()) != EOF)
		++nchar[c];
	
	for (i = 0; i <= 218; ++i) 
		if (nchar[i] != 0) {
			if (i == ' ')
				printf("space");
			else if (i == '\n')
				printf(" newL");
			else {
				printf("    ");
				putchar(i);		
			}
			printf(" : ");
			for (j = 1; j <= nchar[i]; ++j)
				printf("=");
			printf("\n");
		}
}
