/*
Exercise:

Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
*/

#include <stdio.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

int getCelsius(int fahr);

int main() 
{
	int fahr, i;
	
	for (i = 0; i <= UPPER; i = i + STEP) 
		printf("%3d %6.1d\n", i, getCelsius(i));
}

int getCelsius(int fahr)
{
	return (5.0/9.0) * (fahr - 32.0);
}