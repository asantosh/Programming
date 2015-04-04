#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int ps = 5;
    int i = 0;
    int *lps = (int*)malloc(sizeof(int) * ps);

    lps[ps] = 0;

    for (i = 0; i < ps; i++) {
	lps[i] = i+1;
	printf("%d \t %d \n", i, *lps++);
    }

    return 0;
}
