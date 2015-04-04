#include <stdio.h>

int main()
{
    int nl =0, nw =0;
    char c;

    while((c = getchar()) != EOF) {
	if(c == '\n')
	    ++nl;
	if(c == '\n' || c == ' ')
	    ++nw;
    }

    printf("%d %d \n",nl, nw);

    return 0;
}





