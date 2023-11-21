#include <stdio.h>

#define IN	1
#define OUT	0
/*horizontal oriented histogram for words length counting*/

int main() {
	int c, i, j, state, clength;
	int nlength[21];
	int over21; //count words with length over 21
	
	state = IN;
	clength = 0;
	over21 = 0;
	
	for (i = 0; i < 21; i++)
		nlength[i] = 0;
	
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\n' && c != '\t') {
			state = IN;
			++clength;
		} else if (state == IN) {
			state = OUT;
			if (clength < 21)
				++nlength[clength];
			else
				++over21;
			clength = 0;
		}
	}
	
	for (i = 1; i < 21; ++i) {
		if (nlength[i] != 0) {	
			printf("%3d-length: ", i);
			for (j = 0; j < nlength[i]; ++j)
				printf("0");
			printf("\n");
		}
	}
	printf(">21-length: %d", over21);
}