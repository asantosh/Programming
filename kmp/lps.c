#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *pat = "AAACAAAAAC";
    int len = strlen(pat);
    int i = 1;
    int *lps = (int*)malloc(sizeof(int) * len);
    int ps = 0;

    lps[ps] = 0;

    while (i < len) {

	if (pat[i] == pat[ps]) {
	    ps++;
	    lps[i] = ps;
	    i++;
	    printf("i = %d \t ps = %d \t lps[i] = %d\n", i, ps, *lps++);
	    printf("inside if\t");
	}

	else {
	    lps[i] = 0;
	    i++;
	    printf("i = %d \t ps = %d \t lps[i] = %d\n", i, ps, *lps++);
	    printf("inside else\t");
	}

    }

    for (i = 0; i < len; i++)
	printf("%d \t %d \n", i, *lps++);

    return 0;
}
